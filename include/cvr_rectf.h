//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union rectf_s
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
} rectf;

// Returns a rectangle with all elements set to 0.
rectf rectf_zero(void);

// Returns a rectangle initialized to location (0, 0) with the specified width and height.
rectf rectf_init_to_size(const float width, const float height);

// Returns a rectangle initialized to the specified location and size.
rectf rectf_init(const float x, const float y, const float width, const float height);

// Returns a rectangle initialized to the specified location with a zero size.
rectf rectf_init_with_location(const vec2f *const location);

// Returns a rectangle initialized to location (0, 0) with the specified size.
rectf rectf_init_with_size(const vec2f *const size);

// Returns a rectangle initialized to the specified location and size.
rectf rectf_init_with(const vec2f *const location, const vec2f *const size);

// Calculates and returns the left bound of the rectangle.
float rectf_get_left(const rectf *const r);

// Sets the left bound of the rectangle.
void rectf_set_left(rectf *const r, const float value);

// Calculates and returns the right bound of the rectangle.
float rectf_get_right(const rectf *const r);

// Sets the right bound of the rectangle.
void rectf_set_right(rectf *const r, const float value);

// Returns true if two rectangles are equivalent.
bool rectf_eq(const rectf *const lhs, const rectf *const rhs);

// Returns true if two rectangles are not equivalent.
bool rectf_ne(const rectf *const lhs, const rectf *const rhs);

// Prints the rectangle to a string.
int rectf_snprintf(char *const str, const size_t count, const rectf *const r);

// Prints the rectangle to a wide-string.
int rectf_swprintf(wchar_t *const str, const size_t count, const rectf *const r);

// Calculates and returns the top bound of the rectangle.
float rectf_get_top(const rectf *const r);

// Sets the top bound of the rectangle.
void rectf_set_top(rectf *const r, const float value);

// Calculates and returns the bottom bound of the rectangle.
float rectf_get_bottom(const rectf *const r);

// Sets the bottom bound of the rectangle.
void rectf_set_bottom(rectf *const r, const float value);

// Returns true if the specified point is contained within the rectangle.
bool rectf_contains(const rectf *const r, const vec2f *const p);

// Returns true if the specified rectangles overlap.
bool rectf_overlaps(const rectf *const lhs, const rectf *const rhs);
