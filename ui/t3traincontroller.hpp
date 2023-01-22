#ifndef T3TRAINCONTROLLER_H
#define T3TRAINCONTROLLER_H
#include <QtCore>
class T3TrainController: public QObject {
	Q_OBJECT
	//4.0 Regulate train speed at velocity setpoint from CTC & Train Driver
	//4.1 Train does not exceed authority or speed limit
	//4.2 Emergency Brake Activation by Driver
	//4.3 Service Brake by Driver
	//4.4 Engineer sets Kp & Ki
	float kp, ki;
	//4.5 Driver increase & decrease speed
	virtual void setCommandedSpeed(float commandedSpeed);
	//4.6 Use Speed & Authority from Track Circuit
	void setAuthority(char* blockId);
	//4.7 Train lights on and off;
	virtual void setInteriorLight(bool lightOpen);
	virtual void setExteriorLight(bool lightOpen);
	//4.8 Train doors open and close
	virtual void setLeftDoor(bool doorOpen);
	virtual void setRightDoor(bool doorOpen);
  public:
	T3TrainController(QObject *parent = nullptr);

	//4.9 Annouces Stations & stops correctly at stations
	//4.10 Has safety critical architecture
  public Q_SLOTS:
	void post(const QString request);
};
#endif // T3TRAINCONTROLLER_H


inline T3TrainController::T3TrainController(QObject *parent) : QObject(parent)
{}

inline void T3TrainController::post(const QString request) {
	//TO-DO
}

