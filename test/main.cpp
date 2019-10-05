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

    NsBST::insert(pBSTNode, 3);
    NsBST::insert(pBSTNode, 1);
    NsBST::insert(pBSTNode, 2);
    NsBST::insert(pBSTNode, 4);
    NsBST::insert(pBSTNode, 5);
    NsBST::insert(pBSTNode, 6);

    NsBST::PrintPostOrder(pBSTNode);
    NsBST::PrintPreOrder(pBSTNode);
    NsBST::PrintInOrder(pBSTNode); //1 2 3 4 5 6

    return a.exec();
}
