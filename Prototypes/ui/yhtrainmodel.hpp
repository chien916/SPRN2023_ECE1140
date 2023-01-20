#ifndef YHTRAINMODEL_HPP
#define YHTRAINMODEL_HPP
#include <QtCore>

class YhTrainModel: public QObject {
  private:
	quint64 controlRegister = 0x0;
	qfloat16 commandedSpeed = 0.0;
	qfloat16 currentSpeed = 0.0;
	QHash<QString, qfloat16> vehicleData;//depends on vehicle model
//	QPointer<YhTrackModel> destination;

  public Q_SLOTS:


};
#endif // YHTRAINMODEL_HPP
