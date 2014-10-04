#ifndef _AL_ERROR_H_
#define _AL_ERROR_H_

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

ALAPI ALenum	ALAPIENTRY alGetError(ALvoid);
ALAPI ALvoid	ALAPIENTRY alSetError(ALenum errorCode);

#ifdef __cplusplus
}
#endif

#endif