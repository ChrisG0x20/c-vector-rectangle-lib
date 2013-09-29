//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#include <assert.h>
#include <stdint.h>
#include <math.h>   // for sqrt(), fabs()
#include <stdio.h>  // for sprintf()
#ifdef _WIN32
#define SNPRINTF sprintf_s
#define SWPRINTF swprintf_s
#else
#include <wchar.h>
#include <stdlib.h> // for abs()
#define SNPRINTF snprintf
#define SWPRINTF swprintf
#endif
#include "cvr_vector.h"

///////////////////////////
// 2-Dimensional Vectors //
///////////////////////////

#define DIMENSION       2u

#define FOR_EACH_ADDITIONAL_ELEM(apply) \
    apply(1)

// 2D Floating point types
//////////////////////////

#define VEC_FMT_SPEC    "%f"
#define VEC_WFMT_SPEC   L"%f"

// 2D float vector
//////////////////

#define VEC_FUNC(name)  vec2f_##name
#define VEC_SQRT(x)     sqrtf(x)
#define VEC_ABS(x)      fabsf(x)
#define VEC_SIN(x)      sinf(x)
#define VEC_COS(x)      cosf(x)
#define scalar_t        float
#define vector_t        vec2f

#include "cvr_vec_t.h"

#undef VEC_FUNC
#undef VEC_SQRT
#undef VEC_ABS
#undef VEC_SIN
#undef VEC_COS
#undef scalar_t
#undef vector_t

// 2D double vector
///////////////////

#define VEC_FUNC(name)  vec2_##name
#define VEC_SQRT(x)     sqrt(x)
#define VEC_ABS(x)      fabs(x)
#define VEC_SIN(x)      sinf(x)
#define VEC_COS(x)      cosf(x)
#define scalar_t        double
#define vector_t        vec2

#include "cvr_vec_t.h"

#undef VEC_FUNC
#undef VEC_SQRT
#undef VEC_ABS
#undef VEC_SIN
#undef VEC_COS
#undef scalar_t
#undef vector_t

// 2D Integer types
///////////////////

#undef VEC_FMT_SPEC
#undef VEC_WFMT_SPEC
#define VEC_FMT_SPEC    "%d"
#define VEC_WFMT_SPEC   L"%d"

// 2D 32-bit int vector
///////////////////////

#define SCALAR_INTEGER

#define VEC_FUNC(name)  vec2i_##name
#define VEC_ABS(x)      abs(x)
#define scalar_t        int_fast32_t
#define vector_t        vec2i

#include "cvr_vec_t.h"

#undef SCALAR_INTEGER
#undef VEC_FUNC
#undef VEC_ABS
#undef scalar_t
#undef vector_t

// 2D 32-bit unsigned int vector
////////////////////////////////

#define SCALAR_UNSIGNED

#define VEC_FUNC(name)  vec2ui_##name
#define scalar_t        uint_fast32_t
#define vector_t        vec2ui

#include "cvr_vec_t.h"

#undef SCALAR_UNSIGNED
#undef VEC_FUNC
#undef scalar_t
#undef vector_t
#undef VEC_FMT_SPEC
#undef VEC_WFMT_SPEC
#undef DIMENSION
#undef FOR_EACH_ADDITIONAL_ELEM

///////////////////////////
// 3-Dimensional Vectors //
///////////////////////////

#define DIMENSION       3u

#define FOR_EACH_ADDITIONAL_ELEM(apply) \
    apply(1)\
    apply(2)

#define VEC_FMT_SPEC    "%f"
#define VEC_WFMT_SPEC   L"%f"

// 3D float vector
//////////////////

#define VEC_FUNC(name)  vec3f_##name
#define VEC_SQRT(x)     sqrtf(x)
#define VEC_ABS(x)      fabsf(x)
#define scalar_t        float
#define vector_t        vec3f

#include "cvr_vec_t.h"

#undef VEC_FUNC
#undef VEC_SQRT
#undef VEC_ABS
#undef scalar_t
#undef vector_t

// 3D double vector
///////////////////

#define VEC_FUNC(name)  vec3_##name
#define VEC_SQRT(x)     sqrt(x)
#define VEC_ABS(x)      fabs(x)
#define scalar_t        double
#define vector_t        vec3

#include "cvr_vec_t.h"

#undef VEC_FUNC
#undef VEC_SQRT
#undef VEC_ABS
#undef scalar_t
#undef vector_t
#undef DIMENSION
#undef FOR_EACH_ADDITIONAL_ELEM

///////////////////////////
// 4-Dimensional Vectors //
///////////////////////////

#define DIMENSION       4u

#define FOR_EACH_ADDITIONAL_ELEM(apply) \
    apply(1)\
    apply(2)\
    apply(3)

// 4D float vector
//////////////////

#define VEC_FUNC(name)  vec4f_##name
#define VEC_SQRT(x)     sqrtf(x)
#define VEC_ABS(x)      fabsf(x)
#define scalar_t        float
#define vector_t        vec4f

#include "cvr_vec_t.h"

#undef VEC_FUNC
#undef VEC_SQRT
#undef VEC_ABS
#undef scalar_t
#undef vector_t

// 4D double vector
///////////////////

#define VEC_FUNC(name)  vec4_##name
#define VEC_SQRT(x)     sqrt(x)
#define VEC_ABS(x)      fabs(x)
#define scalar_t        double
#define vector_t        vec4

#include "cvr_vec_t.h"

#undef VEC_FUNC
#undef VEC_SQRT
#undef VEC_ABS
#undef scalar_t
#undef vector_t
#undef DIMENSION
#undef FOR_EACH_ADDITIONAL_ELEM
