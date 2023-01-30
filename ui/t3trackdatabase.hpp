#ifndef T3TRACKDATABASE_H
#define T3TRACKDATABASE_H

#include <QtCore>
//#include "t3trackmodel.hpp"

/**
 * @brief The T3TrackDatabase class
 * This class will store all relative information of rail track
 * block data. Both constants and variables are stored in the
 * form of json array.
 *
 * The constants are loaded from the modified CSV file provided
 * by Dr. Profeta. It includes the property of rail block such
 * as crossing, direction of block, grade, length, available
 * next and previous blocks, speed limit, station information,
 * underground information
 * --Keep in mind that the crossing, prev/next block, station
 * field only indicates IF THIS BLOCK IS A STATION/CROSSING..
 * and the real-time state of these infrastructures is stored
 * in the variable objects.
 * --Notify changes whenever new line is being added
 * (Every notify will make UI re-render line map, takes long time)
 *
 * The variables on the other hand includes the dynamic state
 * of insfrastructure, such as the crossing is up or down (given
 * that the current block IS a crossing), the current switch
 * position. It also stores non-infrastructure related information
 * such as train occupancy, beacon information (authority and
 * commanded speed). The PLC program is NOT stored here!!!
 * --Notify changes whenever train controller writes new value
 *
 * QML Exposed Variables:
 * Notify
 *
 */


class T3TrackDatabase: public QObject {
	Q_OBJECT
  private:
	//Context variables exposed to QML:
	Q_PROPERTY(QJsonArray lineConstantsObjects_QML MEMBER lineConstantsObjects NOTIFY onLineConstantsObjectsChanged)
	Q_PROPERTY(QJsonArray lineVariablesObjects_QML MEMBER lineVariablesObjects NOTIFY onLineVariablesObjectsChanged)
	QJsonArray lineConstantsObjects;//do not modify directly after initialization. use the put() slot instead!
	QJsonArray lineVariablesObjects;//do not modify directly after initialization. use the put() slot instead!
  Q_SIGNALS:
	void onLineConstantsObjectsChanged();
	void onLineVariablesObjectsChanged();
  public:
	T3TrackDatabase(QObject *parent = nullptr);
	enum TrackProperty {
		CommandedSpeed = 0 //real/float
		, Authority = 1 //bool
		, SwitchPostion = 2 //bool
		, Light = 3 //string
		, CrossingPosition = 4 //bool
		, TrainOnBlock = 5 //string
		, Failure = 6 //string
		, Heaters = 7 //string
		, PeopleOnStation = 8 //int
	};
	Q_ENUM(TrackProperty);
  private:
	const QHash<T3TrackDatabase::TrackProperty, QPair<QString, int>> trackPropertiesMetaDataMap
	= std::initializer_list<std::pair<T3TrackDatabase::TrackProperty, QPair<QString, int>>> {
		std::make_pair(T3TrackDatabase::TrackProperty::CommandedSpeed, QPair<QString, int>(QString("commandedSpeed"), qMetaTypeId<float>()))
		, std::make_pair(T3TrackDatabase::TrackProperty::Authority, QPair<QString, int>(QString("authority"), qMetaTypeId<bool>()))
		, std::make_pair(T3TrackDatabase::TrackProperty::SwitchPostion, QPair<QString, int>(QString("switchPosition"), qMetaTypeId<bool>()))
		, std::make_pair(T3TrackDatabase::TrackProperty::Light, QPair<QString, int>(QString("light"), qMetaTypeId<QString>()))
		, std::make_pair(T3TrackDatabase::TrackProperty::CrossingPosition, QPair<QString, int>(QString("crossingPosition"), qMetaTypeId<bool>()))
		, std::make_pair(T3TrackDatabase::TrackProperty::TrainOnBlock, QPair<QString, int>(QString("trainOnBlock"), qMetaTypeId<QString>()))
		, std::make_pair(T3TrackDatabase::TrackProperty::Failure, QPair<QString, int>(QString("failure"), qMetaTypeId<QString>()))
		, std::make_pair(T3TrackDatabase::TrackProperty::Heaters, QPair<QString, int>(QString("heaters"), qMetaTypeId<QString>()))
		, std::make_pair(T3TrackDatabase::TrackProperty::PeopleOnStation, QPair<QString, int>(QString("peopleOnStation"), qMetaTypeId<uint16_t>()))
	};
  public Q_SLOTS:
	void put(QString blockId, T3TrackDatabase::TrackProperty trackProperty, QVariant value);
	void get(const QString request, QVariant* respond);
	void import(const QString filePath);
};

/**
 * @brief T3TrackDatabase::put
 * @param request
 * Patch variables with certain values
 *
 */
inline void T3TrackDatabase::put(QString blockId, T3TrackDatabase::TrackProperty trackProperty, QVariant value) {
	QPair<QString, int> metaData = trackPropertiesMetaDataMap.value(trackProperty);
	if(!value.canConvert(metaData.second))
		qFatal("T3TrackDatabase::put() -> property value required and inputted format doesn't match");
	value.convert(metaData.second);
	bool fieldIsFound = false;
	for(qsizetype i = 0; i < lineVariablesObjects.size(); ++i) { //for every line
		QJsonObject currLineVariablesObject = lineVariablesObjects[i].toObject();
		if(currLineVariablesObject.find(blockId) != currLineVariablesObject.end()) {
			QJsonObject currBlockVariablesObject = currLineVariablesObject[blockId].toObject();
			currBlockVariablesObject[metaData.first] = value.toJsonValue();
			currLineVariablesObject[blockId] = currBlockVariablesObject;
			lineVariablesObjects[i] = currLineVariablesObject;
			fieldIsFound = true;
			break;
		}
	}
	if(!fieldIsFound)
		qFatal("T3TrackDatabase::put() -> cannot find the block id inputted");
	Q_EMIT onLineVariablesObjectsChanged();
}

inline void T3TrackDatabase::get(const QString request, QVariant *respond) {
	//TO-DO
}

inline void T3TrackDatabase::import(const QString filePath) {
	QString newFilePath = QString(filePath).replace("file:///", "");
	qsizetype requiredColumnCount = 0;
	QFile file(newFilePath);
	if(!newFilePath.contains(".csv")) {
		qFatal("T3TrackDatabase::import() -> CSV bad format: file received is not csv extensions");
	}
	if(!file.open(QIODevice::ReadOnly)) {
		qFatal(file.errorString().toUtf8());
	}
	QList<QList<QString>> titles;
	QJsonObject currLineConstantsObject;
	QJsonObject currLineVariablesObject;
	QPair<QString, QString> startingBlock{QString(), QString()};
	QPair<QString, QString> endingBlock{QString(), QString()};
	while(!file.atEnd()) {//each iteration is one block (one line in csv)

		QString currLineRaw = QString::fromUtf8(file.readLine()).trimmed();
		if(titles.empty()) {
			if(currLineRaw.contains
					("blockId_s,length_r,grade_r,speedLimit_r,elevation_r,prevBlock1_s,prevBlock2_s,nextBlock1_s,nextBlock2_s,underground_b,crossing_b,station_s,direction_s")) {
				QStringList titleAndTypes = currLineRaw.split(',');
				requiredColumnCount = titleAndTypes.count();
				foreach (const QString& currTitleAndTypes, titleAndTypes) {
					QStringList TitleAndTypesSplitted = currTitleAndTypes.split('_');
					if(TitleAndTypesSplitted.length() != 2)
						qFatal("T3TrackDatabase::import() -> CSV bad format: title name and type format wrong");
					titles.append(TitleAndTypesSplitted);
				}
			} else
				qFatal("T3TrackDatabase::import() -> CSV bad format: title doesn't match.");
			continue;
		}
		QStringList currLineSplitted = currLineRaw.split(',');
		if(currLineSplitted.count() != requiredColumnCount) {
			qFatal("T3TrackDatabase::import() -> CSV bad format: content column count mismatch.");
		}

		//intializing fields for constants for this block
		{
			QJsonObject currBlockConstantsObject;
			for(qsizetype i = 1; i < requiredColumnCount; ++i) {//block id is eliminated at each object
				QString currType = titles.at(i).at(1);
				QString currTitle = titles.at(i).at(0);
				QString currValueAsString = currLineSplitted.at(i);
				if(currType == "s") {
					if(currValueAsString.contains("START_T")) {
						startingBlock.first = currLineSplitted.at(0);
					} else if(currValueAsString.contains("START_B")) {
						startingBlock.second = currLineSplitted.at(0);
					} else if(currValueAsString.contains("END_T")) {
						endingBlock.first = currLineSplitted.at(0);
					} else if(currValueAsString.contains("END_B")) {
						endingBlock.second = currLineSplitted.at(0);
					}
					currBlockConstantsObject.insert(currTitle, currValueAsString);
				} else if(currType == "b") {
					if(currValueAsString == "TRUE")
						currBlockConstantsObject.insert(currTitle, true);
					else if(currValueAsString == "FALSE")
						currBlockConstantsObject.insert(currTitle, false);
					else
						qFatal("T3TrackDatabase::import() -> CSV bad format: title stated as boolean but value is not boolean");
				} else if(currType == "f" || currType == "r") {
					bool conversionIsSucessful;
					float currValue = currValueAsString.toFloat(&conversionIsSucessful);
					if(!conversionIsSucessful)
						qFatal("T3TrackDatabase::import() -> CSV bad format: title stated as float but value is not float");
					currBlockConstantsObject.insert(currTitle, currValue);
				} else if(currType == "i") {
					bool conversionIsSucessful;
					int currValue = currValueAsString.toInt(&conversionIsSucessful);
					if(!conversionIsSucessful)
						qFatal("T3TrackDatabase::import() -> CSV bad format: title stated as float but value is not float");
					currBlockConstantsObject.insert(currTitle, currValue);
				} else {
					qFatal("T3TrackDatabase::import() -> CSV bad format: title type not recognized");
				}
			}
			currLineConstantsObject.insert(currLineSplitted.at(0), currBlockConstantsObject);
		}

		//initializing fields for variables for this block
		{
			QJsonObject currBlockVariablesObject;
			currBlockVariablesObject.insert("commandedSpeed", static_cast<uint16_t>(0));
			currBlockVariablesObject.insert("authority", false);
			currBlockVariablesObject.insert("switchPosition", false);
			currBlockVariablesObject.insert("light", QString("clear"));
			if(currLineSplitted.at(10) == "TRUE")
				currBlockVariablesObject.insert("crossingPosition", false);
			else
				currBlockVariablesObject.insert("crossingPosition", QString(""));
			currBlockVariablesObject.insert("trainOnBlock", QString(""));
			currBlockVariablesObject.insert("failure", QString(""));
			currBlockVariablesObject.insert("heaters", QString(""));
			currBlockVariablesObject.insert("peopleOnStation", static_cast<float>(0.0));
			currLineVariablesObject.insert(currLineSplitted.at(0), currBlockVariablesObject);
		}
	}
	if(startingBlock.first.isEmpty() || endingBlock.first.isEmpty()) {
		qFatal("T3TrackDatabase::import() -> CSV bad format: starting and ending block cannot be found.");
	}

	//add a wrapper layer to constants object to include starting and ending block for UI rendering purposes
	{
		QJsonObject currLineConstantsObjectWrapper;
		currLineConstantsObjectWrapper.insert("startingBlock1", startingBlock.first);
		currLineConstantsObjectWrapper.insert("endingBlock1", endingBlock.first);
		currLineConstantsObjectWrapper.insert("startingBlock2", startingBlock.second);
		currLineConstantsObjectWrapper.insert("endingBlock2",  endingBlock.second);
		currLineConstantsObjectWrapper.insert("blocksMap", currLineConstantsObject);
		lineVariablesObjects.push_back(currLineVariablesObject);
		lineConstantsObjects.push_back(currLineConstantsObjectWrapper);
	}

	QFile fileToWriteLog(QString(newFilePath).replace(".csv", "_json.json"));
	if(fileToWriteLog.open(QFile::WriteOnly) && lineConstantsObjects.count() > 0 && lineConstantsObjects.at(0).isObject())
		fileToWriteLog.write(QJsonDocument(lineConstantsObjects.last().toObject()).toJson());
	else
		qFatal(fileToWriteLog.errorString().toUtf8());
	fileToWriteLog.close();

	Q_EMIT onLineConstantsObjectsChanged();
}

inline T3TrackDatabase::T3TrackDatabase(QObject * parent) : QObject(parent) {

	//	//TESTING FOR RAIL LOADING
	import("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3RedLine.csv");
//	put("R_A_1", TrackProperty::TrainOnBlock, "1234");
//	put("R_A_1", TrackProperty::PeopleOnStation, "1234");
	import("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3GreenLine.csv");
	import("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3BlueLine.csv");
}

#endif // T3TRACKDATABASE_H

