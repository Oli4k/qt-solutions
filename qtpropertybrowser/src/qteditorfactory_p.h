#ifndef QTEDITORFACTORY_P_H
#define QTEDITORFACTORY_P_H

#include <QWidget>
#include <QLineEdit>
#include <QChar>
#include <QLabel>
#include <QToolButton>
#include <QColor>
#include <QFont>

// Nested classes that need MOC processing
class QtCharEdit : public QWidget
{
    Q_OBJECT
public:
    QtCharEdit(QWidget *parent = 0);

    QChar value() const;
    bool eventFilter(QObject *o, QEvent *e);
public Q_SLOTS:
    void setValue(const QChar &value);
Q_SIGNALS:
    void valueChanged(const QChar &value);
protected:
    void focusInEvent(QFocusEvent *e);
    void focusOutEvent(QFocusEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *);
    bool event(QEvent *e);
private slots:
    void slotClearChar();
private:
    void handleKeyEvent(QKeyEvent *e);

    QChar m_value;
    QLineEdit *m_lineEdit;
};

class QtColorEditWidget : public QWidget {
    Q_OBJECT

public:
    QtColorEditWidget(QWidget *parent);

    bool eventFilter(QObject *obj, QEvent *ev);

public Q_SLOTS:
    void setValue(const QColor &value);

Q_SIGNALS:
    void valueChanged(const QColor &value);

protected:
    void paintEvent(QPaintEvent *);

private Q_SLOTS:
    void buttonClicked();

private:
    QColor m_color;
    QLabel *m_pixmapLabel;
    QLabel *m_label;
    QToolButton *m_button;
};

class QtFontEditWidget : public QWidget {
    Q_OBJECT

public:
    QtFontEditWidget(QWidget *parent);

    bool eventFilter(QObject *obj, QEvent *ev);

public Q_SLOTS:
    void setValue(const QFont &value);

Q_SIGNALS:
    void valueChanged(const QFont &value);

protected:
    void paintEvent(QPaintEvent *);

private Q_SLOTS:
    void buttonClicked();

private:
    void updateButtonText();

    QFont m_font;
    QLabel *m_pixmapLabel;
    QLabel *m_label;
    QToolButton *m_button;
};

#endif

