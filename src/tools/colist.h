#ifndef COLIST_H
#define COLIST_H

#include "corelib.h"
#include "codefine.h"

template <typename Type>
class CoList
{

public:
    explicit CoList();
    virtual ~CoList();

    void push_back(Type data);
    Gbool insert(Gint nIndex, Type data);

    Type& operator [](Gint nIndex);

protected:
    class node
    {
    public:
        Type data;
        node *pNextNode;
        node *pPreNode;
    };

private:
    node *m_pHeadNode;
    node *m_pTailNode;
};

template <typename Type>
CoList<Type>::CoList()
    : m_pHeadNode(NULL)
    , m_pTailNode(NULL)
{

}

template <typename Type>
CoList<Type>::~CoList()
{

}

template <typename Type>
void
CoList<Type>::push_back(Type data)
{
    node *pNode = new node();
    pNode->data = data;
    pNode->pNextNode = NULL;
    pNode->pPreNode = NULL;

    if(m_pHeadNode == NULL)
    {
        m_pHeadNode = pNode;
        m_pTailNode = pNode;
    }
    else
    {
        if(m_pHeadNode == m_pTailNode)
        {
            m_pTailNode = pNode;
            m_pHeadNode->pNextNode = m_pTailNode;
            m_pTailNode->pPreNode = m_pHeadNode;
        }
        else
        {
            m_pTailNode->pNextNode = pNode;
            pNode->pPreNode = m_pTailNode;
            m_pTailNode = pNode;
        }
    }
}

template <typename Type>
Gbool
CoList<Type>::insert(Gint nIndex, Type data)
{
    node *pNode = new node();
    pNode->data = data;
    pNode->pNextNode = NULL;
    pNode->pPreNode = NULL;

    if(m_pHeadNode == NULL)
    {
        push_back(data);
        return true;
    }

    node *pCur = m_pHeadNode;
    Gint nCount = 0;
    while(nCount < nIndex)
    {
        pCur = pCur->pNextNode;
        if(pCur == NULL)
            return false;

        nCount++;
    }

    if(nIndex == 0)
    {
        pNode->pNextNode = pCur;
        pNode->pPreNode = NULL;
        pCur->pPreNode = pNode;

        m_pHeadNode = pNode;
    }
    else
    {
        pNode->pNextNode = pCur;
        pNode->pPreNode = pCur->pPreNode;
        pNode->pPreNode->pNextNode = pNode;
        pCur->pPreNode = pNode;
    }

    return true;
}

template <typename Type>
Type& CoList<Type>::operator [](Gint nIndex)
{
    node *pCur = m_pHeadNode;
    Gint nCount = 0;
    while(nCount < nIndex)
    {
        pCur = pCur->pNextNode;
        nCount++;
    }

    return pCur->data;
}

#endif // COLIST_H
