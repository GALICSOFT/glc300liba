#ifndef _AL_MAIN_H_
#define _AL_MAIN_H_

#define AL_MAX_CHANNELS		4
#define AL_MAX_SOURCES		32

#undef ALAPI
#undef ALCAPI
#undef ALAPIENTRY
#undef ALCAPIENTRY

#define ALAPI
#define ALCAPI
#define ALAPIENTRY
#define ALCAPIENTRY


#include "./ALwin/altypes.h"
#include "./ALwin/alctypes.h"
#include "./ALwin/alu.h"
#include "alBuffer.h"
#include "alError.h"
#include "alExtension.h"
#include "alListener.h"
#include "alSource.h"
#include "alState.h"

#include <windows.h>
#include <dsound.h>

#define NUMWAVEBUFFERS	4

typedef struct ALCdevice_struct 
  {
 	ALenum		LastError;
 	ALboolean	InUse;
 	ALboolean	Valid;

	ALuint		Frequency;
	ALuint		Channels;
	ALenum		Format;

	ALint		MajorVersion;
	ALint		MinorVersion;

	ALubyte		szDeviceName[256];

	// Maximum number of sources that can be created
	ALuint		MaxNoOfSources;

	// Set to DSBCAPS_LOCHARDWARE or DSBCAPS_LOCSOFTWARE based on the number of voices supported
	// by the hardware (more than 15 required for Hardware support).
	ALuint		CreationFlag;

	//DirectSound
	LPDIRECTSOUND DShandle;
	LPDIRECTSOUNDBUFFER DSpbuffer;
	LPDIRECTSOUNDBUFFER DSsbuffer;
	LPDIRECTSOUND3DLISTENER DS3dlistener;

	//waveOut
	HWAVEOUT	handle;
	WAVEHDR		buffer[NUMWAVEBUFFERS];

	//mmTimer
	MMRESULT	timer;
  } ALCdevice;
  typedef struct ALCcontext_struct 
  {
	ALlistener	Listener;
	
	ALsource *	Source;
	ALuint		SourceCount;
	
	ALenum		LastError;
	ALboolean	InUse;
	ALboolean	Valid;

	ALuint		Frequency;
	ALuint		Channels;
	ALenum		Format;

	ALenum		DistanceModel;

	ALfloat		DopplerFactor;
	ALfloat		DopplerVelocity;

	ALCdevice * Device;

	struct ALCcontext_struct *previous;
	struct ALCcontext_struct *next;
  }  ALCcontext;

#endif

ALCvoid alcUpdateContext(ALCcontext *context,ALuint type,ALuint name);
ALint LinearGainToDB(float flGain);