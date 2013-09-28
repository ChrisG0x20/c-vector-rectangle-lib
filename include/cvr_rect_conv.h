//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef CVR_RECT_CONV_H
#define CVR_RECT_CONV_H

// Convert rectf -> recti.
recti rect_ftoi(const rectf *const r);

// Convert recti -> rectf.
rectf rect_itof(const recti *const r);

// Convert raster_rectf -> raster_recti.
raster_recti raster_rect_ftoi(const raster_rectf *const r);

// Convert raster_rectf -> raster_rectui.
raster_rectui raster_rect_ftoui(const raster_rectf *const r);

// Convert raster_recti -> raster_rectf.
raster_rectf raster_rect_itof(const raster_recti *const r);

// Convert raster_recti -> raster_rectui.
raster_rectui raster_rect_itoui(const raster_recti *const r);

// Convert raster_rectui -> raster_rectf.
raster_rectf raster_rect_uitof(const raster_rectui *const r);

// Convert raster_rectui -> raster_recti.
raster_recti raster_rect_uitoi(const raster_rectui *const r);

#endif // CVR_VEC_CONV_H
