//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#include <assert.h>
#include <stdint.h>
#include <wchar.h>
#include "cvr_vector.h"
#include "cvr_vec_conv.h"

vec2f vec2_dtof(const vec2 *const v)
{
    vec2f result;

    assert(v);

    result.elem[0] = (float)v->elem[0];
    result.elem[1] = (float)v->elem[1];

    return result;
}

vec2f vec2_itof(const vec2i *const v)
{
    vec2f result;

    assert(v);

    result.elem[0] = (float)v->elem[0];
    result.elem[1] = (float)v->elem[1];

    return result;
}

vec2f vec2_uitof(const vec2ui *const v)
{
    vec2f result;

    assert(v);

    result.elem[0] = (float)v->elem[0];
    result.elem[1] = (float)v->elem[1];

    return result;
}

vec2 vec2_ftod(const vec2f *const v)
{
    vec2 result;

    assert(v);

    result.elem[0] = v->elem[0];
    result.elem[1] = v->elem[1];

    return result;
}

vec2 vec2_itod(const vec2i *const v)
{
    vec2 result;

    assert(v);

    result.elem[0] = v->elem[0];
    result.elem[1] = v->elem[1];

    return result;
}

vec2 vec2_uitod(const vec2ui *const v)
{
    vec2 result;

    assert(v);

    result.elem[0] = v->elem[0];
    result.elem[1] = v->elem[1];

    return result;
}

vec2i vec2_ftoi(const vec2f *const v)
{
    vec2i result;

    assert(v);

    result.elem[0] = (int_fast32_t)v->elem[0];
    result.elem[1] = (int_fast32_t)v->elem[1];

    return result;
}

vec2i vec2_dtoi(const vec2 *const v)
{
    vec2i result;

    assert(v);

    result.elem[0] = (int_fast32_t)v->elem[0];
    result.elem[1] = (int_fast32_t)v->elem[1];

    return result;
}

vec2i vec2_uitoi(const vec2ui *const v)
{
    vec2i result;

    assert(v);

    result.elem[0] = (int_fast32_t)v->elem[0];
    result.elem[1] = (int_fast32_t)v->elem[1];

    return result;
}

vec2ui vec2_ftoui(const vec2f *const v)
{
    vec2ui result;

    assert(v);

    result.elem[0] = (uint_fast32_t)v->elem[0];
    result.elem[1] = (uint_fast32_t)v->elem[1];

    return result;
}

vec2ui vec2_dtoui(const vec2 *const v)
{
    vec2ui result;

    assert(v);

    result.elem[0] = (uint_fast32_t)v->elem[0];
    result.elem[1] = (uint_fast32_t)v->elem[1];

    return result;
}

vec2ui vec2_itoui(const vec2i *const v)
{
    vec2ui result;

    assert(v);

    result.elem[0] = (uint_fast32_t)v->elem[0];
    result.elem[1] = (uint_fast32_t)v->elem[1];

    return result;
}

vec3f vec3_dtof(const vec3 *const v)
{
    vec3f result;

    assert(v);

    result.elem[0] = (float)v->elem[0];
    result.elem[1] = (float)v->elem[1];
    result.elem[2] = (float)v->elem[2];

    return result;
}

vec3 vec3_ftod(const vec3f *const v)
{
    vec3 result;

    assert(v);

    result.elem[0] = v->elem[0];
    result.elem[1] = v->elem[1];
    result.elem[2] = v->elem[2];

    return result;
}

vec4f vec4_dtof(const vec4 *const v)
{
    vec4f result;

    assert(v);

    result.elem[0] = (float)v->elem[0];
    result.elem[1] = (float)v->elem[1];
    result.elem[2] = (float)v->elem[2];
    result.elem[3] = (float)v->elem[3];

    return result;
}

vec4 vec4_ftod(const vec4f *const v)
{
    vec4 result;

    assert(v);

    result.elem[0] = v->elem[0];
    result.elem[1] = v->elem[1];
    result.elem[2] = v->elem[2];
    result.elem[3] = v->elem[3];

    return result;
}
