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

namespace BST
{
void CORELIB insert(CoBSTNode *&pBSTNode,
            Gint nValue);

void CORELIB preorderPrint(CoBSTNode *pBSTNode);
}

#endif // COBST_H
