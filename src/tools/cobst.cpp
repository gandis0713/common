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

namespace NsBST
{
void insert(CoBSTNode *&pBSTNode,
            Gint nValue)
{
    if(pBSTNode == NULL)
    {
        pBSTNode = new (std::nothrow) CoBSTNode;
        pBSTNode->m_nValue = nValue;
        return;
    }

    if(pBSTNode->m_nValue > nValue)
    {
        insert(pBSTNode->m_pLeftNode, nValue);
    }
    else
    {
        insert(pBSTNode->m_pRightNode, nValue);
    }
}

/**
 * @brief Left -> Root -> Right
 */
void PrintInOrder(CoBSTNode *pBSTNode)
{
    if(pBSTNode == NULL)
        return;

    PrintInOrder(pBSTNode->m_pLeftNode);
    qDebug() << __FUNCTION__ << pBSTNode->m_nValue;
    PrintInOrder(pBSTNode->m_pRightNode);
}

/**
 * @brief Root -> Left -> Right
 */
void PrintPreOrder(CoBSTNode *pBSTNode)
{
    if(pBSTNode == NULL)
        return;

    qDebug() << __FUNCTION__ << pBSTNode->m_nValue;
    PrintPreOrder(pBSTNode->m_pLeftNode);
    PrintPreOrder(pBSTNode->m_pRightNode);
}

/**
 * @brief Left -> Right -> Root
 */
void PrintPostOrder(CoBSTNode *pBSTNode)
{
    if(pBSTNode == NULL)
        return;

    PrintPostOrder(pBSTNode->m_pLeftNode);
    PrintPostOrder(pBSTNode->m_pRightNode);
    qDebug() << __FUNCTION__ << pBSTNode->m_nValue;
}


}
