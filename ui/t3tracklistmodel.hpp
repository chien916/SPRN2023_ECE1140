#ifndef T3TRACKLISTMODEL_H
#define T3TRACKLISTMODEL_H

#include <QtCore>
class T3TrackListModel: public QAbstractListModel {
  private:

  public:
	int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE Q_DECL_FINAL;
	QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE Q_DECL_FINAL;
	QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE Q_DECL_FINAL;

  public Q_SLOTS:
	void put(const QString request);
	void get(const QString request, QVariant* respond);
};

inline int T3TrackListModel::rowCount(const QModelIndex &parent) const {
	//TO-DO
	return 0;
}

inline QVariant T3TrackListModel::data(const QModelIndex &index, int role) const {
	//TO-DO
	return 0;
}

inline QHash<int, QByteArray> T3TrackListModel::roleNames() const {
	//TO-DO
	return QHash<int, QByteArray>();
}

inline void T3TrackListModel::put(const QString request) {
	//TO-DO
}

inline void T3TrackListModel::get(const QString request, QVariant *respond) {
	//TO-DO
}
#endif // T3TRACKLISTMODEL_H
