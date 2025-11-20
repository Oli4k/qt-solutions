#ifndef QTPROPERTYMANAGER_P_H
#define QTPROPERTYMANAGER_P_H

#include <QObject>
#include <QSizePolicy>

// Nested class that needs MOC processing
class QtMetaEnumWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QSizePolicy::Policy policy READ policy)
public:
    QSizePolicy::Policy policy() const { return QSizePolicy::Ignored; }
private:
    QtMetaEnumWrapper(QObject *parent = 0) : QObject(parent) {}
};

#endif

