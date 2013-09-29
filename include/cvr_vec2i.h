//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union vec2i_s
{
    struct
    {
        int_fast32_t x;
        int_fast32_t y;
    };
    struct
    {
        int_fast32_t width;
        int_fast32_t height;
    };
    int_fast32_t elem[2];
} vec2i;

// Returns a vector with all elements set to zero.
vec2i vec2i_zero(void);

// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void vec2i_copy_array(vec2i *const dst, const int_fast32_t *const src, const size_t count);

// Fill all elements of the destination vector with the same scalar value.
void vec2i_fill(vec2i *const dst, const int_fast32_t src);

// Swaps the contents of two vectors.
void vec2i_swap(vec2i *const lhs, vec2i *const rhs);

// Returns a vector with elements swizzled from the original.
vec2i vec2i_swizzle(const vec2i *const v, const unsigned int e0, const unsigned int e1);

// Add vectors and return the result.
vec2i vec2i_add(const vec2i *const lhs, const vec2i *const rhs);

// Add the right-hand vector to the left-hand vector.
void vec2i_add_assign(vec2i *const lhs, const vec2i *const rhs);

// Add a scalar value to each element of a vector and return the result.
vec2i vec2i_add_scalar(const vec2i *const v, const int_fast32_t scalar);

// Add a scalar value to each element of a vector.
void vec2i_add_assign_scalar(vec2i *const v, const int_fast32_t scalar);

// Subtract the right-hand vector from the left-hand and return the result.
vec2i vec2i_subtract(const vec2i *const lhs, const vec2i *const rhs);

// Subtract the right-hand vector from the left-hand vector.
void vec2i_subtract_assign(vec2i *const lhs, const vec2i *const rhs);

// Subtract a scalar value from each element of a vector and return the result.
vec2i vec2i_subtract_scalar(const vec2i *const v, const int_fast32_t scalar);

// Subtract a scalar value from each element of a vector.
void vec2i_subtract_assign_scalar(vec2i *const v, const int_fast32_t scalar);

// Multiply vectors and return the result.
vec2i vec2i_multiply(const vec2i *const lhs, const vec2i *const rhs);

// Multiply vectors and store the product in the left-hand vector.
void vec2i_multiply_assign(vec2i *const lhs, const vec2i *const rhs);

// Multiply each element of a vector by a scalar and return the result.
vec2i vec2i_multiply_scalar(const vec2i *const v, const int_fast32_t scalar);

// Multiply each element of a vector by a scalar.
void vec2i_multiply_assign_scalar(vec2i *const v, const int_fast32_t scalar);

// Divide the left-hand by the right-hand and return the result.
vec2i vec2i_divide(const vec2i *const lhs, const vec2i *const rhs);

// Divide the left-hand by the right-hand vector.
void vec2i_divide_assign(vec2i *const lhs, const vec2i *const rhs);

// Divide each element of a vector by a scalar and return the result.
vec2i vec2i_divide_scalar(const vec2i *const v, const int_fast32_t scalar);

// Divide each element of a vector by a scalar.
void vec2i_divide_assign_scalar(vec2i *const v, const int_fast32_t scalar);

// Prints the vector to a string.
int vec2i_snprintf(char *const str, const size_t count, const vec2i *const v);

// Prints the vector to a string.
int vec2i_swprintf(wchar_t *const str, const size_t count, const vec2i *const v);

// Returns true if the two vectors are equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2i_eq(const vec2i *const lhs, const vec2i *const rhs);

// Returns true if the two vectors are not equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2i_ne(const vec2i *const lhs, const vec2i *const rhs);

// Returns true if the lhs is less-than (<) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2i_lt(const vec2i *const lhs, const vec2i *const rhs);

// Returns true if the lhs is less-than-or-equal-to (<=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2i_le(const vec2i *const lhs, const vec2i *const rhs);

// Returns true if the lhs is greater-than (>) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2i_gt(const vec2i *const lhs, const vec2i *const rhs);

// Returns true if the lhs is greater-than-or-equal-to (>=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2i_ge(const vec2i *const lhs, const vec2i *const rhs);

// Returns the scalar dot product of lhs and rhs.
int_fast32_t vec2i_dot_product(const vec2i *const lhs, const vec2i *const rhs);

// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
int_fast32_t vec2i_length_squared(const vec2i *const v);

// Negates all elements of a vector and returns the result.
vec2i vec2i_negate(const vec2i *const v);

// Absolute value function.
vec2i vec2i_abs(const vec2i *const v);
