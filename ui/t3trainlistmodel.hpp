#ifndef T3TRAINLISTMODEL_H
#define T3TRAINLISTMODEL_H
#include <QtCore>
class T3TrainListModel: public QAbstractListModel {
  private:

  public:
	int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE Q_DECL_FINAL;
	QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE Q_DECL_FINAL;
	QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE Q_DECL_FINAL;
  public Q_SLOTS:
	void post(const QString request);
	void put(const QString request);
	void get(const QString request, QVariant* respond);
};

inline int T3TrainListModel::rowCount(const QModelIndex &parent) const {
	//TO-DO
	return 0;
}

inline QVariant T3TrainListModel::data(const QModelIndex &index, int role) const {
	//TO-DO
	return 0;
}

inline QHash<int, QByteArray> T3TrainListModel::roleNames() const {
	//TO-DO
	return QHash<int, QByteArray>();
}

inline void T3TrainListModel::post(const QString request) {
	//TO-DO
}

inline void T3TrainListModel::put(const QString request) {
	//TO-DO
}

inline void T3TrainListModel::get(const QString request, QVariant *respond) {
	//TO-DO
}
#endif // T3TRAINLISTMODEL_H
