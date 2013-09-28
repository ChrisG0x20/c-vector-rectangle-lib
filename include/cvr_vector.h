//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef CVR_VECTOR_H
#define CVR_VECTOR_H

#if defined _MSC_VER && _MSC_VER <= 1700
#pragma warning( push )
#pragma warning( disable : 4201 ) // This warning is out-of-date for C99.
#endif

typedef int bool;
#define true 1
#define false 0

#include "cvr_vec2f.h"
#include "cvr_vec2.h"
#include "cvr_vec2i.h"
#include "cvr_vec2ui.h"

#include "cvr_vec3f.h"
#include "cvr_vec3.h"

#include "cvr_vec4f.h"
#include "cvr_vec4.h"

#include "cvr_vec_conv.h"

#ifdef CVR_VECTOR_POLLUTION
typedef vec2f   pointf;
typedef vec2i   pointi;
typedef vec2ui  pointui;
typedef vec2f   sizef;
typedef vec2i   sizei;
typedef vec2ui  sizeui;
typedef vec2f   texcoord2f;

typedef vec3f   rgbf;
typedef vec3f   volumef;
typedef vec3f   texcoord3f;

typedef vec4f   rgbaf;
typedef vec4f   texcoord4f;
#endif

#if defined _MSC_VER && _MSC_VER <= 1700
#pragma warning( pop ) // 4201
#endif

#endif
