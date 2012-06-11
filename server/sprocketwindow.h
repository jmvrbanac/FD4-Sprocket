#ifndef SPROCKETWINDOW_H
#define SPROCKETWINDOW_H

#include <QMainWindow>
#include "sprocketserver.h"

namespace Ui {
class SprocketWindow;
}

class SprocketWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SprocketWindow(QWidget *parent = 0);
    ~SprocketWindow();
    
private slots:
    void on_startButton_clicked();

private:
    Ui::SprocketWindow *ui;
    SprocketServer *server;
};

#endif // SPROCKETWINDOW_H
