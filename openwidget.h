#ifndef OPENWIDGET_H
#define OPENWIDGET_H

#include <QGLWidget>
#include <GL/glu.h>
#include <math.h>
#include <QMouseEvent>
#include <QKeyEvent>

class OpenWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenWidget(QWidget *parent = 0);
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mouseMoveEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
private:
    double xRot, yRot;
    double step;
    void setPos();
signals:
    
public slots:
    
};

#endif // OPENWIDGET_H
