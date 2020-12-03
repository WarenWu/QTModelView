#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cplatinfomodel.h"
#include "cplatinfodelegate.h"

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
    CTableDelegate* m_tableDelegate;
};

#endif // MAINWINDOW_H
