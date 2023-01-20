#ifndef YHTRACKMODEL_HPP
#define YHTRACKMODEL_HPP

#include <QtCore>
#include <QtQml>
#include "yhtrainmodel.hpp"
class YhTrackModel: public QObject {
  public:

  private:
	//identifications of track block
	QString blockId = "";
	QString infrastructure = "";
	QString light = "";

	QList<QPointer<YhTrackModel>> prevBlocks;
	QList<QPointer<YhTrackModel>> nextBlocks;
	bool toYard = false;
	bool fromYard = false;

	//numeric properties of track block
	quint16 blockNumber = 0;//constant after loading
	quint16 speedLimit = 0;//constant after loading
	qfloat16 blockLength = 0.0;//constant after loading
	qfloat16 blockGrade = 0.0;//constant after loading
	qfloat16 elevation = 0.0;//constant after loading
	qfloat16 cumulativeElevation = 0.0;//constant after loading
	bool isUnderground = false;

	//programmable logics controller
	QJSValue plcFunction;

	//train object
	QPointer<YhTrainModel> trainModel = nullptr;
	qfloat16 trainAtPercent = 0.0;
	bool isMovingFoward = true;


  public:



};
#endif // YHTRACKMODEL_HPP
