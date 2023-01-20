#ifndef YHTRACKLISTMODEL_HPP
#define YHTRACKLISTMODEL_HPP

#include <QtCore>
class YhTrackListModel: public QAbstractListModel {
  private:

  public:
	int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE Q_DECL_FINAL;
	QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE Q_DECL_FINAL;
	QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE Q_DECL_FINAL;
};
#endif // YHTRACKLISTMODEL_HPP
