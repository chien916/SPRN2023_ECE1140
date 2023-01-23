#ifndef T3PIDCONTROLLER_H
#define T3PIDCONTROLLER_H
/**
 * @brief The T3PidController class
 * https://en.wikipedia.org/wiki/PID_controller#/media/File:PID_en.svg
 * In the case for this project:
 * V_cmd -> r(t)
 * V_err -> e(t)
 * P -> u(t)
 *5
 */
class T3PidController {
  private:
	float (*plant)(float) {
		nullptr
	};
	float prev_e{0.0};
	float prev_y{0.0};
	float sum_e{0.0};
  public :
	explicit T3PidController(float (*plant)(float));
	float dt{0.0};
	float r;//desired setpoint
	float ki{0.0}, kp{0.0}, kd{0.0};
	bool integralOn{false}, propotionalOn{false}, derivativeOn{false};
	float iterate();
};

inline T3PidController::T3PidController( float (*plant)(float)) {
	this->plant = plant;
}

inline float T3PidController::iterate() {
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
#endif // T3PIDCONTROLLER_H



