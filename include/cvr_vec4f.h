//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union vec4f_s
{
    struct
    {
        float x;
        float y;
        float z;
        float w;
    };
    struct
    {
        float s;
        float t;
        float p;
        float q;
    };
    struct
    {
        float r;
        float g;
        float b;
        float a;
    };
    float elem[4];
} vec4f;

// Returns a vector with all elements set to zero.
vec4f vec4f_zero();

// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void vec4f_copy_array(vec4f *const dst, const float *const src, const size_t count);

// Fill all elements of the destination vector with the same scalar value.
void vec4f_fill(vec4f *const dst, const float src);

// Swaps the contents of two vectors.
void vec4f_swap(vec4f *const lhs, vec4f *const rhs);

// Returns a vector with elements swizzled from the original.
vec4f vec4f_swizzle(const vec4f *const v, const unsigned int e0, const unsigned int e1, const unsigned int e2, const unsigned int e3);

// Add vectors and return the result.
vec4f vec4f_add(const vec4f *const lhs, const vec4f *const rhs);

// Add the right-hand vector to the left-hand vector.
void vec4f_add_assign(vec4f *const lhs, const vec4f *const rhs);

// Add a scalar value to each element of a vector and return the result.
vec4f vec4f_add_scalar(const vec4f *const v, const float scalar);

// Add a scalar value to each element of a vector.
void vec4f_add_assign_scalar(vec4f *const v, const float scalar);

// Subtract the right-hand vector from the left-hand and return the result.
vec4f vec4f_subtract(const vec4f *const lhs, const vec4f *const rhs);

// Subtract the right-hand vector from the left-hand vector.
void vec4f_subtract_assign(vec4f *const lhs, const vec4f *const rhs);

// Subtract a scalar value from each element of a vector and return the result.
vec4f vec4f_subtract_scalar(const vec4f *const v, const float scalar);

// Subtract a scalar value from each element of a vector.
void vec4f_subtract_assign_scalar(vec4f *const v, const float scalar);

// Multiply vectors and return the result.
vec4f vec4f_multiply(const vec4f *const lhs, const vec4f *const rhs);

// Multiply vectors and store the product in the left-hand vector.
void vec4f_multiply_assign(vec4f *const lhs, const vec4f *const rhs);

// Multiply each element of a vector by a scalar and return the result.
vec4f vec4f_multiply_scalar(const vec4f *const v, const float scalar);

// Multiply each element of a vector by a scalar.
void vec4f_multiply_assign_scalar(vec4f *const v, const float scalar);

// Divide the left-hand by the right-hand and return the result.
vec4f vec4f_divide(const vec4f *const lhs, const vec4f *const rhs);

// Divide the left-hand by the right-hand vector.
void vec4f_divide_assign(vec4f *const lhs, const vec4f *const rhs);

// Divide each element of a vector by a scalar and return the result.
vec4f vec4f_divide_scalar(const vec4f *const v, const float scalar);

// Divide each element of a vector by a scalar.
void vec4f_divide_assign_scalar(vec4f *const v, const float scalar);

// Prints the vector to a string.
int vec4f_snprintf(char *const str, const size_t count, const vec4f *const v);

// Prints the vector to a string.
int vec4f_swprintf(wchar_t *const str, const size_t count, const vec4f *const v);

// Returns true if the two vectors are equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4f_eq(const vec4f *const lhs, const vec4f *const rhs);

// Returns true if the two vectors are not equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4f_ne(const vec4f *const lhs, const vec4f *const rhs);

// Returns true if the lhs is less-than (<) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4f_lt(const vec4f *const lhs, const vec4f *const rhs);

// Returns true if the lhs is less-than-or-equal-to (<=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4f_le(const vec4f *const lhs, const vec4f *const rhs);

// Returns true if the lhs is greater-than (>) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4f_gt(const vec4f *const lhs, const vec4f *const rhs);

// Returns true if the lhs is greater-than-or-equal-to (>=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4f_ge(const vec4f *const lhs, const vec4f *const rhs);

// Returns the scalar dot product of lhs and rhs.
float vec4f_dot_product(const vec4f *const lhs, const vec4f *const rhs);

// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
float vec4f_length_squared(const vec4f *const v);

// Computes and returns the vector's magnitude.
float vec4f_length(const vec4f *const v);

// Make a unit vector from an existing vector.
vec4f vec4f_unit(const vec4f *const v);

// Normalize the vector (make it a unit vector) and return its original length.
float vec4f_normalize(vec4f *const v);

// Negates all elements of a vector and returns the result.
vec4f vec4f_negate(const vec4f *const v);

// Absolute value function.
vec4f vec4f_abs(const vec4f *const v);
