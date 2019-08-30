#ifndef COLIST_H
#define COLIST_H

#include "corelib.h"
#include "codefine.h"

template <typename T>
class CORELIB CoList
{
public:
    explicit CoList(Gint nBufferSize = 100);
    ~CoList();

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

#endif // COLIST_H
