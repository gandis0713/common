#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>

#include "costring.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])

{
    QCoreApplication a(argc, argv);

    QElapsedTimer timer;

    timer.start();

    CoString str("Hello world!");

    cout << str.length() << endl;
    cout << str.capacity() << endl;
    cout << str.string() << endl;

    return a.exec();
}
