#ifndef COLIST_H
#define COLIST_H

#include "corelib.h"
#include "codefine.h"

#include <algorithm>

template <typename T>
class CoVector
{
public:
    explicit CoVector(Gint nBufferSize = 100);
    ~CoVector();

    Gint size();
    Gbool push_back(T value);
    Gbool insert(Gint nIndex, T value);
    Gbool remove(Gint nIndex);
    T& operator [](Gint nIndex);

private:
    T* m_pData;
    Gint m_nBufferSize;
    Gint m_nLength;

private:
    Gbool increaseBuffer();
};

template <typename T>
CoVector<T>::CoVector(Gint nBufferSize)
    : m_nBufferSize(nBufferSize)
    , m_nLength(0)
{
    m_pData = new T[m_nBufferSize];
}

template <typename T>
CoVector<T>::~CoVector()
{
    delete[] m_pData;
}

template <typename T>
Gint CoVector<T>::size()
{
    return m_nLength;
}

template <typename T>
Gbool CoVector<T>::push_back(T value)
{
    if(m_nLength >= m_nBufferSize)
    {
        if(!increaseBuffer())
            return false;
    }

    m_pData[m_nLength++] = value;

    return true;
}

template <typename T>
Gbool CoVector<T>::insert(Gint nIndex, T value)
{
    if(m_nLength >= m_nBufferSize)
    {
        if(!increaseBuffer())
            return false;
    }

    memmove(m_pData + nIndex + 1, m_pData + nIndex, (m_nLength - nIndex) * sizeof(T));
    m_pData[nIndex] = value;
    m_nLength++;

    return true;
}

template <typename T>
Gbool CoVector<T>::remove(Gint nIndex)
{
    memmove(m_pData + nIndex, m_pData + nIndex + 1, (--m_nLength - nIndex) * sizeof(T));
    return true;
}

template <typename T>
T& CoVector<T>::operator [](Gint nIndex)
{
    return m_pData[nIndex];
}

template <typename T>
Gbool CoVector<T>::increaseBuffer()
{
    Gint nNewBufferSize = m_nBufferSize + 100;
    T *pData = new T[nNewBufferSize];
    std::copy_n(m_pData, m_nBufferSize, pData);

    delete[] m_pData;

    m_pData = pData;
    if(!m_pData)
        return false;

    m_nBufferSize = nNewBufferSize;
    return true;
}


#endif // COLIST_H
