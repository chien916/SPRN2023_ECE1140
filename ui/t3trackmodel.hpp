#ifndef T3TRACKMODEL_H
#define T3TRACKMODEL_H
#include <QtQml>

#include "t3trainmodel.hpp"
#include "t3trackcontroller.hpp"
class T3TrackModel {
  private:
	//identifications of track block
	QString blockId = "";//constants after initialization

	//3.1 - All Track properties displayed to user
	float grade = 0.0;
	float elevation = 0.0;
	float length = 0.0;
	uint16_t speedLimit = 0;
	//towardsBlock in 3.4 as direction of travel
	QString crossing;//""|"up"|"down"
	QString heaters;//undefined
	QString beacons;//undefined
	bool isUnderground = false;

	//3.2 - Ticket Sales (People waiting at stations)
	uint16_t passengerCount = 0;//track model req 3.2

	//3.3 -> # of passengers boarding & disembark train shown
	//implements via function

	//3.4 - Train occupancy
	QPointer<T3TrainModel> trainModel = nullptr;
	float trainAtPercent = 0.0;
	QString towardsBlock;

	//3.5 - Track circuits signals sent and received

	//3.6 - Set environmental temperature
	float envTemp;

	//3.7 - Track heaters work
	//implements via function

	//3.8 - Switch positions and light states displayed
	QString light = "";//"clear"|"approach"|"stop"
	QString prevBlocks;//"B_A_12,B_C_35" use comma as delimiter
	QString nextBlocks;//"B_A_13" use comma as delimiter
	QString currPrevBlock;
	QString currNextBlock;

	//3.9 - Failture modes
	QString failureMode;

	//Extras - programmable logics controller
	QJSValue plcFunction;

  public:


};

#endif // T3TRACKMODEL_H
