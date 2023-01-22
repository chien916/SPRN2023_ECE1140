#ifndef T3TRACKCONTROLLER_H
#define T3TRACKCONTROLLER_H
#include <QtCore>
class T3TrackController: public QObject {
	Q_OBJECT
	explicit T3TrackController(QObject *parent = nullptr);
	//6.0 Wayside receive suggested speed & authorityfrom CTC

	//  public Q_SLOTS:
	//	void


	//6.1 Wayside automatically moves switches based on PLC program execution
	//6.2 Wayside automatically sets Traffic light color based on PLC program execution
	//6.3 Wayside receives train presence and broken rail from Track Model
	//6.4 Wayside sends track occupancy to CTC
	//6.5 Railway crossing lights and gates activated
	//6.6 PLC language based only on Boolean variables.
	//6.7 Load PLC file
	//6.8 In maintenance mode, manually set a switch position
	//6.9 Has safety critical architecture

  public Q_SLOTS:
	void post(const QString request);
};

inline T3TrackController::T3TrackController(QObject *parent): QObject(parent) {
//TO-DO
}

inline void T3TrackController::post(const QString request) {
	//TO-DO
}
#endif // T3TRACKCONTROLLER_H
