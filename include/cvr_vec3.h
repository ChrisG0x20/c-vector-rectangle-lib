//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union vec3_s
{
    struct
    {
        double x;
        double y;
        double z;
    };
    struct
    {
        double width;
        double height;
        double depth;
    };
    struct
    {
        double s;
        double t;
        double p;
    };
    struct
    {
        double r;
        double g;
        double b;
    };
    double elem[3];
} vec3;

// Returns a vector with all elements set to zero.
vec3 vec3_zero();

// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void vec3_copy_array(vec3 *const dst, const double *const src, const size_t count);

// Fill all elements of the destination vector with the same scalar value.
void vec3_fill(vec3 *const dst, const double src);

// Swaps the contents of two vectors.
void vec3_swap(vec3 *const lhs, vec3 *const rhs);

// Returns a vector with elements swizzled from the original.
vec3 vec3_swizzle(const vec3 *const v, const unsigned int e0, const unsigned int e1, const unsigned int e2);

// Add vectors and return the result.
vec3 vec3_add(const vec3 *const lhs, const vec3 *const rhs);

// Add the right-hand vector to the left-hand vector.
void vec3_add_assign(vec3 *const lhs, const vec3 *const rhs);

// Add a scalar value to each element of a vector and return the result.
vec3 vec3_add_scalar(const vec3 *const v, const double scalar);

// Add a scalar value to each element of a vector.
void vec3_add_assign_scalar(vec3 *const v, const double scalar);

// Subtract the right-hand vector from the left-hand and return the result.
vec3 vec3_subtract(const vec3 *const lhs, const vec3 *const rhs);

// Subtract the right-hand vector from the left-hand vector.
void vec3_subtract_assign(vec3 *const lhs, const vec3 *const rhs);

// Subtract a scalar value from each element of a vector and return the result.
vec3 vec3_subtract_scalar(const vec3 *const v, const double scalar);

// Subtract a scalar value from each element of a vector.
void vec3_subtract_assign_scalar(vec3 *const v, const double scalar);

// Multiply vectors and return the result.
vec3 vec3_multiply(const vec3 *const lhs, const vec3 *const rhs);

// Multiply vectors and store the product in the left-hand vector.
void vec3_multiply_assign(vec3 *const lhs, const vec3 *const rhs);

// Multiply each element of a vector by a scalar and return the result.
vec3 vec3_multiply_scalar(const vec3 *const v, const double scalar);

// Multiply each element of a vector by a scalar.
void vec3_multiply_assign_scalar(vec3 *const v, const double scalar);

// Divide the left-hand by the right-hand and return the result.
vec3 vec3_divide(const vec3 *const lhs, const vec3 *const rhs);

// Divide the left-hand by the right-hand vector.
void vec3_divide_assign(vec3 *const lhs, const vec3 *const rhs);

// Divide each element of a vector by a scalar and return the result.
vec3 vec3_divide_scalar(const vec3 *const v, const double scalar);

// Divide each element of a vector by a scalar.
void vec3_divide_assign_scalar(vec3 *const v, const double scalar);

// Prints the vector to a string.
int vec3_snprintf(char *const str, const size_t count, const vec3 *const v);

// Prints the vector to a string.
int vec3_swprintf(wchar_t *const str, const size_t count, const vec3 *const v);

// Returns true if the two vectors are equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3_eq(const vec3 *const lhs, const vec3 *const rhs);

// Returns true if the two vectors are not equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3_ne(const vec3 *const lhs, const vec3 *const rhs);

// Returns true if the lhs is less-than (<) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3_lt(const vec3 *const lhs, const vec3 *const rhs);

// Returns true if the lhs is less-than-or-equal-to (<=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3_le(const vec3 *const lhs, const vec3 *const rhs);

// Returns true if the lhs is greater-than (>) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3_gt(const vec3 *const lhs, const vec3 *const rhs);

// Returns true if the lhs is greater-than-or-equal-to (>=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec3_ge(const vec3 *const lhs, const vec3 *const rhs);

// Returns the scalar dot product of lhs and rhs.
double vec3_dot_product(const vec3 *const lhs, const vec3 *const rhs);

// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
double vec3_length_squared(const vec3 *const v);

// Computes and returns the vector's magnitude.
double vec3_length(const vec3 *const v);

// Make a unit vector from an existing vector.
vec3 vec3_unit(const vec3 *const v);

// Normalize the vector (make it a unit vector) and return its original length.
double vec3_normalize(vec3 *const v);

// Returns the vector cross product of lhs and rhs.
vec3 vec3_cross_product(const vec3 *const lhs, const vec3 *const rhs);

// Gets the surface normal of three counter-clockwise points in space. 
vec3 vec3_calc_surface_normal(const vec3 *const v0, const vec3 *const v1, const vec3 *const v2);

// Negates all elements of a vector and returns the result.
vec3 vec3_negate(const vec3 *const v);

// Absolute value function.
vec3 vec3_abs(const vec3 *const v);
