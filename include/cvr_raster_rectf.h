//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union raster_raster_rectf_s
{
    struct
    {
        vec2f   location;
        vec2f   size;
    };
    struct
    {
        float   x;
        float   y;
        float   width;
        float   height;
    };
    float elem[4];
} raster_rectf;

// Returns a rectangle with all elements set to 0.
raster_rectf raster_rectf_zero(void);

// Returns a rectangle initialized to location (0, 0) with the specified width and height.
raster_rectf raster_rectf_init_to_size(const float width, const float height);

// Returns a rectangle initialized to the specified location and size.
raster_rectf raster_rectf_init(const float x, const float y, const float width, const float height);

// Returns a rectangle initialized to the specified location with a zero size.
raster_rectf raster_rectf_init_with_location(const vec2f *const location);

// Returns a rectangle initialized to location (0, 0) with the specified size.
raster_rectf raster_rectf_init_with_size(const vec2f *const size);

// Returns a rectangle initialized to the specified location and size.
raster_rectf raster_rectf_init_with(const vec2f *const location, const vec2f *const size);

// Calculates and returns the left bound of the rectangle.
float raster_rectf_get_left(const raster_rectf *const r);

// Sets the left bound of the rectangle.
void raster_rectf_set_left(raster_rectf *const r, const float value);

// Calculates and returns the right bound of the rectangle.
float raster_rectf_get_right(const raster_rectf *const r);

// Sets the right bound of the rectangle.
void raster_rectf_set_right(raster_rectf *const r, const float value);

// Returns true if two rectangles are equivalent.
bool raster_rectf_eq(const raster_rectf *const lhs, const raster_rectf *const rhs);

// Returns true if two rectangles are not equivalent.
bool raster_rectf_ne(const raster_rectf *const lhs, const raster_rectf *const rhs);

// Prints the rectangle to a string.
int raster_rectf_snprintf(char *const str, const size_t count, const raster_rectf *const r);

// Prints the rectangle to a wide-string.
int raster_rectf_swprintf(wchar_t *const str, const size_t count, const raster_rectf *const r);

// Calculates and returns the top bound of the rectangle.
float raster_rectf_get_top(const raster_rectf *const r);

// Sets the top bound of the rectangle.
void raster_rectf_set_top(raster_rectf *const r, const float value);

// Calculates and returns the bottom bound of the rectangle.
float raster_rectf_get_bottom(const raster_rectf *const r);

// Sets the bottom bound of the rectangle.
void raster_rectf_set_bottom(raster_rectf *const r, const float value);

// Returns true if the specified point is contained within the rectangle.
bool raster_rectf_contains(const raster_rectf *const r, const vec2f *const p);

// Returns true if the specified rectangles overlap.
bool raster_rectf_overlaps(const raster_rectf *const lhs, const raster_rectf *const rhs);

#ifdef _WINDEF_
// Initializes and returns an equivalent Win32 RECT from the specified rectangle.
RECT raster_rectf_to_windows_rect(const raster_rectf *const r);

// Initializes and returns an equivalent rectangle from a Win32 RECT.
raster_rectf raster_rectf_from_windows_rect(const RECT *const r);
#endif // _WINDEF_

#ifdef __OBJC__
// Initializes and returns an equivalent Objective-C CGRect from the specified rectangle.
CGRect raster_rectf_to_objc_cgrect(const raster_rectf *const r);

// Initializes and returns an equivalent rectangle from an Objective-C CGRect.
raster_rectf raster_rectf_from_objc_cgrect(const CGRect *const r);
#endif // __OBJC__
