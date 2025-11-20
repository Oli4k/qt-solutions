#ifndef QTTREEPROPERTYBROWSER_P_H
#define QTTREEPROPERTYBROWSER_P_H

#include <QTreeWidget>
#include <QItemDelegate>

class QtTreePropertyBrowserPrivate;

// Nested classes that need MOC processing
class QtPropertyEditorView : public QTreeWidget
{
    Q_OBJECT
public:
    QtPropertyEditorView(QWidget *parent = 0);
    void setEditorPrivate(QtTreePropertyBrowserPrivate *editorPrivate);
    QTreeWidgetItem *indexToItem(const QModelIndex &index) const;

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void drawRow(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QtTreePropertyBrowserPrivate *m_editorPrivate;
};

class QtPropertyEditorDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    QtPropertyEditorDelegate(QObject *parent = 0);
    void setEditorPrivate(QtTreePropertyBrowserPrivate *editorPrivate);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setModelData(QWidget *, QAbstractItemModel *, const QModelIndex &) const {}
    void setEditorData(QWidget *, const QModelIndex &) const {}
    bool eventFilter(QObject *object, QEvent *event);
    void closeEditor(QtProperty *property);
    QTreeWidgetItem *editedItem() const { return m_editedItem; }

protected:
    void drawDecoration(QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect, const QPixmap &pixmap) const;
    void drawDisplay(QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect, const QString &text) const;

private slots:
    void slotEditorDestroyed(QObject *object);

private:
    int indentation(const QModelIndex &index) const;
    typedef QMap<QWidget *, QtProperty *> EditorToPropertyMap;
    mutable EditorToPropertyMap m_editorToProperty;
    typedef QMap<QtProperty *, QWidget *> PropertyToEditorMap;
    mutable PropertyToEditorMap m_propertyToEditor;
    QtTreePropertyBrowserPrivate *m_editorPrivate;
    mutable QTreeWidgetItem *m_editedItem;
    mutable QWidget *m_editedWidget;
    mutable bool m_disablePainting;
};

#endif

