#include "costring.h"

CoString::CoString(const Gchar *str)
    : m_pString(NULL)
    , m_nLength(0)
    , m_nCapacity(0)
{
    while(str[m_nLength++]){} // increase length.

    m_nCapacity = m_nLength;

    m_pString = new Gchar[m_nLength];

    for(Gint nIndex = 0; nIndex < m_nLength; nIndex++)
    {
        m_pString[nIndex] = str[nIndex];
    }
}

CoString::~CoString()
{
    delete[] m_pString;
}

Gint CoString::length()
{
    return m_nLength;
}

Gint CoString::capacity()
{
    return m_nCapacity;
}

const Gchar* CoString::string()
{
    return &m_pString[0];
}
