//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#include <assert.h>
#include <stdint.h>
#include <stdio.h>  // for sprintf()
#ifdef _WIN32
#define SNPRINTF sprintf_s
#define SWPRINTF swprintf_s
#else
#include <wchar.h>
#define SNPRINTF snprintf
#define SWPRINTF swprintf
#endif
#include "cvr_rectangle.h"

#define RECT_FUNC(name) rectf_##name
#define scalar_t        float
#define vector_t        vec2f
#define rect_t          rectf
#define RECT_FMT_SPEC   "%f"
#define RECT_WFMT_SPEC  L"%f"

#include "cvr_rect_t.h"

#undef RECT_FUNC
#undef scalar_t
#undef vector_t
#undef rect_t
#undef RECT_FMT_SPEC
#undef RECT_WFMT_SPEC

#define RECT_FUNC(name) recti_##name
#define scalar_t        int_fast32_t
#define vector_t        vec2i
#define rect_t          recti
#define RECT_FMT_SPEC   "%d"
#define RECT_WFMT_SPEC  L"%d"

#include "cvr_rect_t.h"

#undef RECT_FUNC
#undef scalar_t
#undef vector_t
#undef rect_t
#undef RECT_FMT_SPEC
#undef RECT_WFMT_SPEC

#define RASTER_COORDINATES

#define RECT_FUNC(name) raster_rectf_##name
#define scalar_t        float
#define vector_t        vec2f
#define rect_t          raster_rectf
#define RECT_FMT_SPEC   "%f"
#define RECT_WFMT_SPEC  L"%f"

#include "cvr_rect_t.h"

#undef RECT_FUNC
#undef scalar_t
#undef vector_t
#undef rect_t
#undef RECT_FMT_SPEC
#undef RECT_WFMT_SPEC

#define RECT_FUNC(name) raster_recti_##name
#define scalar_t        int_fast32_t
#define vector_t        vec2i
#define rect_t          raster_recti
#define RECT_FMT_SPEC   "%d"
#define RECT_WFMT_SPEC  L"%d"

#include "cvr_rect_t.h"

#undef RECT_FUNC
#undef scalar_t
#undef vector_t
#undef rect_t

#define RECT_FUNC(name) raster_rectui_##name
#define scalar_t        uint_fast32_t
#define vector_t        vec2ui
#define rect_t          raster_rectui

#include "cvr_rect_t.h"

#undef RECT_FUNC
#undef scalar_t
#undef vector_t
#undef rect_t
#undef RECT_FMT_SPEC
#undef RECT_WFMT_SPEC

#undef RASTER_COORDINATES
