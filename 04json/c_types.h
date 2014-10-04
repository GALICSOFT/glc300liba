
#ifndef _JSON_TYPES_H
#define _JSON_TYPES_H

/* make it easy on the folks that want to compile the libs with a
   different malloc than stdlib */
#define _json_malloc  malloc
#define _json_calloc  calloc
#define _json_realloc realloc
#define _json_free    free

#if defined(_MSC_VER) 

#  if defined(__CYGWIN__)
#    include <stdint.h>
     typedef uint8_t  json_uint8_t;
     typedef int8_t   json_int8_t;
     typedef int16_t  json_int16_t;
     typedef uint16_t json_uint16_t;
     typedef int32_t  json_int32_t;
     typedef uint32_t json_uint32_t;
     typedef int64_t  json_int64_t;
     typedef uint64_t json_uint64_t;
#  else
     /* MSVC/Borland */
     typedef __int64          json_int64_t;
	 typedef unsigned __int64 json_uint64_t;
     typedef __int32          json_int32_t;
     typedef unsigned __int32 json_uint32_t;
     typedef __int16          json_int16_t;
     typedef unsigned __int16 json_uint16_t;
	 typedef unsigned __int8  json_uint8_t;
#  endif

#elif defined(__MACOS__)

#  include <sys/types.h>
   typedef SInt8    json_int8_t;
   typedef UInt8    json_uint8_t;
   typedef SInt16   json_int16_t;
   typedef UInt16   json_uint16_t;
   typedef SInt32   json_int32_t;
   typedef UInt32   json_uint32_t;
   typedef SInt64   json_int64_t;

#elif (defined(__APPLE__) && defined(__MACH__)) /* MacOS X Framework build */

#  include <inttypes.h>
   typedef int8_t   json_int8_t;
   typedef int16_t  json_int16_t;
   typedef uint16_t json_uint16_t;
   typedef int32_t  json_int32_t;
   typedef uint32_t json_uint32_t;
   typedef int64_t  json_int64_t;

#else

typedef signed char         json_int8_t;
typedef unsigned char       json_uint8_t;
typedef short               json_int16_t;
typedef unsigned short      json_uint16_t;
typedef int                 json_int32_t;
typedef unsigned int        json_uint32_t;
typedef long long           json_int64_t;
typedef unsigned long long  json_uint64_t;

#endif

#endif


