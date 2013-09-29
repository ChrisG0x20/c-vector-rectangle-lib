//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union vec4_s
{
    struct
    {
        double x;
        double y;
        double z;
        double w;
    };
    struct
    {
        double s;
        double t;
        double p;
        double q;
    };
    struct
    {
        double r;
        double g;
        double b;
        double a;
    };
    double elem[4];
} vec4;

// Returns a vector with all elements set to zero.
vec4 vec4_zero(void);

// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void vec4_copy_array(vec4 *const dst, const double *const src, const size_t count);

// Fill all elements of the destination vector with the same scalar value.
void vec4_fill(vec4 *const dst, const double src);

// Swaps the contents of two vectors.
void vec4_swap(vec4 *const lhs, vec4 *const rhs);

// Returns a vector with elements swizzled from the original.
vec4 vec4_swizzle(const vec4 *const v, const unsigned int e0, const unsigned int e1, const unsigned int e2, const unsigned int e3);

// Add vectors and return the result.
vec4 vec4_add(const vec4 *const lhs, const vec4 *const rhs);

// Add the right-hand vector to the left-hand vector.
void vec4_add_assign(vec4 *const lhs, const vec4 *const rhs);

// Add a scalar value to each element of a vector and return the result.
vec4 vec4_add_scalar(const vec4 *const v, const double scalar);

// Add a scalar value to each element of a vector.
void vec4_add_assign_scalar(vec4 *const v, const double scalar);

// Subtract the right-hand vector from the left-hand and return the result.
vec4 vec4_subtract(const vec4 *const lhs, const vec4 *const rhs);

// Subtract the right-hand vector from the left-hand vector.
void vec4_subtract_assign(vec4 *const lhs, const vec4 *const rhs);

// Subtract a scalar value from each element of a vector and return the result.
vec4 vec4_subtract_scalar(const vec4 *const v, const double scalar);

// Subtract a scalar value from each element of a vector.
void vec4_subtract_assign_scalar(vec4 *const v, const double scalar);

// Multiply vectors and return the result.
vec4 vec4_multiply(const vec4 *const lhs, const vec4 *const rhs);

// Multiply vectors and store the product in the left-hand vector.
void vec4_multiply_assign(vec4 *const lhs, const vec4 *const rhs);

// Multiply each element of a vector by a scalar and return the result.
vec4 vec4_multiply_scalar(const vec4 *const v, const double scalar);

// Multiply each element of a vector by a scalar.
void vec4_multiply_assign_scalar(vec4 *const v, const double scalar);

// Divide the left-hand by the right-hand and return the result.
vec4 vec4_divide(const vec4 *const lhs, const vec4 *const rhs);

// Divide the left-hand by the right-hand vector.
void vec4_divide_assign(vec4 *const lhs, const vec4 *const rhs);

// Divide each element of a vector by a scalar and return the result.
vec4 vec4_divide_scalar(const vec4 *const v, const double scalar);

// Divide each element of a vector by a scalar.
void vec4_divide_assign_scalar(vec4 *const v, const double scalar);

// Prints the vector to a string.
int vec4_snprintf(char *const str, const size_t count, const vec4 *const v);

// Prints the vector to a string.
int vec4_swprintf(wchar_t *const str, const size_t count, const vec4 *const v);

// Returns true if the two vectors are equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4_eq(const vec4 *const lhs, const vec4 *const rhs);

// Returns true if the two vectors are not equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4_ne(const vec4 *const lhs, const vec4 *const rhs);

// Returns true if the lhs is less-than (<) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4_lt(const vec4 *const lhs, const vec4 *const rhs);

// Returns true if the lhs is less-than-or-equal-to (<=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4_le(const vec4 *const lhs, const vec4 *const rhs);

// Returns true if the lhs is greater-than (>) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4_gt(const vec4 *const lhs, const vec4 *const rhs);

// Returns true if the lhs is greater-than-or-equal-to (>=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec4_ge(const vec4 *const lhs, const vec4 *const rhs);

// Returns the scalar dot product of lhs and rhs.
double vec4_dot_product(const vec4 *const lhs, const vec4 *const rhs);

// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
double vec4_length_squared(const vec4 *const v);

// Computes and returns the vector's magnitude.
double vec4_length(const vec4 *const v);

// Make a unit vector from an existing vector.
vec4 vec4_unit(const vec4 *const v);

// Normalize the vector (make it a unit vector) and return its original length.
double vec4_normalize(vec4 *const v);

// Negates all elements of a vector and returns the result.
vec4 vec4_negate(const vec4 *const v);

// Absolute value function.
vec4 vec4_abs(const vec4 *const v);
