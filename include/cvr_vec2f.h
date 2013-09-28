//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union vec2f_s
{
    struct
    {
        float x;
        float y;
    };
    struct
    {
        float width;
        float height;
    };
    struct
    {
        float s;
        float t;
    };
    float elem[2];
} vec2f;

// Returns a vector with all elements set to zero.
vec2f vec2f_zero();

// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void vec2f_copy_array(vec2f *const dst, const float *const src, const size_t count);

// Fill all elements of the destination vector with the same scalar value.
void vec2f_fill(vec2f *const dst, const float src);

// Swaps the contents of two vectors.
void vec2f_swap(vec2f *const lhs, vec2f *const rhs);

// Returns a vector with elements swizzled from the original.
vec2f vec2f_swizzle(const vec2f *const v, const unsigned int e0, const unsigned int e1);

// Add vectors and return the result.
vec2f vec2f_add(const vec2f *const lhs, const vec2f *const rhs);

// Add the right-hand vector to the left-hand vector.
void vec2f_add_assign(vec2f *const lhs, const vec2f *const rhs);

// Add a scalar value to each element of a vector and return the result.
vec2f vec2f_add_scalar(const vec2f *const v, const float scalar);

// Add a scalar value to each element of a vector.
void vec2f_add_assign_scalar(vec2f *const v, const float scalar);

// Subtract the right-hand vector from the left-hand and return the result.
vec2f vec2f_subtract(const vec2f *const lhs, const vec2f *const rhs);

// Subtract the right-hand vector from the left-hand vector.
void vec2f_subtract_assign(vec2f *const lhs, const vec2f *const rhs);

// Subtract a scalar value from each element of a vector and return the result.
vec2f vec2f_subtract_scalar(const vec2f *const v, const float scalar);

// Subtract a scalar value from each element of a vector.
void vec2f_subtract_assign_scalar(vec2f *const v, const float scalar);

// Multiply vectors and return the result.
vec2f vec2f_multiply(const vec2f *const lhs, const vec2f *const rhs);

// Multiply vectors and store the product in the left-hand vector.
void vec2f_multiply_assign(vec2f *const lhs, const vec2f *const rhs);

// Multiply each element of a vector by a scalar and return the result.
vec2f vec2f_multiply_scalar(const vec2f *const v, const float scalar);

// Multiply each element of a vector by a scalar.
void vec2f_multiply_assign_scalar(vec2f *const v, const float scalar);

// Divide the left-hand by the right-hand and return the result.
vec2f vec2f_divide(const vec2f *const lhs, const vec2f *const rhs);

// Divide the left-hand by the right-hand vector.
void vec2f_divide_assign(vec2f *const lhs, const vec2f *const rhs);

// Divide each element of a vector by a scalar and return the result.
vec2f vec2f_divide_scalar(const vec2f *const v, const float scalar);

// Divide each element of a vector by a scalar.
void vec2f_divide_assign_scalar(vec2f *const v, const float scalar);

// Prints the vector to a string.
int vec2f_snprintf(char *const str, const size_t count, const vec2f *const v);

// Prints the vector to a string.
int vec2f_swprintf(wchar_t *const str, const size_t count, const vec2f *const v);

// Returns true if the two vectors are equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2f_eq(const vec2f *const lhs, const vec2f *const rhs);

// Returns true if the two vectors are not equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2f_ne(const vec2f *const lhs, const vec2f *const rhs);

// Returns true if the lhs is less-than (<) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2f_lt(const vec2f *const lhs, const vec2f *const rhs);

// Returns true if the lhs is less-than-or-equal-to (<=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2f_le(const vec2f *const lhs, const vec2f *const rhs);

// Returns true if the lhs is greater-than (>) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2f_gt(const vec2f *const lhs, const vec2f *const rhs);

// Returns true if the lhs is greater-than-or-equal-to (>=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2f_ge(const vec2f *const lhs, const vec2f *const rhs);

// Returns the scalar dot product of lhs and rhs.
float vec2f_dot_product(const vec2f *const lhs, const vec2f *const rhs);

// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
float vec2f_length_squared(const vec2f *const v);

// Computes and returns the vector's magnitude.
float vec2f_length(const vec2f *const v);

// Make a unit vector from an existing vector.
vec2f vec2f_unit(const vec2f *const v);

// Normalize the vector (make it a unit vector) and return its original length.
float vec2f_normalize(vec2f *const v);

// Calculates a counter-clockwise rotation of the vector about the Z-axis.
// x' = x cos(Theta) - y sin(Theta)
// y' = x sin(Theta) + y cos(Theta)
vec2f vec2f_rotate_counter_clockwise(const vec2f *const v, const float radians);

// Calculates a clockwise rotation of the vector about the Z-axis.
// x' = x  cos(Theta) + y sin(Theta)
// y' = x -sin(Theta) + y cos(Theta)
vec2f vec2f_rotate_clockwise(const vec2f *const v, const float radians);

// Negates all elements of a vector and returns the result.
vec2f vec2f_negate(const vec2f *const v);

// Absolute value function.
vec2f vec2f_abs(const vec2f *const v);
