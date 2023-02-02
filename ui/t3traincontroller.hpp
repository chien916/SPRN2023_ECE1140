#ifndef T3TRAINCONTROLLER_H
#define T3TRAINCONTROLLER_H
#include <QtCore>
class T3TrainController: public QObject {
	Q_OBJECT

  private:
	//Speed regulation module
	struct PidController {
	  private:
		float plant(float);
		float prev_e{0.0}, prev_y{0.0}, sum_e{0.0};
	  public:
		float dt{0.0};
		float r;//desired setpoint
		float ki{0.0}, kp{0.0}, kd{0.0};
		bool integralOn{false}, propotionalOn{false}, derivativeOn{false};
		float iterate();
	} pidController;

	//Views
	Q_PROPERTY(QList<float> rbuffer_q MEMBER rbuffer NOTIFY onrybufferChanged)
	Q_PROPERTY(QList<float> tbuffer_q MEMBER tbuffer NOTIFY onrybufferChanged)
	Q_PROPERTY(QList<float> ybuffer_q MEMBER ybuffer NOTIFY onrybufferChanged)
	Q_PROPERTY(float r_q READ readR WRITE writeR NOTIFY onrybufferChanged)
	QList<float> tbuffer, ybuffer, rbuffer;
	void writeR(float newR) {
		pidController.r = newR;
	}
	float readR() {
		return pidController.r;
	}
  Q_SIGNALS:
	void onrybufferChanged();


	//4.0 Regulate train speed at velocity setpoint from CTC & Train Driver
  private:
	float testPlant(float input) {
		return input;
	};

//	//4.1 Train does not exceed authority or speed limit
//	//4.2 Emergency Brake Activation by Driver
//	//4.3 Service Brake by Driver
//	//4.4 Engineer sets Kp & Ki

//	//4.5 Driver increase & decrease speed
//	virtual void setCommandedSpeed(float commandedSpeed);
//	//4.6 Use Speed & Authority from Track Circuit
//	void setAuthority(char* blockId);
//	//4.7 Train lights on and off;
//	virtual void setInteriorLight(bool lightOpen);
//	virtual void setExteriorLight(bool lightOpen);
//	//4.8 Train doors open and close
//	virtual void setLeftDoor(bool doorOpen);
//	virtual void setRightDoor(bool doorOpen);
  public:
	explicit T3TrainController(QObject *parent = nullptr);

	//4.9 Annouces Stations & stops correctly at stations
	//4.10 Has safety critical architecture
  public Q_SLOTS:
	void post(const QString request);

	// QObject interface
  protected:
	void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
};

inline float T3TrainController::PidController::plant(float) {

}

inline float T3TrainController::PidController::iterate() {
	float curr_e = r - prev_y;
	float P = kp * curr_e;
	float I = ki * sum_e * dt;
	float D = kd * (prev_e + curr_e) * dt * 0.5;//trapozoidal integration
	float u = (propotionalOn ? P : 0.0) + (integralOn ? I : 0.0) + (derivativeOn ? D : 0.0);
	float y = plant(u);
	prev_y = y;
	prev_e = curr_e;
	sum_e += curr_e;
	return y;
}

inline T3TrainController::T3TrainController(QObject *parent) : QObject(parent) {
	//testing only
	pidController.propotionalOn = true;
	pidController.integralOn = true;
	pidController.derivativeOn = true;
	pidController.r  = 1000;
	pidController.kp = 0.001f;
	pidController.ki = 0.05f;
	pidController.kd = 0.01f;
	pidController.dt = 0.1f;
}

inline void T3TrainController::post(const QString request) {
	//TO-DO
}

inline void T3TrainController::timerEvent(QTimerEvent *event) {
	Q_UNUSED(event)
	float newT = tbuffer.empty() ? 0 : tbuffer.last() + pidController.dt;
	float newY = pidController.iterate();
	if(ybuffer.length() >= 100) {
		tbuffer.pop_front();
		ybuffer.pop_front();
		rbuffer.pop_front();
	}
	tbuffer.push_back(newT);
	ybuffer.push_back(newY);
	rbuffer.push_back(pidController.r);
//	qDebug() << newY;
//	qDebug() << "Size" << ybuffer.length();
	emit onrybufferChanged();
}

#endif // T3TRAINCONTROLLER_H
