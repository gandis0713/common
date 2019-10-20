#ifndef COSTRING_H
#define COSTRING_H

#include "codefine.h"

#include "corelib.h"

class CORELIB CoString
{
public:
    explicit CoString(const Gchar *str);
    virtual ~CoString();

    Gint length();
    Gint capacity();

    const Gchar* string();

private:
    Gchar* m_pString;
    Gint   m_nLength;
    Gint   m_nCapacity;
};

#endif // COSTRING_H
