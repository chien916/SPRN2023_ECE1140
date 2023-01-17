#ifndef FIREBASE_HPP
#define FIREBASE_HPP
#include <QtCore>
#include <QtNetwork>
/**
 * @brief The Firebase class
 *
 * This class provides an unified communication protocols between different modules
 *
 *
 * Steps for configuration:
 * 1.Add network module into make file
 * 2.Install openssl and include bin folder in env path.
 */
class Firebase: public QObject {
	Q_OBJECT
  public:
	Firebase(QObject *parent = nullptr);
	QJsonDocument getJsonDocFromCsvFile(QFile& file);
  private:
	//Rest API constants
	QUrl firebaseRootUrl = QUrl("https://sprn2023-ece1140-default-rtdb.firebaseio.com/");
	QPointer <QNetworkAccessManager> networkAccessManager;
	QPointer <QNetworkReply> networkReply;
  private slots:
	void networkReplyReadyRead();

};

inline Firebase::Firebase(QObject *parent): QObject(parent) {
	networkAccessManager = new QNetworkAccessManager(this);
	QNetworkRequest readRequest = QNetworkRequest(firebaseRootUrl);
//	networkReply = networkAccessManager->get(readRequest);
//	connect(networkReply, &QNetworkReply::readyRead, this, &Firebase::networkReplyReadyRead);
}

inline QJsonDocument Firebase::getJsonDocFromCsvFile(QFile &file) {
	//convert csv file into 2d string list
	if(!file.open(QIODevice::ReadOnly)) {
		qFatal(file.errorString().toUtf8());
	}
	QList<QList<QString>> structure;
	while(!file.atEnd()) {
		QList<QString> currLine;
		QByteArray line = file.readLine();
		qDebug() << line;
		QList<QByteArray> splitted =  line.split(',');
		foreach (const QByteArray currString, splitted) {
			currLine.push_back(QString::fromUtf8(currString).trimmed());
		}
		structure.push_back(currLine);
	}
	//iterate through the string list and convert the strucutre into json document
	foreach (const QList<QString>& currStringList, structure) {
		if(currStringList.length() != 10) {
			qFatal("csv file given is not valid route information");
		}
		if(currStringList.at(0) == "Line") continue;
		QString line = currStringList.at(0);
		QString section = currStringList.at(1);
		QString block = currStringList.at(2);
		//
		QVariantMap constants;
		QVariantMap variables;
		QVariantMap infrastructures;

		constants["length"] = currStringList.at(3).toFloat();
		constants["grade"] = currStringList.at(4).toFloat();
		constants["speedLimit"] = currStringList.at(5).toFloat();
		//parse infrastrucuture
		QStringList infrastructureStringList = currStringList.at(6).split(';');
		for(int currInd = 0; currInd < infrastructureStringList.length(); ++currInd) {
			QString currString = infrastructureStringList.at(currInd).trimmed();
			if(currString.contains("station", Qt::CaseInsensitive)) {
				//handles instrastructure.station
				QString stationSides
					= "$" + QString((currStringList.at(7).indexOf("left") != -1) ? "L" : "")
					  + QString((currStringList.at(7).indexOf("right") != -1) ? "R" : "");
				if(currInd + 1 >= infrastructureStringList.length() - 1) {
					infrastructures["station"]
						= infrastructureStringList.at(currInd + 1).toLower().trimmed() + stationSides;
				} else {
					infrastructures["station"] = "unnamed station" + stationSides;
				}
			} else if(currString.contains("switch", Qt::CaseInsensitive)) {
				/**
				 * Examples of Switch Connection Representation String
				 *
				 * "A$13$15$15"
				 * active switch with available connections to 13 and 15
				 * currently connected to 15
				 *
				 * "P$34
				 * passive switch with available connections to 34
				 * check connectivity by querying its corresponding active switch
				 *
				 * "Y"
				 */
				//handles infrastructure.switch
				qsizetype leftPareInd = currString.indexOf('(');
				qsizetype rightPareInd = currString.indexOf(')');
				QStringList switchConnectionInfo
					= currString.mid(leftPareInd + 1, rightPareInd - leftPareInd - 1).split(';');
				//parse (l1-l2;r1-r2) into [l1,l2,r1,r2]
				QList<qint16> connectionBlockNumbers;
				foreach (const QString& currRawConnectionInfo, switchConnectionInfo) {
					foreach(const QString& currString, currRawConnectionInfo.split('-')) {
						if(currString.contains("yard", Qt::CaseInsensitive)) {
							connectionBlockNumbers.append(-1);
						} else {
							bool isConversionSuccessful;
							qint16 currNumber = currString.toInt(&isConversionSuccessful, 10);
							Q_ASSERT_X(isConversionSuccessful, "getJsonDocFromCsvFile", "convert to integer failed");
							connectionBlockNumbers.append(currNumber);
						}
					}
				}
				//decode [l1,l2,r1,r2] or [-1,l2] or [l1,-1]
				if(connectionBlockNumbers.length() == 4) {
					if(connectionBlockNumbers.at(2) == block) {
						//active connection
						variables["switch"] = "A$" + QString::number(connectionBlockNumbers.at(1))
											  + "$" + QString::number(connectionBlockNumbers.at(3))
											  + "$" + QString::number(connectionBlockNumbers.at(1));
					} else {
						//passive connection
						variables["switch"] = "P$" + QString::number(connectionBlockNumbers.at(1));
					}
				} else if(connectionBlockNumbers.length() == 2) {
					Q_ASSERT_X(connectionBlockNumbers.contains(-1), "", "cannot determine if a yard connection");
					variables["switch"] = "Y";
				} else qFatal("connectionBlockNumbers not 2 or 4");










			}
		}

	}






	return QJsonDocument();
}

inline void Firebase::networkReplyReadyRead() {
	qDebug() << networkReply->readAll();
}

#endif // FIREBASE_HPP
