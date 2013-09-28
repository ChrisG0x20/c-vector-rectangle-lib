//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//
// Math coordinates vs. raster coordinates:
//
//  - Normal rectangles with math coordinates
//      * the positive y-axis extends from down to up
//      * origin is in the lower-left corner
//      * comparisons are top row and right column inclusive
//
//  - Raster rectangles with raster coordinates
//      * the positive y-axis extends from up to down
//      * origin is in the upper-left corner
//      * comparisons are bottom row and right column exclusive (they're not included).
//

#ifndef CVR_RECTANGLE_H
#define CVR_RECTANGLE_H

#ifndef CVR_VECTOR_H
  #include "cvr_vector.h"
#endif

#if defined _MSC_VER && _MSC_VER <= 1700
#pragma warning( push )
#pragma warning( disable : 4201 ) // This warning is out-of-date for C99.
#endif

#include "cvr_rectf.h"
#include "cvr_recti.h"
#include "cvr_raster_rectf.h"
#include "cvr_raster_recti.h"
#include "cvr_raster_rectui.h"

#include "cvr_rect_conv.h"

#if defined _MSC_VER && _MSC_VER <= 1700
#pragma warning( pop ) // 4201
#endif

#endif // CVR_RECTANGLE_H
