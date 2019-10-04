#include "cobst.h"
#include <QDebug>

CoBSTNode::CoBSTNode()
    : m_pLeftNode(NULL)
    , m_pRightNode(NULL)
    , m_nValue(0)
{
    // do nothing.
}

CoBSTNode::~CoBSTNode()
{
    // do nothing.
}

namespace BST
{
void insert(CoBSTNode *&pBSTNode,
            Gint nValue)
{
    qDebug() << "value : " << nValue;
    if(pBSTNode == NULL)
    {
        qDebug() << __FUNCTION__ << "New";
        pBSTNode = new (std::nothrow) CoBSTNode;
        pBSTNode->m_nValue = nValue;
    }
    else
    {
        if(pBSTNode->m_nValue > nValue)
        {
            qDebug() << __FUNCTION__ << "Left";
            insert(pBSTNode->m_pLeftNode, nValue);
        }
        else
        {
            qDebug() << __FUNCTION__ << "Right";
            insert(pBSTNode->m_pRightNode, nValue);
        }
    }
}

void preorderPrint(CoBSTNode *pBSTNode)
{
    if(pBSTNode == NULL) return;
    qDebug() << pBSTNode->m_nValue;
    preorderPrint(pBSTNode->m_pRightNode);
    preorderPrint(pBSTNode->m_pLeftNode);
}
}
