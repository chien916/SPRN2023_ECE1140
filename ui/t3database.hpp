#ifndef T3Database_H
#define T3Database_H

#include <QtCore>
#include <QtQml>
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
	QJsonArray trainObjects;//do not modify directly after initialization. use the setTrainProperty() slot instead!
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
		, MaintainanceMode = 10
	};
	Q_ENUM(TrackProperty);
	//Train properties definitions
	enum TrainProperty {
		Id = 0
		, Length = 1
		, Height = 2
		, Width = 3
		, Mass = 4
		, Acceleration = 5
		, Velocity = 6
		, CrewCount = 7
		, PassangerCount = 8
		, Aircon = 9
		, ExteriorLights = 10
		, InteriorLights = 11
		, LeftDoors = 12
		, RightDoors = 13
		, Brakes = 14
		, Failures = 15
		, Pid_Prev_e
		, Pid_Prev_y
		, Pid_Sum_e
		, Pid_Dt
		, Pid_R
		, Pid_Ki
		, Pid_Kp
		, Pid_Kd
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
		, std::make_pair(T3Database::TrackProperty::MaintainanceMode, QPair<QString, int>(QString("maintainanceMode"), qMetaTypeId<bool>()))
	};

	const QHash<T3Database::TrainProperty, QPair<QString, int>> trainPropertiesMetaDataMap
	= std::initializer_list<std::pair<T3Database::TrainProperty, QPair<QString, int>>> {
		std::make_pair(T3Database::TrainProperty::Id, QPair<QString, int>(QString("id"), qMetaTypeId<QString>()))
		, std::make_pair(T3Database::TrainProperty::Length, QPair<QString, int>(QString("length"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Height, QPair<QString, int>(QString("height"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Width, QPair<QString, int>(QString("width"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Mass, QPair<QString, int>(QString("mass"), qMetaTypeId<float>()))
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
		, std::make_pair(T3Database::TrainProperty::Pid_Prev_e, QPair<QString, int>(QString("pid_prev_e"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Pid_Prev_y, QPair<QString, int>(QString("pid_prev_y"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Pid_Sum_e, QPair<QString, int>(QString("pid_sum_e"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Pid_Dt, QPair<QString, int>(QString("pid_dt"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Pid_R, QPair<QString, int>(QString("pid_r"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Pid_Ki, QPair<QString, int>(QString("pid_ki"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Pid_Kp, QPair<QString, int>(QString("pid_kp"), qMetaTypeId<float>()))
		, std::make_pair(T3Database::TrainProperty::Pid_Kd, QPair<QString, int>(QString("pid_kd"), qMetaTypeId<float>()))
	};

	//QString plcProgram = "function(a){return a;}";

  public:
	Q_INVOKABLE void setTrackProperty(QString blockId, T3Database::TrackProperty trackProperty, QVariant value);
	Q_INVOKABLE QVariant getTrackProperty(QString blockId, T3Database::TrackProperty trackProperty);
	Q_INVOKABLE void addTrackFromCsv(const QString filePath);
	Q_INVOKABLE void setTrainProperty(QString trainId, T3Database::TrainProperty trainProperty, QVariant value);
	Q_INVOKABLE QVariant getTrainProperty(QString trainId, T3Database::TrainProperty trainProperty);
	Q_INVOKABLE void addTrainFromCtc(const QString trainId, const QString trackId, bool moveDirection);
	Q_INVOKABLE void removeTrainFromCtc(const QString trainId);

	float pid_plant(float);
	void pid_iterate();

	void plc_iterate();


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
			if(valueRequested.convert(metaData.second)) {
				//qInfo() << "T3Database::getTrackProperty() -> " << valueRequested;
				return valueRequested;
			} else
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
			currBlockVariablesObject.insert("authority", true);
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
			currBlockVariablesObject.insert("maintainanceMode", false);
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

inline void T3Database::addTrainFromCtc(const QString trainId, const QString blockId, bool moveDirection) {
	QJsonObject trainObject;
	trainObject.insert(QString("id"), trainId);
	trainObject.insert(QString("length"), 32.2);
	trainObject.insert(QString("height"), 3.42);
	trainObject.insert(QString("width"), 2.65);
	trainObject.insert(QString("mass"), 40.9e3);
	trainObject.insert(QString("acceleration"), 0.0);
	trainObject.insert(QString("velocity"), 0.0);
	trainObject.insert(QString("crewCount"), 1);
	trainObject.insert(QString("passangerCount"), 0);
	trainObject.insert(QString("aircon"), QString(""));
	trainObject.insert(QString("exteriorLights"), false);
	trainObject.insert(QString("interiorLights"), false);
	trainObject.insert(QString("leftDoors"), false);
	trainObject.insert(QString("rightDoors"), false);
	trainObject.insert(QString("brakes"), QString(""));
	trainObject.insert(QString("failures"), QString(""));
	trainObject.insert(QString("pid_prev_e"), 0.0);
	trainObject.insert(QString("pid_prev_y"), 0.0);
	trainObject.insert(QString("pid_sum_e"), 0.0);
	trainObject.insert(QString("pid_dt"), 1.0);
	trainObject.insert(QString("pid_r"), 0.0);
	trainObject.insert(QString("pid_ki"), 0.1);
	trainObject.insert(QString("pid_kp"), 0.1);
	trainObject.insert(QString("pid_kd"), 0.1);
	setTrackProperty(blockId, TrackProperty::TrainOnBlock, trainId);
	trainObjects.push_front(trainObject);

	QStringList trainOnBlock = {QString(trainId), QString(moveDirection ? "F" : "B"), QString::number(0.0)};

	setTrackProperty(blockId, TrackProperty::TrainOnBlock, trainOnBlock.join("_"));

	Q_EMIT onTrainObjectsChanged();
	Q_EMIT onTrackVariablesObjectsChanged();
}

inline void T3Database::removeTrainFromCtc(const QString trainId) {
	for(qsizetype i = 0; i < trainObjects.count(); ++i) {
		QJsonObject currTrainObject = trainObjects.at(i).toObject();
		if(currTrainObject.value(QString("id")).toString().trimmed() == trainId.trimmed()) {
			trainObjects.removeAt(i);
			Q_EMIT onTrainObjectsChanged();
			return;
		}
	}
	qFatal("T3Database::removeTrainFromCtc() -> cannot find train id provided.");
}

inline T3Database::T3Database(QObject * parent) : QObject(parent) {
	//	//TESTING FOR RAIL LOADING
	addTrackFromCsv("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3RedLine.csv");
	//	setTrackProperty("R_A_1", TrackProperty::TrainOnBlock, "1234");
	//	setTrackProperty("R_A_1", TrackProperty::PeopleOnStation, "1234");
	addTrackFromCsv("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3GreenLine.csv");
	addTrackFromCsv("C:/Users/YIQ25/Documents/Academics/ECE1140/Resources/T3BlueLine.csv");
}

inline float T3Database::pid_plant(float inp) {
	return inp;
}

inline void T3Database::pid_iterate() {
	for(qsizetype i = 0; i < trainObjects.size(); ++i) {
		QJsonObject currTrainObject = trainObjects.at(i).toObject();

		//retrieve pid data from train database
		float r = currTrainObject.value(QString("pid_r")).toDouble();
		float prev_e = currTrainObject.value(QString("pid_prev_e")).toDouble();
		float prev_y = currTrainObject.value(QString("pid_prev_y")).toDouble();
		float sum_e = currTrainObject.value(QString("pid_sum_e")).toDouble();
		float dt = currTrainObject.value(QString("pid_dt")).toDouble();
		float kp = currTrainObject.value(QString("pid_kp")).toDouble();
		float ki = currTrainObject.value(QString("pid_ki")).toDouble();
		float kd = currTrainObject.value(QString("pid_kd")).toDouble();

		//calculate new values
		float e = r - prev_y;
		float P = kp * e;
		float I = ki * sum_e * dt;
		float D = kd * (prev_e + e) * dt * 0.5;//trapozoidal integration
		float u = P + I + D;
		float y = pid_plant(u);

		//overwrite pid data with new values
		currTrainObject.insert("velocity", y);
		currTrainObject.insert("pid_prev_y", y);
		currTrainObject.insert("pid_prev_e", e);
		currTrainObject.insert("pid_sum_e", sum_e + e);

		trainObjects.replace(i, currTrainObject);
	}
	Q_EMIT onTrainObjectsChanged();
}

inline void T3Database::plc_iterate() {

	for(qsizetype i = 0; i < trackVariablesObjects.count(); ++i) {
		QJsonObject currTrackVariablesObject = trackVariablesObjects.at(i).toObject();
		QJsonObject currTrackConstantsObject = trackConstantsObjects.at(i).toObject().value("blocksMap").toObject();
		QStringList blockIds = currTrackVariablesObject.keys();
		for(qsizetype j = 0; j < blockIds.count(); ++j) {
			QJsonObject currBlockVariablesObject = currTrackVariablesObject.value(blockIds.at(j)).toObject();
			QJsonObject currBlockConstantsObject = currTrackConstantsObject.value(blockIds.at(j)).toObject();

			//----STAGE 1 : PLC PROGRAM EXECUTION

			//determine prev2 prev1 next1 next2 blockId
			bool currSwitch = currBlockVariablesObject.value("switchPosition").toBool();
			bool currHasCrossing = currBlockConstantsObject.value("crossing").toBool();
			bool prev1ViewDirectionReverse = true;
			bool next1ViewDirectionReverse = true;
			QString currPrev1Block1 = currBlockConstantsObject.value("prevBlock1").toString();
			if(currPrev1Block1.compare("START_T") == 0)
				currPrev1Block1 = currTrackConstantsObject.value("startingBlock2").toString();
			else if(currPrev1Block1.compare("START_B") == 0)
				currPrev1Block1 = currTrackConstantsObject.value("startingBlock1").toString();
			else prev1ViewDirectionReverse = false;

			QString currPrev1Block2 = currBlockConstantsObject.value("prevBlock2").toString();
			QString currNext1Block1 = currBlockConstantsObject.value("nextBlock1").toString();
			if(currPrev1Block1.compare("END_T") == 0)
				currPrev1Block1 = currTrackConstantsObject.value("endingBlock2").toString();
			else if(currPrev1Block1.compare("END_B") == 0)
				currPrev1Block1 = currTrackConstantsObject.value("endingBlock1").toString();
			else next1ViewDirectionReverse = false;

			QString currNext1Block2 = currBlockConstantsObject.value("nextBlock2").toString();
			QString currPrev1Block
				= (currNext1Block2 != "" && currNext1Block2 != "PASSIVE" && !currSwitch)
				  ? currPrev1Block2
				  : currPrev1Block1;
			QString currNext1Block
				= (currPrev1Block2 != "" && currPrev1Block2 != "PASSIVE" && !currSwitch)
				  ? currNext1Block2
				  : currNext1Block1;

			//process prev1 block to get prev2

			QJsonObject prev1BlockVariablesObject = currTrackVariablesObject.value(currPrev1Block).toObject();
			QJsonObject prev1BlockConstantsObject = currTrackConstantsObject.value(currPrev1Block).toObject();

			bool prev1Switch = prev1BlockVariablesObject.value("switchPosition").toBool();
			QString currPrev2Block1 = prev1BlockConstantsObject.value("prevBlock1").toString();
			QString currPrev2Block2 = prev1BlockConstantsObject.value("prevBlock2").toString();

			QString currPrev2Block
				= (currPrev2Block2 != "" && currPrev2Block2 != "PASSIVE" && !prev1Switch)
				  ? currPrev2Block1
				  : currPrev2Block2;

			//process next1 block to get next2

			QJsonObject next1BlockVariablesObject = currTrackVariablesObject.value(currNext1Block).toObject();
			QJsonObject next1BlockConstantsObject = currTrackConstantsObject.value(currNext1Block).toObject();

			bool next1Switch = next1BlockVariablesObject.value("switchPosition").toBool();
			QString currNext2Block1 = next1BlockConstantsObject.value("nextBlock1").toString();
			QString currNext2Block2 = next1BlockConstantsObject.value("nextBlock2").toString();

			QString currNext2Block
				= (currNext2Block2 != "" && currNext2Block2 != "PASSIVE" && !next1Switch)
				  ? currNext2Block1
				  : currNext2Block2;

			//get occupancy of prev2 prev1 curr next1 next2
			QJsonObject prev2BlockVariablesObject = currTrackVariablesObject.value(currPrev2Block).toObject();
			QJsonObject next2BlockVariablesObject = currTrackVariablesObject.value(currNext2Block).toObject();

			bool prev2occupancy = prev2BlockVariablesObject.value("trainOnBlock").toString().compare("") != 0;
			bool prev1occupancy = prev1BlockVariablesObject.value("trainOnBlock").toString().compare("") != 0;
			bool curroccupancy = currBlockVariablesObject.value("trainOnBlock").toString().compare("") != 0;
			bool next1occupancy = next1BlockVariablesObject.value("trainOnBlock").toString().compare("") != 0;
			bool next2occupancy = next2BlockVariablesObject.value("trainOnBlock").toString().compare("") != 0;

			QString reversedLight = prev1occupancy ? "stop" : (prev2occupancy ? "approach" : "clear");
			QString forwardLight = next1occupancy ? "stop" : (next1occupancy ? "approach" : "clear");
			QString crossing = currHasCrossing
							   ? ((prev2occupancy || prev1occupancy || curroccupancy || next1occupancy || next2occupancy)
								  ? "down" : "up")
							   : "";

			currBlockVariablesObject.insert("forwardLight", forwardLight);
			currBlockVariablesObject.insert("reversedLight", reversedLight);
			currBlockVariablesObject.insert("crossingPosition", crossing);


			//----STAGE 2 : TRAIN POSITION UPDATE

			//trainOnBlock formats: ID_DIRECTION_PERCENT
			QStringList trainOnBlock = currBlockVariablesObject.value("trainOnBlock").toString().split("_");
			Q_ASSERT(trainOnBlock.size() == 3);

			QString trainId = trainOnBlock.at(0);
			QString trainDirection = trainOnBlock.at(1);
			bool toFloatConversionStatus = true;
			float trainTravelledPercent = trainOnBlock.at(2).toFloat(&toFloatConversionStatus);
			Q_ASSERT(toFloatConversionStatus);

			//iterate per one second
			float dt = 1 / 60 / 60; //1 second in hours
			float v = getTrainProperty(trainId, TrainProperty::Velocity).toFloat(&toFloatConversionStatus);
			Q_ASSERT(toFloatConversionStatus);
			float ds = dt * v;

			float totalBlockLength = currBlockConstantsObject.value("length").toDouble();
			float remainingBlockLength = totalBlockLength * trainTravelledPercent;
			if(remainingBlockLength < ds) {
				//time to traverse to next block

				//EXTRACTION
				QString nextOrPrevBlockId =  trainDirection.contains("F")
											 ? currNext1Block : currPrev1Block;
				QJsonObject nextOrPrevBlockConstantsObject
					= currTrackConstantsObject.value(nextOrPrevBlockId).toObject();
				QJsonObject nextOrPrevBlockVariablesObject
					= currTrackVariablesObject.value(nextOrPrevBlockId).toObject();

				totalBlockLength = nextOrPrevBlockConstantsObject.value("length").toDouble();
				float newInitialBlockLength = ds - remainingBlockLength;
				remainingBlockLength = totalBlockLength - newInitialBlockLength;
				trainTravelledPercent = 1 - remainingBlockLength / totalBlockLength;
				if(trainDirection.contains("F")
						? next1ViewDirectionReverse : prev1ViewDirectionReverse)
					trainDirection = trainDirection.contains("F") ? "R" : "F";
				trainOnBlock = QStringList(std::initializer_list<QString>
				{trainId, trainDirection, QString::number(trainTravelledPercent)});

				//WRITE-BACK
				currBlockVariablesObject.insert("trainOnBlock", QString(""));
				nextOrPrevBlockVariablesObject.insert("trainOnBlock", trainOnBlock.join("_"));
				currTrackVariablesObject.insert(blockIds.at(j), currBlockVariablesObject);
				currTrackVariablesObject.insert(nextOrPrevBlockId, nextOrPrevBlockVariablesObject);

			} else {
				//stays on current block
				remainingBlockLength -= ds;
				trainTravelledPercent = 1 - remainingBlockLength / totalBlockLength;
				trainOnBlock = QStringList(std::initializer_list<QString>
				{trainId, trainDirection, QString::number(trainTravelledPercent)});
				//WRITE-BACK
				currBlockVariablesObject.insert("trainOnBlock", trainOnBlock.join("_"));
				currTrackVariablesObject.insert(blockIds.at(j), currBlockVariablesObject);

			}
			//---STAGE 3 : TRAIN ATC SYSTEM AUTOMATIC CONTROLS
			currTrackVariablesObject.insert(blockIds.at(j), currBlockVariablesObject);
		}
		trackVariablesObjects.replace(i, currTrackVariablesObject);
	}

	/**
		 *
		 * inputs from ctc:
		 * -> connection[0] -> connection to track model
		 * -> authority from CTC[1] -> read from db
		 * -> suggested speed from CTC[2:9] -> read from db
		 * -> left switch position from CTC[10] -> read from db
		 * -> right switch position from CTC[11] -> read from db

		 *
		 * inputs from track model (db):
		 * -> connection[16] -> connection to track model
		 * -> prevprev occupancy[17] -> read from db
		 * -> prev occypancy[18] -> read from db
		 * -> curr occupancy[19] -> read from db
		 * -> next occupancy[20] -> read from db
		 * -> nextnext occupancy[21] -> read from db
		 * -> temperature from current Track Model[22:29] -> read from db
		 * -> failure mode[30:31] -> read from db
		 *
		 *
		 * outputs to ctc:
		 * -> curr occupancy[0] -> read from db -> do nothing
		 * -> failure mode[1:2] -> read from db -> do nothing
		 *
		 * outputs to track model
		 * -> switch position from CTC[16] -> read from db -> do nothing
		 * -> light signal to prev[17:18] -> check prev occupancy and prev prev occupancy -> write to db
		 * -> light signal to next[19:20]-> check next occupancy and next next occupancy -> write to db
		 * -> crossing[21]  -> check prev occupancy and prev prev occupancy and next occupancy and next next occupancy -> write to db
		 * -> heater[22] -> check temperature from current track model -> write to db
		 * -> prev occupancy[23]
		 * -> next occupancy[24]
		 *
		 * outputs to beacon
		 * -> authority from CTC[4] -> read from db AS LONG AS CONNECTIONS OK -> pass to beacon -> do nothing
		 * -> commanded speed[5:12] -> read from db AS LONG AS CONNECTIONS OK -> pass to beacon -> do nothing
		 */
}

#endif // T3Database_H

