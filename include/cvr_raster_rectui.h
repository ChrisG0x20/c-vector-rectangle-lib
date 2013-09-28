//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union raster_rectui_s
{
    struct
    {
        vec2ui          location;
        vec2ui          size;
    };
    struct
    {
        uint_fast32_t   x;
        uint_fast32_t   y;
        uint_fast32_t   width;
        uint_fast32_t   height;
    };
    uint_fast32_t elem[4];
} raster_rectui;

// Returns a rectangle with all elements set to 0.
raster_rectui raster_rectui_zero();

// Returns a rectangle initialized to location (0, 0) with the specified width and height.
raster_rectui raster_rectui_init_to_size(const uint_fast32_t width, const uint_fast32_t height);

// Returns a rectangle initialized to the specified location and size.
raster_rectui raster_rectui_init(const uint_fast32_t x, const uint_fast32_t y, const uint_fast32_t width, const uint_fast32_t height);

// Returns a rectangle initialized to the specified location with a zero size.
raster_rectui raster_rectui_init_with_location(const vec2ui *const location);

// Returns a rectangle initialized to location (0, 0) with the specified size.
raster_rectui raster_rectui_init_with_size(const vec2ui *const size);

// Returns a rectangle initialized to the specified location and size.
raster_rectui raster_rectui_init_with(const vec2ui *const location, const vec2ui *const size);

// Calculates and returns the left bound of the rectangle.
uint_fast32_t raster_rectui_get_left(const raster_rectui *const r);

// Sets the left bound of the rectangle.
void raster_rectui_set_left(raster_rectui *const r, const uint_fast32_t value);

// Calculates and returns the right bound of the rectangle.
uint_fast32_t raster_rectui_get_right(const raster_rectui *const r);

// Sets the right bound of the rectangle.
void raster_rectui_set_right(raster_rectui *const r, const uint_fast32_t value);

// Returns true if two rectangles are equivalent.
bool raster_rectui_eq(const raster_rectui *const lhs, const raster_rectui *const rhs);

// Returns true if two rectangles are not equivalent.
bool raster_rectui_ne(const raster_rectui *const lhs, const raster_rectui *const rhs);

// Prints the rectangle to a string.
int raster_rectui_snprintf(char *const str, const size_t count, const raster_rectui *const r);

// Prints the rectangle to a wide-string.
int raster_rectui_swprintf(wchar_t *const str, const size_t count, const raster_rectui *const r);

// Calculates and returns the top bound of the rectangle.
uint_fast32_t raster_rectui_get_top(const raster_rectui *const r);

// Sets the top bound of the rectangle.
void raster_rectui_set_top(raster_rectui *const r, const uint_fast32_t value);

// Calculates and returns the bottom bound of the rectangle.
uint_fast32_t raster_rectui_get_bottom(const raster_rectui *const r);

// Sets the bottom bound of the rectangle.
void raster_rectui_set_bottom(raster_rectui *const r, const uint_fast32_t value);

// Returns true if the specified point is contained within the rectangle.
bool raster_rectui_contains(const raster_rectui *const r, const vec2ui *const p);

// Returns true if the specified rectangles overlap.
bool raster_rectui_overlaps(const raster_rectui *const lhs, const raster_rectui *const rhs);

#ifdef _WINDEF_
// Initializes and returns an equivalent Win32 RECT from the specified rectangle.
RECT raster_rectui_to_windows_rect(const raster_rectui *const r);

// Initializes and returns an equivalent rectangle from a Win32 RECT.
raster_rectui raster_rectui_from_windows_rect(const RECT *const r);
#endif // _WINDEF_

#ifdef __OBJC__
// Initializes and returns an equivalent Objective-C CGRect from the specified rectangle.
CGRect raster_rectui_to_objc_cgrect(const raster_rectui *const r);

// Initializes and returns an equivalent rectangle from an Objective-C CGRect.
raster_rectui raster_rectui_from_objc_cgrect(const CGRect *const r);
#endif // __OBJC__
