#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ctablemodel.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CTableModel* m_tableModel;
};

#endif // MAINWINDOW_H
