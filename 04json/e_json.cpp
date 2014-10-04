/*
 * $Id: e_json.cpp,v 0.1 2014/08/29 11:11:11 $
 *
 * Author: Heesung Oh <afewhee@hotmail.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See COPYING for details.
 *
 */

#if defined(_MSC_VER)
  #pragma warning(disable:4996)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <errno.h>

#include "json/json_config.h"
#include "json/json_debug.h"
#include "json/json_printbuf.h"
#include "json/json_linkhash.h"
#include "json/json_arraylist.h"
#include "json/json_inttypes.h"
#include "json/json_object.h"
#include "json/json_tokener.h"
#include "c_object_private.h"
#include "json/json_util.h"
#include "c_math_compat.h"


json_type jsoncpp_t(struct json_object *jso)
{
	return json_object_get_type(jso);
}


json_object* jsoncpp_root(const char* str_buf)
{
	json_object* root = json_tokener_parse(str_buf);
	return root;
}


int jsoncpp_release(json_object** jso)
{
	if(NULL== jso || *jso == NULL)
		return 0;

	json_object_put(*jso);
	*jso = NULL;
	return 0;
}


json_object* jsoncpp_o(json_object* jso
						, const char* k0, const char* k1
						, const char* k2, const char* k3
						, const char* k4, const char* k5
						, const char* k6, const char* k7
						, const char* k8, const char* k9
						, const char* ka, const char* kb
						)
{

	json_object* obj = NULL;
	json_object* prn = NULL;

	prn = jso;	json_object_object_get_ex(prn, k0, &obj);
	if(NULL == k1)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, k1, &obj);
	if(NULL == k2)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, k2, &obj);
	if(NULL == k3)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, k3, &obj);
	if(NULL == k4)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, k4, &obj);
	if(NULL == k5)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, k5, &obj);
	if(NULL == k6)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, k6, &obj);
	if(NULL == k7)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, k7, &obj);
	if(NULL == k8)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, k8, &obj);
	if(NULL == k9)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, k9, &obj);
	if(NULL == ka)
		goto END;

	prn = obj;	json_object_object_get_ex(prn, ka, &obj);
	if(NULL == kb)
		goto END;


	prn = obj;	json_object_object_get_ex(prn, kb, &obj);

END:
	return obj;
}


int jsoncpp_b(json_object* jso, const char* key)
{
	int          ret = 0;
	json_object* val = NULL;
	json_object_object_get_ex(jso, key, &val);
	if(NULL == val)
		return 0;
	
	ret = (int)json_object_get_boolean(val);
	return ret;
}

int jsoncpp_b(json_object* jso
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	int          ret = 0;
	json_object* obj = jsoncpp_o(jso,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	if(NULL == obj)
		return 0;
	
	ret = (int)json_object_get_boolean(obj);
	return ret;
}


int jsoncpp_b(json_object* jso, int idx
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	int          ret = 0;
	json_object* obj = json_object_array_get_idx(jso, idx);

	if(NULL == obj)
		return 0;


	ret  = jsoncpp_b(obj,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	return ret;
}



int jsoncpp_i   (json_object* jso, const char* key)
{
	int          ret = 0;
	json_object* val = NULL;
	json_object_object_get_ex(jso, key, &val);
	if(NULL == val)
		return 0;
	
	ret = (int)json_object_get_int(val);
	return ret;
}

int jsoncpp_i(json_object* jso
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	int          ret = 0;
	json_object* obj = jsoncpp_o(jso,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	if(NULL == obj)
		return 0;
	
	ret = (int)json_object_get_int(obj);
	return ret;
}


int jsoncpp_i(json_object* jso, int idx
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	int          ret = 0;
	json_object* obj = json_object_array_get_idx(jso, idx);

	if(NULL == obj)
		return 0;


	ret  = jsoncpp_i(obj,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	return ret;
}


double jsoncpp_d(json_object* jso, const char* key)
{
	double       ret = 0;
	json_object* val = NULL;
	json_object_object_get_ex(jso, key, &val);
	if(NULL == val)
		return 0;
	
	ret = (double)json_object_get_double(val);
	return ret;
}


double jsoncpp_d(json_object* jso
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	double       ret = 0;
	json_object* obj = jsoncpp_o(jso,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	if(NULL == obj)
		return 0;
	
	ret = (double)json_object_get_double(obj);
	return ret;
}


double jsoncpp_d(json_object* jso, int idx
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	double       ret = 0;
	json_object* obj = json_object_array_get_idx(jso, idx);

	if(NULL == obj)
		return 0;


	ret  = jsoncpp_d(obj,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	return ret;
}



float jsoncpp_f(json_object* jso, const char* key)
{
	float  ret = (float)jsoncpp_d(jso, key);
	return ret;
}


float jsoncpp_f(json_object* jso
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	float  ret = (float)jsoncpp_d(jso,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	return ret;
}


float jsoncpp_f(json_object* jso, int idx
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	float  ret = (float)jsoncpp_d(jso,idx,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	return ret;
}



const char* jsoncpp_s(json_object* jso, const char* key)
{
	const char * ret = 0;
	json_object* val = NULL;
	json_object_object_get_ex(jso, key, &val);
	if(NULL == val)
		return 0;
	
	ret = (const char *)json_object_get_string(val);
	return ret;
}


const char* jsoncpp_s(json_object* jso
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	const char * ret = 0;
	json_object* obj = jsoncpp_o(jso,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	if(NULL == obj)
		return 0;
	
	ret = (const char *)json_object_get_string(obj);
	return ret;
}


const char* jsoncpp_s(json_object* jso, int idx
			, const char* k0, const char* k1
			, const char* k2, const char* k3
			, const char* k4, const char* k5
			, const char* k6, const char* k7
			, const char* k8, const char* k9
			, const char* ka, const char* kb
			)
{
	const char * ret = 0;
	json_object* obj = json_object_array_get_idx(jso, idx);

	if(NULL == obj)
		return 0;


	ret  = jsoncpp_s(obj,k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,ka,kb);
	return ret;
}


