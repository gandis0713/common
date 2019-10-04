#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>

#include "cobst.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QElapsedTimer timer;

    timer.start();

    CoBSTNode *pBSTNode = NULL;

    BST::insert(pBSTNode, 1);
    BST::insert(pBSTNode, 2);
    BST::insert(pBSTNode, 10);
    BST::insert(pBSTNode, 12);
    BST::insert(pBSTNode, 6);
    BST::insert(pBSTNode, 14);
    BST::insert(pBSTNode, 100);

    BST::preorderPrint(pBSTNode);

    return a.exec();
}
