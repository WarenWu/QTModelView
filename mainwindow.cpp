#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_tableModel = new CTableModel();
    m_tableDelegate = new CTableDelegate();
    ui->tableView->setModel(m_tableModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setItemDelegate(m_tableDelegate);
//    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Interactive);
//    ui->tableView->horizontalHeader()->resizeSection(0,100);
};

MainWindow::~MainWindow()
{
    delete ui;
}
