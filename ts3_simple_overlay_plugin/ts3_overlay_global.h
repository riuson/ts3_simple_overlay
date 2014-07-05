#ifndef TS3_OVERLAY_GLOBAL_H
#define TS3_OVERLAY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TS3_OVERLAY_LIBRARY)
#  define TS3_LIB_EXPORT Q_DECL_EXPORT
#else
#  define TS3_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // TS3_OVERLAY_GLOBAL_H
