#ifndef COLIST_H
#define COLIST_H

#include "corelib.h"
#include "codefine.h"

#include <algorithm>

template <typename Type>
class CoVector
{
public:
    explicit CoVector(Gint nBufferSize = 100);
    ~CoVector();

    Gint size();
    Gbool push_back(Type value);
    Gbool insert(Gint nIndex, Type value);
    Gbool remove(Gint nIndex);
    Type& operator [](Gint nIndex);

private:
    Type* m_pData;
    Gint m_nBufferSize;
    Gint m_nLength;

private:
    Gbool increaseBuffer();
};

template <typename Type>
CoVector<Type>::CoVector(Gint nBufferSize)
    : m_nBufferSize(nBufferSize)
    , m_nLength(0)
{
    m_pData = new Type[m_nBufferSize];
}

template <typename Type>
CoVector<Type>::~CoVector()
{
    delete[] m_pData;
}

template <typename Type>
Gint
CoVector<Type>::size()
{
    return m_nLength;
}

template <typename Type>
Gbool
CoVector<Type>::push_back(Type value)
{
    if(m_nLength >= m_nBufferSize)
    {
        if(!increaseBuffer())
            return false;
    }

    m_pData[m_nLength++] = value;

    return true;
}

template <typename Type>
Gbool
CoVector<Type>::insert(Gint nIndex, Type value)
{
    if(m_nLength >= m_nBufferSize)
    {
        if(!increaseBuffer())
            return false;
    }

    memmove(m_pData + nIndex + 1, m_pData + nIndex, (m_nLength - nIndex) * sizeof( Type));
    m_pData[nIndex] = value;
    m_nLength++;

    return true;
}

template <typename Type>
Gbool
CoVector<Type>::remove(Gint nIndex)
{
    memmove(m_pData + nIndex, m_pData + nIndex + 1, (--m_nLength - nIndex) * sizeof( Type));
    return true;
}

template <typename Type>
Type&
CoVector<Type>::operator [](Gint nIndex)
{
    return m_pData[nIndex];
}

template <typename Type>
Gbool
CoVector<Type>::increaseBuffer()
{
    Gint nNewBufferSize = m_nBufferSize + 100;
    Type *pData = new Type[nNewBufferSize];
    std::copy_n(m_pData, m_nBufferSize, pData);

    delete[] m_pData;

    m_pData = pData;
    if(!m_pData)
        return false;

    m_nBufferSize = nNewBufferSize;
    return true;
}


#endif // COLIST_H
