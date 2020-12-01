#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}

int main1(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::vector<uint> rowCounts;
    rowCounts.push_back(5);
    rowCounts.push_back(2);
    rowCounts.push_back(1);

    std::sort(rowCounts.begin(),rowCounts.end());

    uint r = rowCounts.back();
    qDebug()<<r<<endl;
    MainWindow w;
    w.show();
    return a.exec();
}
