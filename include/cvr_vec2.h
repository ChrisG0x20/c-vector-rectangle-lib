//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

typedef union vec2_s
{
    struct
    {
        double x;
        double y;
    };
    struct
    {
        double width;
        double height;
    };
    struct
    {
        double s;
        double t;
    };
    double elem[2];
} vec2;

// Returns a vector with all elements set to zero.
vec2 vec2_zero(void);

// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void vec2_copy_array(vec2 *const dst, const double *const src, const size_t count);

// Fill all elements of the destination vector with the same scalar value.
void vec2_fill(vec2 *const dst, const double src);

// Swaps the contents of two vectors.
void vec2_swap(vec2 *const lhs, vec2 *const rhs);

// Returns a vector with elements swizzled from the original.
vec2 vec2_swizzle(const vec2 *const v, const unsigned int e0, const unsigned int e1);

// Add vectors and return the result.
vec2 vec2_add(const vec2 *const lhs, const vec2 *const rhs);

// Add the right-hand vector to the left-hand vector.
void vec2_add_assign(vec2 *const lhs, const vec2 *const rhs);

// Add a scalar value to each element of a vector and return the result.
vec2 vec2_add_scalar(const vec2 *const v, const double scalar);

// Add a scalar value to each element of a vector.
void vec2_add_assign_scalar(vec2 *const v, const double scalar);

// Subtract the right-hand vector from the left-hand and return the result.
vec2 vec2_subtract(const vec2 *const lhs, const vec2 *const rhs);

// Subtract the right-hand vector from the left-hand vector.
void vec2_subtract_assign(vec2 *const lhs, const vec2 *const rhs);

// Subtract a scalar value from each element of a vector and return the result.
vec2 vec2_subtract_scalar(const vec2 *const v, const double scalar);

// Subtract a scalar value from each element of a vector.
void vec2_subtract_assign_scalar(vec2 *const v, const double scalar);

// Multiply vectors and return the result.
vec2 vec2_multiply(const vec2 *const lhs, const vec2 *const rhs);

// Multiply vectors and store the product in the left-hand vector.
void vec2_multiply_assign(vec2 *const lhs, const vec2 *const rhs);

// Multiply each element of a vector by a scalar and return the result.
vec2 vec2_multiply_scalar(const vec2 *const v, const double scalar);

// Multiply each element of a vector by a scalar.
void vec2_multiply_assign_scalar(vec2 *const v, const double scalar);

// Divide the left-hand by the right-hand and return the result.
vec2 vec2_divide(const vec2 *const lhs, const vec2 *const rhs);

// Divide the left-hand by the right-hand vector.
void vec2_divide_assign(vec2 *const lhs, const vec2 *const rhs);

// Divide each element of a vector by a scalar and return the result.
vec2 vec2_divide_scalar(const vec2 *const v, const double scalar);

// Divide each element of a vector by a scalar.
void vec2_divide_assign_scalar(vec2 *const v, const double scalar);

// Prints the vector to a string.
int vec2_sprintf(char *const str, const size_t count, const vec2 *const v);

// Prints the vector to a string.
int vec2_swprintf(wchar_t *const str, const size_t count, const vec2 *const v);

// Returns true if the two vectors are equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2_eq(const vec2 *const lhs, const vec2 *const rhs);

// Returns true if the two vectors are not equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2_ne(const vec2 *const lhs, const vec2 *const rhs);

// Returns true if the lhs is less-than (<) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2_lt(const vec2 *const lhs, const vec2 *const rhs);

// Returns true if the lhs is less-than-or-equal-to (<=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2_le(const vec2 *const lhs, const vec2 *const rhs);

// Returns true if the lhs is greater-than (>) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2_gt(const vec2 *const lhs, const vec2 *const rhs);

// Returns true if the lhs is greater-than-or-equal-to (>=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool vec2_ge(const vec2 *const lhs, const vec2 *const rhs);

// Returns the scalar dot product of lhs and rhs.
double vec2_dot_product(const vec2 *const lhs, const vec2 *const rhs);

// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
double vec2_length_squared(const vec2 *const v);

// Computes and returns the vector's magnitude.
double vec2_length(const vec2 *const v);

// Make a unit vector from an existing vector.
vec2 vec2_unit(const vec2 *const v);

// Normalize the vector (make it a unit vector) and return its original length.
double vec2_normalize(vec2 *const v);

// Calculates a counter-clockwise rotation of the vector about the Z-axis.
// x' = x cos(Theta) - y sin(Theta)
// y' = x sin(Theta) + y cos(Theta)
vec2 vec2_rotate_counter_clockwise(const vec2 *const v, const double radians);

// Calculates a clockwise rotation of the vector about the Z-axis.
// x' = x  cos(Theta) + y sin(Theta)
// y' = x -sin(Theta) + y cos(Theta)
vec2 vec2_rotate_clockwise(const vec2 *const v, const double radians);

// Negates all elements of a vector and returns the result.
vec2 vec2_negate(const vec2 *const v);

// Absolute value function.
vec2 vec2_abs(const vec2 *const v);
