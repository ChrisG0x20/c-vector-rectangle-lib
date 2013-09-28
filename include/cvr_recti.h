//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union recti_s
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
} recti;

// Returns a rectangle with all elements set to 0.
recti recti_zero();

// Returns a rectangle initialized to location (0, 0) with the specified width and height.
recti recti_init_to_size(const int_fast32_t width, const int_fast32_t height);

// Returns a rectangle initialized to the specified location and size.
recti recti_init(const int_fast32_t x, const int_fast32_t y, const int_fast32_t width, const int_fast32_t height);

// Returns a rectangle initialized to the specified location with a zero size.
recti recti_init_with_location(const vec2i *const location);

// Returns a rectangle initialized to location (0, 0) with the specified size.
recti recti_init_with_size(const vec2i *const size);

// Returns a rectangle initialized to the specified location and size.
recti recti_init_with(const vec2i *const location, const vec2i *const size);

// Calculates and returns the left bound of the rectangle.
int_fast32_t recti_get_left(const recti *const r);

// Sets the left bound of the rectangle.
void recti_set_left(recti *const r, const int_fast32_t value);

// Calculates and returns the right bound of the rectangle.
int_fast32_t recti_get_right(const recti *const r);

// Sets the right bound of the rectangle.
void recti_set_right(recti *const r, const int_fast32_t value);

// Returns true if two rectangles are equivalent.
bool recti_eq(const recti *const lhs, const recti *const rhs);

// Returns true if two rectangles are not equivalent.
bool recti_ne(const recti *const lhs, const recti *const rhs);

// Prints the rectangle to a string.
int recti_snprintf(char *const str, const size_t count, const recti *const r);

// Prints the rectangle to a wide-string.
int recti_swprintf(wchar_t *const str, const size_t count, const recti *const r);

// Calculates and returns the top bound of the rectangle.
int_fast32_t recti_get_top(const recti *const r);

// Sets the top bound of the rectangle.
void recti_set_top(recti *const r, const int_fast32_t value);

// Calculates and returns the bottom bound of the rectangle.
int_fast32_t recti_get_bottom(const recti *const r);

// Sets the bottom bound of the rectangle.
void recti_set_bottom(recti *const r, const int_fast32_t value);

// Returns true if the specified point is contained within the rectangle.
bool recti_contains(const recti *const r, const vec2i *const p);

// Returns true if the specified rectangles overlap.
bool recti_overlaps(const recti *const lhs, const recti *const rhs);
