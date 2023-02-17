#ifndef T3Database_H
#define T3Database_H

#include <QtCore>
//#include "t3trackmodel.hpp"

/**
 * @brief The T3Database class
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


class T3Database: public QObject {
	Q_OBJECT
	//Context variables exposed to QML:
	Q_PROPERTY(QJsonArray trackConstantsObjects_QML MEMBER trackConstantsObjects NOTIFY onTrackConstantsObjectsChanged)
	Q_PROPERTY(QJsonArray trackVariablesObjects_QML MEMBER trackVariablesObjects NOTIFY onTrackVariablesObjectsChanged)
	QJsonArray trackConstantsObjects;//do not modify directly after initialization. use the setTrackProperty() slot instead!
	QJsonArray trackVariablesObjects;//do not modify directly after initialization. use the setTrackProperty() slot instead!
	Q_PROPERTY(QJsonArray trainObjects_QML MEMBER trainObjects NOTIFY onTrainObjectsChanged)
	QJsonArray trainObjects;
  Q_SIGNALS:
	void onTrackConstantsObjectsChanged();
	void onTrackVariablesObjectsChanged();
	void onTrainObjectsChanged();
  public:
	T3Database(QObject *parent = nullptr);
	//Track properties definiations
	enum TrackProperty {
		CommandedSpeed = 0 //real/float
		, Authority = 1 //bool
		, SwitchPostion = 2 //bool
		, ForwardLight = 3 //string
		, ReversedLight = 4 // string
		, CrossingPosition = 5//bool
		, TrainOnBlock = 6 //string
		, Failure = 7 //string
		, Heaters = 8 //string
		, PeopleOnStation = 9 //int
	};
	Q_ENUM(TrackProperty);
	//Train properties definitions
	enum TrainProperty {
		Id
		, Length
		, Height
		, Width
		, Mass
		, PidConstants
		, Acceleration
		, Velocity
		, CrewCount
		, PassangerCount
		, Aircon
		, ExteriorLights
		, InteriorLights
		, LeftDoors
		, RightDoors
		, Brakes
		, Failures
	};
	Q_ENUM(TrainProperty);
  private:
	const QHash<T3Database::TrackProperty, QPair<QString, int>> trackPropertiesMetaDataMap
	= std::initializer_list<std::pair<T3Database::TrackProperty, QPair<QString, int>>> {
		std::make_pair(T3Database::TrackProperty::CommandedSpeed, QPair<QString, int>(QString("commandedSpeed"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrackProperty::Authority, QPair<QString, int>(QString("authority"), qMetaTypeId<bool>()))
		, std::make_pair(T3Database::TrackProperty::SwitchPostion, QPair<QString, int>(QString("switchPosition"), qMetaTypeId<bool>()))
		, std::make_pair(T3Database::TrackProperty::ForwardLight, QPair<QString, int>(QString("forwardLight"), qMetaTypeId<QString>()))
		, std::make_pair(T3Database::TrackProperty::ReversedLight, QPair<QString, int>(QString("backwardLight"), qMetaTypeId<QString>()))
		, std::make_pair(T3Database::TrackProperty::CrossingPosition, QPair<QString, int>(QString("crossingPosition"), qMetaTypeId<bool>()))
		, std::make_pair(T3Database::TrackProperty::TrainOnBlock, QPair<QString, int>(QString("trainOnBlock"), qMetaTypeId<QString>()))
		, std::make_pair(T3Database::TrackProperty::Failure, QPair<QString, int>(QString("failure"), qMetaTypeId<QString>()))
		, std::make_pair(T3Database::TrackProperty::Heaters, QPair<QString, int>(QString("heaters"), qMetaTypeId<QString>()))
		, std::make_pair(T3Database::TrackProperty::PeopleOnStation, QPair<QString, int>(QString("peopleOnStation"), qMetaTypeId<uint16_t>()))
	};

	const QHash<T3Database::TrainProperty, QPair<QString, int>> trainPropertiesMetaDataMap
	= std::initializer_list<std::pair<T3Database::TrainProperty, QPair<QString, int>>> {
		std::make_pair(T3Database::TrainProperty::Length, QPair<QString, int>(QString("id"), qMetaTypeId<QString>()))
		, std::make_pair(T3Database::TrainProperty::Length, QPair<QString, int>(QString("length"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Height, QPair<QString, int>(QString("height"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Width, QPair<QString, int>(QString("width"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Mass, QPair<QString, int>(QString("mass"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::PidConstants, QPair<QString, int>(QString("pidData"), qMetaTypeId<QJsonObject>()))
		, std::make_pair(T3Database::TrainProperty::Acceleration, QPair<QString, int>(QString("acceleration"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Velocity, QPair<QString, int>(QString("velocity"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::CrewCount, QPair<QString, int>(QString("crewCount"), qMetaTypeId<uint16_t>()))
		, std::make_pair(T3Database::TrainProperty::PassangerCount, QPair<QString, int>(QString("passangerCount"), qMetaTypeId<uint16_t>()))
		, std::make_pair(T3Database::TrainProperty::Aircon, QPair<QString, int>(QString("aircon"), qMetaTypeId<QString>()))
		, std::make_pair(T3Database::TrainProperty::ExteriorLights, QPair<QString, int>(QString("exteriorLights"), qMetaTypeId<bool>()))
		, std::make_pair(T3Database::TrainProperty::InteriorLights, QPair<QString, int>(QString("interiorLights"), qMetaTypeId<bool>()))
		, std::make_pair(T3Database::TrainProperty::LeftDoors, QPair<QString, int>(QString("leftDoors"), qMetaTypeId<bool>()))
		, std::make_pair(T3Database::TrainProperty::RightDoors, QPair<QString, int>(QString("rightDoors"), qMetaTypeId<bool>()))
		, std::make_pair(T3Database::TrainProperty::Brakes, QPair<QString, int>(QString("brakes"), qMetaTypeId<QString>()))
		, std::make_pair(T3Database::TrainProperty::Failures, QPair<QString, int>(QString("failures"), qMetaTypeId<QString>()))
	};
  public:
	void setTrackProperty(QString blockId, T3Database::TrackProperty trackProperty, QVariant value);
	QVariant getTrackProperty(QString blockId, T3Database::TrackProperty trackProperty);
	void addTrackFromCsv(const QString filePath);

	void setTrainProperty(QString trainId, T3Database::TrainProperty trainProperty, QVariant value);
	QVariant getTrainProperty(QString trainId, T3Database::TrainProperty trainProperty);
	void addTrainFromCtc(const QString metaInfo);
};

/**
 * @brief T3Database::setTrackProperty
 * @param request
 * Patch variables with certain values
 *
 */
inline void T3Database::setTrackProperty(QString blockId, T3Database::TrackProperty trackProperty, QVariant value) {
	QPair<QString, int> metaData = trackPropertiesMetaDataMap.value(trackProperty);
	if(!value.canConvert(metaData.second))
		qFatal("T3Database::setTrackProperty() -> property value required and insetTrackPropertyted format doesn't match");
	value.convert(metaData.second);
	bool fieldIsFound = false;
	for(qsizetype i = 0; i < trackVariablesObjects.size(); ++i) { //for every line
		QJsonObject currtrackVariablesObject = trackVariablesObjects[i].toObject();
		if(currtrackVariablesObject.find(blockId) != currtrackVariablesObject.end()) {
			QJsonObject currBlockVariablesObject = currtrackVariablesObject[blockId].toObject();
			currBlockVariablesObject[metaData.first] = value.toJsonValue();
			currtrackVariablesObject[blockId] = currBlockVariablesObject;
			trackVariablesObjects[i] = currtrackVariablesObject;
			fieldIsFound = true;
			break;
		}
	}
	if(!fieldIsFound)
		qFatal("T3Database::setTrackProperty() -> cannot find the block id insetTrackPropertyted");
	Q_EMIT onTrackVariablesObjectsChanged();
}

inline QVariant T3Database::getTrackProperty(QString blockId, TrackProperty trackProperty) {
	QPair<QString, int> metaData = trackPropertiesMetaDataMap.value(trackProperty);
	for(qsizetype i = 0; i < trackVariablesObjects.size(); ++i) { //for every line
		QJsonObject currtrackVariablesObject = trackVariablesObjects[i].toObject();
		if(currtrackVariablesObject.find(blockId) != currtrackVariablesObject.end()) {
			QJsonObject currBlockVariablesObject = currtrackVariablesObject[blockId].toObject();
			QVariant valueRequested = currBlockVariablesObject[metaData.first].toVariant();
			if(valueRequested.convert(metaData.second))
				return valueRequested;
			else
				qFatal("T3Database::getTrackProperty() -> cannot convert value to the right type");
		}
	}
	qFatal("T3Database::getTrackProperty() -> cannot find the block id insetTrackPropertyted");
	return QVariant();//should not reach this step..
}

inline void T3Database::addTrackFromCsv(const QString filePath) {
	QString newFilePath = QString(filePath).replace("file:///", "");
	qsizetype requiredColumnCount = 0;
	QFile file(newFilePath);
	if(!newFilePath.contains(".csv")) {
		qFatal("T3Database::addTrackFromCsv() -> CSV bad format: file received is not csv extensions");
	}
	if(!file.open(QIODevice::ReadOnly)) {
		qFatal(file.errorString().toUtf8());
	}
	QList<QList<QString>> titles;
	QJsonObject currtrackConstantsObject;
	QJsonObject currtrackVariablesObject;
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
						qFatal("T3Database::addTrackFromCsv() -> CSV bad format: title name and type format wrong");
					titles.append(TitleAndTypesSplitted);
				}
			} else
				qFatal("T3Database::addTrackFromCsv() -> CSV bad format: title doesn't match.");
			continue;
		}
		QStringList currLineSplitted = currLineRaw.split(',');
		if(currLineSplitted.count() != requiredColumnCount) {
			qFatal("T3Database::addTrackFromCsv() -> CSV bad format: content column count mismatch.");
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
						qFatal("T3Database::addTrackFromCsv() -> CSV bad format: title stated as boolean but value is not boolean");
				} else if(currType == "f" || currType == "r") {
					bool conversionIsSucessful;
					float currValue = currValueAsString.toFloat(&conversionIsSucessful);
					if(!conversionIsSucessful)
						qFatal("T3Database::addTrackFromCsv() -> CSV bad format: title stated as float but value is not float");
					currBlockConstantsObject.insert(currTitle, currValue);
				} else if(currType == "i") {
					bool conversionIsSucessful;
					int currValue = currValueAsString.toInt(&conversionIsSucessful);
					if(!conversionIsSucessful)
						qFatal("T3Database::addTrackFromCsv() -> CSV bad format: title stated as float but value is not float");
					currBlockConstantsObject.insert(currTitle, currValue);
				} else {
					qFatal("T3Database::addTrackFromCsv() -> CSV bad format: title type not recognized");
				}
			}
			currtrackConstantsObject.insert(currLineSplitted.at(0), currBlockConstantsObject);
		}

		//initializing fields for variables for this block
		{
			QJsonObject currBlockVariablesObject;
			currBlockVariablesObject.insert("commandedSpeed", static_cast<uint16_t>(0));
			currBlockVariablesObject.insert("authority", false);
			currBlockVariablesObject.insert("switchPosition", false);
			if(currLineSplitted.at(12).contains("BIDIRECTIONAL")
					|| currLineSplitted.at(12).contains("FORWARD"))
				currBlockVariablesObject.insert("forwardLight", QString("clear"));
			else
				currBlockVariablesObject.insert("forwardLight", QString(""));
			if(currLineSplitted.at(12).contains("BIDIRECTIONAL")
					|| currLineSplitted.at(12).contains("REVERSED"))
				currBlockVariablesObject.insert("reversedLight", QString("clear"));
			else
				currBlockVariablesObject.insert("reversedLight", QString(""));
			if(currLineSplitted.at(10) == "TRUE")
				currBlockVariablesObject.insert("crossingPosition", false);
			else
				currBlockVariablesObject.insert("crossingPosition", QString(""));
			currBlockVariablesObject.insert("trainOnBlock", QString(""));
			currBlockVariablesObject.insert("failure", QString(""));
			currBlockVariablesObject.insert("heaters", QString(""));
			currBlockVariablesObject.insert("peopleOnStation", static_cast<float>(0.0));
			currtrackVariablesObject.insert(currLineSplitted.at(0), currBlockVariablesObject);
		}
	}
	if(startingBlock.first.isEmpty() || endingBlock.first.isEmpty()) {
		qFatal("T3Database::addTrackFromCsv() -> CSV bad format: starting and ending block cannot be found.");
	}

	//add a wrapper layer to constants object to include starting and ending block for UI rendering purposes
	{
		QJsonObject currtrackConstantsObjectWrapper;
		currtrackConstantsObjectWrapper.insert("startingBlock1", startingBlock.first);
		currtrackConstantsObjectWrapper.insert("endingBlock1", endingBlock.first);
		currtrackConstantsObjectWrapper.insert("startingBlock2", startingBlock.second);
		currtrackConstantsObjectWrapper.insert("endingBlock2",  endingBlock.second);
		currtrackConstantsObjectWrapper.insert("blocksMap", currtrackConstantsObject);
		trackVariablesObjects.push_back(currtrackVariablesObject);
		trackConstantsObjects.push_back(currtrackConstantsObjectWrapper);
	}

	QFile fileToWriteLog(QString(newFilePath).replace(".csv", "_ConstantsJson.json"));
	if(fileToWriteLog.open(QFile::WriteOnly) && trackConstantsObjects.count() > 0 && trackConstantsObjects.at(0).isObject())
		fileToWriteLog.write(QJsonDocument(trackConstantsObjects.last().toObject()).toJson());
	else
		qFatal(fileToWriteLog.errorString().toUtf8());

	QFile fileToWriteLog2(QString(newFilePath).replace(".csv", "_VariablesJson.json"));
	if(fileToWriteLog2.open(QFile::WriteOnly) && trackVariablesObjects.count() > 0 && trackVariablesObjects.at(0).isObject())
		fileToWriteLog2.write(QJsonDocument(trackVariablesObjects.last().toObject()).toJson());
	else
		qFatal(fileToWriteLog.errorString().toUtf8());
	fileToWriteLog2.close();

	Q_EMIT onTrackConstantsObjectsChanged();
}

inline void T3Database::setTrainProperty(QString trainId, TrainProperty trainProperty, QVariant value) {
	QPair<QString, int> metaData = trainPropertiesMetaDataMap.value(trainProperty);
	if(!value.canConvert(metaData.second))
		qFatal("T3Database::setTrainProperty() -> property value required and insetTrackPropertyted format doesn't match");
	value.convert(metaData.second);
	for(qsizetype i = 0; i < trainObjects.size(); ++i) {
		if(!trainObjects.at(i).isObject())
			qFatal("T3Database::setTrainProperty() -> current train object is not an object.");
		QJsonObject currTrainObject = trainObjects.at(i).toObject();
		if(currTrainObject.find(QString("id")) == currTrainObject.end())
			qFatal("T3Database::setTrainProperty() -> current train object does not has id field.");
		if(currTrainObject.value("id") == trainId) {
			if(currTrainObject.find(metaData.first) == currTrainObject.end())
				qFatal("T3Database::setTrainProperty() -> current train object does not has the requested field.");
			currTrainObject[metaData.first] = value.toJsonValue();
			return;
		}
	}
	qFatal("T3Database::setTrainProperty() -> cannot find train with ID provided");
}

inline QVariant T3Database::getTrainProperty(QString trainId, TrainProperty trainProperty) {
	QPair<QString, int> metaData = trainPropertiesMetaDataMap.value(trainProperty);
	for(qsizetype i = 0; i < trainObjects.size(); ++i) {
		if(!trainObjects.at(i).isObject())
			qFatal("T3Database::getTrainProperty() -> current train object is not an object.");
		QJsonObject currTrainObject = trainObjects.at(i).toObject();
		if(currTrainObject.find(QString("id")) == currTrainObject.end())
			qFatal("T3Database::getTrainProperty() -> current train object does not has id field.");
		if(currTrainObject.value("id") == trainId) {
			if(currTrainObject.find(metaData.first) == currTrainObject.end())
				qFatal("T3Database::getTrainProperty() -> current train object does not has the requested field.");
			QVariant res = currTrainObject[metaData.first].toVariant();
			if(!res.canConvert(metaData.second))
				qFatal("T3Database::setTrainProperty() -> property value required and insetTrackPropertyted format doesn't match");
			res.convert(metaData.second);
			return res;
		}
	}
	qFatal("T3Database::setTrainProperty() -> cannot find train with ID provided");
}

inline void T3Database::addTrainFromCtc(const QString metaInfo) {

}

inline T3Database::T3Database(QObject * parent) : QObject(parent) {
	//	//TESTING FOR RAIL LOADING
	addTrackFromCsv("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3RedLine.csv");
	//	setTrackProperty("R_A_1", TrackProperty::TrainOnBlock, "1234");
	//	setTrackProperty("R_A_1", TrackProperty::PeopleOnStation, "1234");
	addTrackFromCsv("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3GreenLine.csv");
	addTrackFromCsv("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3BlueLine.csv");
}

#endif // T3Database_H

