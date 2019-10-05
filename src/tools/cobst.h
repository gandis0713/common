#ifndef COBST_H
#define COBST_H

#include "codefine.h"
#include "corelib.h"

class CORELIB CoBSTNode
{
public:
    explicit CoBSTNode();
    virtual ~CoBSTNode();

    Gint m_nValue;
    CoBSTNode *m_pLeftNode;
    CoBSTNode *m_pRightNode;
};

namespace NsBST
{
CORELIB CoBSTNode* search(CoBSTNode *pBSTNode,
                          Gint nValue);
CORELIB void insert(CoBSTNode *&pBSTNode,
                    Gint nValue);

CORELIB void PrintPostOrder(CoBSTNode *pBSTNode);
CORELIB void PrintPreOrder(CoBSTNode *pBSTNode);
CORELIB void PrintInOrder(CoBSTNode *pBSTNode);
}

#endif // COBST_H
