//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union raster_recti_s
{
    struct
    {
        vec2i           location;
        vec2i           size;
    };
    struct
    {
        int_fast32_t    x;
        int_fast32_t    y;
        int_fast32_t    width;
        int_fast32_t    height;
    };
    int_fast32_t elem[4];
} raster_recti;

// Returns a rectangle with all elements set to 0.
raster_recti raster_recti_zero(void);

// Returns a rectangle initialized to location (0, 0) with the specified width and height.
raster_recti raster_recti_init_to_size(const int_fast32_t width, const int_fast32_t height);

// Returns a rectangle initialized to the specified location and size.
raster_recti raster_recti_init(const int_fast32_t x, const int_fast32_t y, const int_fast32_t width, const int_fast32_t height);

// Returns a rectangle initialized to the specified location with a zero size.
raster_recti raster_recti_init_with_location(const vec2i *const location);

// Returns a rectangle initialized to location (0, 0) with the specified size.
raster_recti raster_recti_init_with_size(const vec2i *const size);

// Returns a rectangle initialized to the specified location and size.
raster_recti raster_recti_init_with(const vec2i *const location, const vec2i *const size);

// Calculates and returns the left bound of the rectangle.
int_fast32_t raster_recti_get_left(const raster_recti *const r);

// Sets the left bound of the rectangle.
void raster_recti_set_left(raster_recti *const r, const int_fast32_t value);

// Calculates and returns the right bound of the rectangle.
int_fast32_t raster_recti_get_right(const raster_recti *const r);

// Sets the right bound of the rectangle.
void raster_recti_set_right(raster_recti *const r, const int_fast32_t value);

// Returns true if two rectangles are equivalent.
bool raster_recti_eq(const raster_recti *const lhs, const raster_recti *const rhs);

// Returns true if two rectangles are not equivalent.
bool raster_recti_ne(const raster_recti *const lhs, const raster_recti *const rhs);

// Prints the rectangle to a string.
int raster_recti_snprintf(char *const str, const size_t count, const raster_recti *const r);

// Prints the rectangle to a wide-string.
int raster_recti_swprintf(wchar_t *const str, const size_t count, const raster_recti *const r);

// Calculates and returns the top bound of the rectangle.
int_fast32_t raster_recti_get_top(const raster_recti *const r);

// Sets the top bound of the rectangle.
void raster_recti_set_top(raster_recti *const r, const int_fast32_t value);

// Calculates and returns the bottom bound of the rectangle.
int_fast32_t raster_recti_get_bottom(const raster_recti *const r);

// Sets the bottom bound of the rectangle.
void raster_recti_set_bottom(raster_recti *const r, const int_fast32_t value);

// Returns true if the specified point is contained within the rectangle.
bool raster_recti_contains(const raster_recti *const r, const vec2i *const p);

// Returns true if the specified rectangles overlap.
bool raster_recti_overlaps(const raster_recti *const lhs, const raster_recti *const rhs);

#ifdef _WINDEF_
// Initializes and returns an equivalent Win32 RECT from the specified rectangle.
RECT raster_recti_to_windows_rect(const raster_recti *const r);

// Initializes and returns an equivalent rectangle from a Win32 RECT.
raster_recti raster_recti_from_windows_rect(const RECT *const r);
#endif // _WINDEF_

#ifdef __OBJC__
// Initializes and returns an equivalent Objective-C CGRect from the specified rectangle.
CGRect raster_recti_to_objc_cgrect(const raster_recti *const r);

// Initializes and returns an equivalent rectangle from an Objective-C CGRect.
raster_recti raster_recti_from_objc_cgrect(const CGRect *const r);
#endif // __OBJC__
