#ifndef T3CTCOFFICE_H
#define T3CTCOFFICE_H
#include <QtCore>
class T3CtcOffice: public QObject {
	Q_OBJECT
  public:
	explicit T3CtcOffice(QObject *parent = nullptr);



  Q_SIGNALS:

  public Q_SLOTS:
};
#endif // T3CTCOFFICE_H


inline T3CtcOffice::T3CtcOffice(QObject *parent) : QObject(parent)
{}

