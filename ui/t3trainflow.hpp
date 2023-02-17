#ifndef T3TRAINFLOW_H
#define T3TRAINFLOW_H
#include <QtCore>
/**
 * Do not store any data here!
 * @brief The T3TrainFlow class
 */
class T3TrainFlow {
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
  public:
	explicit T3TrainFlow();

	//4.9 Annouces Stations & stops correctly at stations
	//4.10 Has safety critical architecture

	// QObject interface
};

inline float T3TrainFlow::PidController::plant(float) {

}

inline float T3TrainFlow::PidController::iterate() {
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

inline T3TrainFlow::T3TrainFlow() {
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

#endif // T3TRAINFLOW_H
