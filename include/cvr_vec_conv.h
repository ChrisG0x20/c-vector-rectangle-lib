//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef CVR_VEC_CONV_H
#define CVR_VEC_CONV_H

// Convert vec2 -> vec2f.
vec2f vec2_dtof(const vec2 *const v);

// Convert vec2i -> vec2f.
vec2f vec2_itof(const vec2i *const v);

// Convert vec2ui -> vec2f.
vec2f vec2_uitof(const vec2ui *const v);

// Convert vec2f -> vec2.
vec2 vec2_ftod(const vec2f *const v);

// Convert vec2i -> vec2.
vec2 vec2_itod(const vec2i *const v);

// Convert vec2ui -> vec2.
vec2 vec2_uitod(const vec2ui *const v);

// Convert vec2f -> vec2i.
vec2i vec2_ftoi(const vec2f *const v);

// Convert vec2 -> vec2i.
vec2i vec2_dtoi(const vec2 *const v);

// Convert vec2ui -> vec2i.
vec2i vec2_uitoi(const vec2ui *const v);

// Convert vec2f -> vec2ui.
vec2ui vec2_ftoui(const vec2f *const v);

// Convert vec2 -> vec2ui.
vec2ui vec2_dtoui(const vec2 *const v);

// Convert vec2i -> vec2ui.
vec2ui vec2_itoui(const vec2i *const v);

// Convert vec3 -> vec3f.
vec3f vec3_dtof(const vec3 *const v);

// Convert vec3f -> vec3.
vec3 vec3_ftod(const vec3f *const v);

// Convert vec4 -> vec4f.
vec4f vec4_dtof(const vec4 *const v);

// Convert vec4f -> vec4.
vec4 vec4_ftod(const vec4f *const v);

#endif // CVR_VEC_CONV_H
