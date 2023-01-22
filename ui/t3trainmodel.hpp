#ifndef T3TRAINMODEL_H
#define T3TRAINMODEL_H
#include <QtCore>
#include "t3traincontroller.hpp"

class T3TrainModel {
  private:
	float plant(float u);
  public:
	//5.0 - Given a power command, calculates Newton's laws

	//5.1 - Train properties displayed to user
	float length, height, width, mass, accel, velocity;

	//5.2 - Crew & Passenger count
	uint16_t crewCount, passengerCount;

	//5.3 - Received track circuit signal with suggested speed & authority
	//SEE SLOTS

	//5.4 - Set and regulate internal train tempature
	float temperature;
	//SEE SLOTS for regulate

	//5.5 - Train lights on and off
	bool interiorLightOpen, exteriorLightOpen;

	//5.6 - Train doors open and close
	bool leftDoorOpen, rightDoorOpen;

	//5.7 - Beacon inputs are received
	QString authority;
	uint16_t commandedSpeed;
	//SEE SLOTS

	//5.8 - Passenger activates Emergency Brake
	QString brake;//""|"passenger"|"service"

	//5.9 - Failure Modes
	QString failureModes;//""|"trainEngine"|"signalPickup"|"brake"

};

inline float T3TrainModel::plant(float u) {
	//TO-DO
	return 0.0;

}
#endif // T3TRAINMODEL_H
