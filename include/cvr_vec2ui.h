//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union vec2ui_s
{
    struct
    {
        uint_fast32_t x;
        uint_fast32_t y;
    };
    struct
    {
        uint_fast32_t width;
        uint_fast32_t height;
    };
    uint_fast32_t elem[2];
} vec2ui;

// Returns a vector with all elements set to zero.
vec2ui vec2ui_zero(void);

// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void vec2ui_copy_array(vec2ui *const dst, const uint_fast32_t *const src, const size_t count);

// Fill all elements of the destination vector with the same scalar value.
void vec2ui_fill(vec2ui *const dst, const uint_fast32_t src);

// Swaps the contents of two vectors.
void vec2ui_swap(vec2ui *const lhs, vec2ui *const rhs);

// Returns a vector with elements swizzled from the original.
vec2ui vec2ui_swizzle(const vec2ui *const v, const unsigned int e0, const unsigned int e1);

// Add vectors and return the result.
vec2ui vec2ui_add(const vec2ui *const lhs, const vec2ui *const rhs);

// Add the right-hand vector to the left-hand vector.
void vec2ui_add_assign(vec2ui *const lhs, const vec2ui *const rhs);

// Add a scalar value to each element of a vector and return the result.
vec2ui vec2ui_add_scalar(const vec2ui *const v, const uint_fast32_t scalar);

// Add a scalar value to each element of a vector.
void vec2ui_add_assign_scalar(vec2ui *const v, const uint_fast32_t scalar);

// Subtract the right-hand vector from the left-hand and return the result.
vec2ui vec2ui_subtract(const vec2ui *const lhs, const vec2ui *const rhs);

// Subtract the right-hand vector from the left-hand vector.
void vec2ui_subtract_assign(vec2ui *const lhs, const vec2ui *const rhs);

// Subtract a scalar value from each element of a vector and return the result.
vec2ui vec2ui_subtract_scalar(const vec2ui *const v, const uint_fast32_t scalar);

// Subtract a scalar value from each element of a vector.
void vec2ui_subtract_assign_scalar(vec2ui *const v, const uint_fast32_t scalar);

// Multiply vectors and return the result.
vec2ui vec2ui_multiply(const vec2ui *const lhs, const vec2ui *const rhs);

// Multiply vectors and store the product in the left-hand vector.
void vec2ui_multiply_assign(vec2ui *const lhs, const vec2ui *const rhs);

// Multiply each element of a vector by a scalar and return the result.
vec2ui vec2ui_multiply_scalar(const vec2ui *const v, const uint_fast32_t scalar);

// Multiply each element of a vector by a scalar.
void vec2ui_multiply_assign_scalar(vec2ui *const v, const uint_fast32_t scalar);

// Divide the left-hand by the right-hand and return the result.
vec2ui vec2ui_divide(const vec2ui *const lhs, const vec2ui *const rhs);

// Divide the left-hand by the right-hand vector.
void vec2ui_divide_assign(vec2ui *const lhs, const vec2ui *const rhs);

// Divide each element of a vector by a scalar and return the result.
vec2ui vec2ui_divide_scalar(const vec2ui *const v, const uint_fast32_t scalar);

// Divide each element of a vector by a scalar.
void vec2ui_divide_assign_scalar(vec2ui *const v, const uint_fast32_t scalar);

// Prints the vector to a string.
int vec2ui_snprintf(char *const str, const size_t count, const vec2ui *const v);

// Prints the vector to a string.
int vec2ui_swprintf(wchar_t *const str, const size_t count, const vec2ui *const v);

// Returns true if the two vectors are equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2ui_eq(const vec2ui *const lhs, const vec2ui *const rhs);

// Returns true if the two vectors are not equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2ui_ne(const vec2ui *const lhs, const vec2ui *const rhs);

// Returns true if the lhs is less-than (<) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2ui_lt(const vec2ui *const lhs, const vec2ui *const rhs);

// Returns true if the lhs is less-than-or-equal-to (<=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2ui_le(const vec2ui *const lhs, const vec2ui *const rhs);

// Returns true if the lhs is greater-than (>) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2ui_gt(const vec2ui *const lhs, const vec2ui *const rhs);

// Returns true if the lhs is greater-than-or-equal-to (>=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2ui_ge(const vec2ui *const lhs, const vec2ui *const rhs);

// Returns the scalar dot product of lhs and rhs.
uint_fast32_t vec2ui_dot_product(const vec2ui *const lhs, const vec2ui *const rhs);

// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
uint_fast32_t vec2ui_length_squared(const vec2ui *const v);
