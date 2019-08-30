#ifndef CORELIB_H
#define CORELIB_H

#include <QtCore/qglobal.h>

#if defined(CORELIB_LIBRARY)
#  define CORELIB Q_DECL_EXPORT
#else
#  define CORELIB Q_DECL_IMPORT
#endif

#endif // CORELIB_H
