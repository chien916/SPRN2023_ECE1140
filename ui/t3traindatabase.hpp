#ifndef T3TRAINDATABASE_H
#define T3TRAINDATABASE_H
#include <QtCore>
class T3TrainDatabase: public QObject {
	Q_OBJECT
  private:

public:
	T3TrainDatabase(QObject *parent = nullptr);
};


#endif // T3TRAINDATABASE_H


inline T3TrainDatabase::T3TrainDatabase(QObject *parent) : QObject(parent)
{}

