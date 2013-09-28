//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union vec3f_s
{
    struct
    {
        float x;
        float y;
        float z;
    };
    struct
    {
        float width;
        float height;
        float depth;
    };
    struct
    {
        float s;
        float t;
        float p;
    };
    struct
    {
        float r;
        float g;
        float b;
    };
    float elem[3];
} vec3f;

// Returns a vector with all elements set to zero.
vec3f vec3f_zero();

// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void vec3f_copy_array(vec3f *const dst, const float *const src, const size_t count);

// Fill all elements of the destination vector with the same scalar value.
void vec3f_fill(vec3f *const dst, const float src);

// Swaps the contents of two vectors.
void vec3f_swap(vec3f *const lhs, vec3f *const rhs);

// Returns a vector with elements swizzled from the original.
vec3f vec3f_swizzle(const vec3f *const v, const unsigned int e0, const unsigned int e1, const unsigned int e2);

// Add vectors and return the result.
vec3f vec3f_add(const vec3f *const lhs, const vec3f *const rhs);

// Add the right-hand vector to the left-hand vector.
void vec3f_add_assign(vec3f *const lhs, const vec3f *const rhs);

// Add a scalar value to each element of a vector and return the result.
vec3f vec3f_add_scalar(const vec3f *const v, const float scalar);

// Add a scalar value to each element of a vector.
void vec3f_add_assign_scalar(vec3f *const v, const float scalar);

// Subtract the right-hand vector from the left-hand and return the result.
vec3f vec3f_subtract(const vec3f *const lhs, const vec3f *const rhs);

// Subtract the right-hand vector from the left-hand vector.
void vec3f_subtract_assign(vec3f *const lhs, const vec3f *const rhs);

// Subtract a scalar value from each element of a vector and return the result.
vec3f vec3f_subtract_scalar(const vec3f *const v, const float scalar);

// Subtract a scalar value from each element of a vector.
void vec3f_subtract_assign_scalar(vec3f *const v, const float scalar);

// Multiply vectors and return the result.
vec3f vec3f_multiply(const vec3f *const lhs, const vec3f *const rhs);

// Multiply vectors and store the product in the left-hand vector.
void vec3f_multiply_assign(vec3f *const lhs, const vec3f *const rhs);

// Multiply each element of a vector by a scalar and return the result.
vec3f vec3f_multiply_scalar(const vec3f *const v, const float scalar);

// Multiply each element of a vector by a scalar.
void vec3f_multiply_assign_scalar(vec3f *const v, const float scalar);

// Divide the left-hand by the right-hand and return the result.
vec3f vec3f_divide(const vec3f *const lhs, const vec3f *const rhs);

// Divide the left-hand by the right-hand vector.
void vec3f_divide_assign(vec3f *const lhs, const vec3f *const rhs);

// Divide each element of a vector by a scalar and return the result.
vec3f vec3f_divide_scalar(const vec3f *const v, const float scalar);

// Divide each element of a vector by a scalar.
void vec3f_divide_assign_scalar(vec3f *const v, const float scalar);

// Prints the vector to a string.
int vec3f_snprintf(char *const str, const size_t count, const vec3f *const v);

// Prints the vector to a string.
int vec3f_swprintf(wchar_t *const str, const size_t count, const vec3f *const v);

// Returns true if the two vectors are equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3f_eq(const vec3f *const lhs, const vec3f *const rhs);

// Returns true if the two vectors are not equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3f_ne(const vec3f *const lhs, const vec3f *const rhs);

// Returns true if the lhs is less-than (<) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3f_lt(const vec3f *const lhs, const vec3f *const rhs);

// Returns true if the lhs is less-than-or-equal-to (<=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3f_le(const vec3f *const lhs, const vec3f *const rhs);

// Returns true if the lhs is greater-than (>) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3f_gt(const vec3f *const lhs, const vec3f *const rhs);

// Returns true if the lhs is greater-than-or-equal-to (>=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3f_ge(const vec3f *const lhs, const vec3f *const rhs);

// Returns the scalar dot product of lhs and rhs.
float vec3f_dot_product(const vec3f *const lhs, const vec3f *const rhs);

// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
float vec3f_length_squared(const vec3f *const v);

// Computes and returns the vector's magnitude.
float vec3f_length(const vec3f *const v);

// Make a unit vector from an existing vector.
vec3f vec3f_unit(const vec3f *const v);

// Normalize the vector (make it a unit vector) and return its original length.
float vec3f_normalize(vec3f *const v);

// Returns the vector cross product of lhs and rhs.
vec3f vec3f_cross_product(const vec3f *const lhs, const vec3f *const rhs);

// Gets the surface normal of three counter-clockwise points in space. 
vec3f vec3f_calc_surface_normal(const vec3f *const v0, const vec3f *const v1, const vec3f *const v2);

// Negates all elements of a vector and returns the result.
vec3f vec3f_negate(const vec3f *const v);

// Absolute value function.
vec3f vec3f_abs(const vec3f *const v);
