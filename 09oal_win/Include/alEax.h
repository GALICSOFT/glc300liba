#ifndef _AL_EAX_H_
#define _AL_EAX_H_

#undef ALAPI
#undef ALCAPI
#undef ALAPIENTRY
#undef ALCAPIENTRY

#define ALAPI
#define ALCAPI
#define ALAPIENTRY
#define ALCAPIENTRY


#include "./ALwin/altypes.h"

#ifdef __cplusplus
extern "C" {
#endif

ALboolean		CheckEAXSupport(ALubyte *szEAXName);
ALAPI ALenum    ALAPIENTRY EAXGet(const struct _GUID *propertySetID,ALuint property,ALuint source,ALvoid *value,ALuint size);
ALAPI ALenum    ALAPIENTRY EAXSet(const struct _GUID *propertySetID,ALuint property,ALuint source,ALvoid *value,ALuint size);

#ifdef __cplusplus
}
#endif

#endif