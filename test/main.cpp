#include <QCoreApplication>
#include <QDebug>

#include "covector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CoVector<int> vector;
    vector.insert(0, 3);

    qDebug() << vector[0];

    return a.exec();
}
