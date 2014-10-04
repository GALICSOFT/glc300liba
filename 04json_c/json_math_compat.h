#ifndef __math_compat_h
#define __math_compat_h

#if defined(_MSC_VER)
#include <float.h>
#define isnan(x) _isnan(x)

#include <float.h>
#define isinf(x) (!_finite(x))

#endif


//#ifndef HAVE_DECL_NAN
//#error This platform does not have nan()
//#endif
//

//#ifndef HAVE_DECL_INFINITY
//#error This platform does not have INFINITY
//#endif

#endif
