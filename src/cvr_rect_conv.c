//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#include <assert.h>
#include <stdint.h>
#include <wchar.h>
#include "cvr_rectangle.h"
#include "cvr_rect_conv.h"

// Convert rectf -> recti.
recti rect_ftoi(const rectf *const r)
{
    recti result = recti_zero();
    size_t i = 0u;

    assert(r);

    for (; i < 4; ++i)
    {
        result.elem[i] = (int_fast32_t)r->elem[i];
    }

    return result;
}

// Convert recti -> rectf.
rectf rect_itof(const recti *const r)
{
    rectf result = rectf_zero();
    size_t i = 0u;

    assert(r);

    for (; i < 4; ++i)
    {
        result.elem[i] = (float)r->elem[i];
    }

    return result;
}

// Convert raster_rectf -> raster_recti.
raster_recti raster_rect_ftoi(const raster_rectf *const r)
{
    raster_recti result = raster_recti_zero();
    size_t i = 0u;

    assert(r);

    for (; i < 4; ++i)
    {
        result.elem[i] = (int_fast32_t)r->elem[i];
    }

    return result;
}

// Convert raster_rectf -> raster_rectui.
raster_rectui raster_rect_ftoui(const raster_rectf *const r)
{
    raster_rectui result = raster_rectui_zero();
    size_t i = 0u;

    assert(r);

    for (; i < 4; ++i)
    {
        result.elem[i] = (uint_fast32_t)r->elem[i];
    }

    return result;
}

// Convert raster_recti -> raster_rectf.
raster_rectf raster_rect_itof(const raster_recti *const r)
{
    raster_rectf result = raster_rectf_zero();
    size_t i = 0u;

    assert(r);

    for (; i < 4; ++i)
    {
        result.elem[i] = (float)r->elem[i];
    }

    return result;
}

// Convert raster_recti -> raster_rectui.
raster_rectui raster_rect_itoui(const raster_recti *const r)
{
    raster_rectui result = raster_rectui_zero();
    size_t i = 0u;

    assert(r);

    for (; i < 4; ++i)
    {
        result.elem[i] = r->elem[i];
    }

    return result;
}

// Convert raster_rectui -> raster_rectf.
raster_rectf raster_rect_uitof(const raster_rectui *const r)
{
    raster_rectf result = raster_rectf_zero();
    size_t i = 0u;

    assert(r);

    for (; i < 4; ++i)
    {
        result.elem[i] = (float)r->elem[i];
    }

    return result;
}

// Convert raster_rectui -> raster_recti.
raster_recti raster_rect_uitoi(const raster_rectui *const r)
{
    raster_recti result = raster_recti_zero();
    size_t i = 0u;

    assert(r);

    for (; i < 4; ++i)
    {
        result.elem[i] = r->elem[i];
    }

    return result;
}
