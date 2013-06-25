#include "openwidget.h"

OpenWidget::OpenWidget(QWidget *parent) :
    QGLWidget(parent)
{
    xRot = 0;
    yRot = 0;
    setMouseTracking(true);
    this->setCursor(QCursor(Qt::BlankCursor));
}

void OpenWidget::initializeGL() {
    qglClearColor(Qt::gray);
}

void OpenWidget::resizeGL(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)w, (GLint)h);
    glOrtho(-10, 10, -10, 10, -10, 10);
    setPos();
}

void OpenWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

//    glTranslatef(0, 0, 1);

    double r[100][100][3];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) {
            r[i][j][0] = i * step;
            r[i][j][1] = j * step;
            r[i][j][2] = sin(i * step) + sin(j * step);
        }

    qglColor(Qt::green);
    glBegin(GL_LINES);
        for (int i = 0; i < 99; i++)
            for (int j = 0; j < 99; j++) {
                glVertex3f(r[i][j][0], r[i][j][1], r[i][j][2]);
                glVertex3f(r[i + 1][j][0], r[i + 1][j][1], r[i + 1][j][2]);

                glVertex3f(r[i][j][0], r[i][j][1], r[i][j][2]);
                glVertex3f(r[i][j + 1][0], r[i][j + 1][1], r[i][j + 1][2]);
            }
    glEnd();
}

void OpenWidget::keyPressEvent(QKeyEvent *ev) {
    if (ev->key() == Qt::Key_Escape)
        this->close();
    else if (ev->key() == Qt::Key_Z)
        if (isFullScreen())
            showNormal();
        else
            showFullScreen();
    else if (ev->key() == Qt::Key_Left)
        yRot -= 5;
    else if (ev->key() == Qt::Key_Right)
        yRot += 5;
    else if (ev->key() == Qt::Key_Down)
        xRot -= 5;
    else if (ev->key() == Qt::Key_Up)
        xRot += 5;

    ev->accept();
    repaint();
}

void OpenWidget::mouseMoveEvent(QMouseEvent *e) {
    if (!isFullScreen())
        return;

    xRot += (this->width() / 2 - e->x()) * 0.2;
    yRot += (this->height() / 2 - e->y()) * 0.2;
    setPos();
    repaint();
}

void OpenWidget::setPos() {
    QCursor::setPos(this->width() / 2, this->height() / 2);
}
