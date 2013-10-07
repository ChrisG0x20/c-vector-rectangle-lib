Basic Vector Functions
----------------------

```C
// Returns vector with all elements set to zero.
vec vec_zero();
```
- Similar to doing a `memset(&v, 0, sizeof(v));`, but less error prone.

```C
// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void vec_copy_array(vector_t *const dst, const scalar_t *const src, const size_t count);
```
- Used to do a safer copy of part or all of scalar array into a vector. Similar to doing `memcpy(&vec, src, count);`.

```C
// Fill all elements of the destination vector with the same scalar value.
void vec_fill(vector_t *const dst, const scalar_t src);
```
- Use to initialize all elements of a vector to the same scalar value.

```C
// Swaps the contents of two vectors.
void vec_swap(vector_t *const lhs, vector_t *const rhs);
```
- Used to quickly swap the contents of two vectors.

```C
// Returns a vector with elements swizzled from the original.
vector_t vec_swizzle(const vector_t *const v, const unsigned int e0, const unsigned int e1, ...);
```
- Used to swizzle the elements of a vector. The arguments after the source vector represent the elements of the destination vector. Each destination element argument is passed the index of the source vector element to copy. For example, to convert an RGB color to a BGR format color: `bgr = vec3_swizzle(&rgb, 2, 1, 0);`; to make a new point with X and Y values both equal to a source point's Y value: `yy = vec2_swizzle(&xy, 1, 1);`.

```C
vector_t vec_add(const vector_t *const lhs, const vector_t *const rhs);
vector_t vec_subtract(const vector_t *const lhs, const vector_t *const rhs);
vector_t vec_multiply(const vector_t *const lhs, const vector_t *const rhs);
vector_t vec_divide(const vector_t *const lhs, const vector_t *const rhs);
```
- Immutable vector math operations. These are equivalent to:

```
v3 = v1 + v2
v3 = v1 - v2
v3 = v1 * v2
v3 = v1 / v2
```

```C
void vec_add_assign(vector_t *const lhs, const vector_t *const rhs);
void vec_subtract_assign(vector_t *const lhs, const vector_t *const rhs);
void vec_multiply_assign(vector_t *const lhs, const vector_t *const rhs);
void vec_divide_assign(vector_t *const lhs, const vector_t *const rhs);
```
- Mutable vector math operations. These are equivalent to:

```
v1 += v2
v1 -= v2
v1 *= v2
v1 /= v2
```

```C
vector_t vec_add_scalar(const vector_t *const v, const scalar_t scalar);
vector_t vec_subtract_scalar(const vector_t *const v, const scalar_t scalar);
vector_t vec_multiply_scalar(const vector_t *const v, const scalar_t scalar);
vector_t vec_divide_scalar(const vector_t *const v, const scalar_t scalar);
```
- Immutable vector-scalar math operations. These are equivalent to:

```
v2 = v1 + s1
v2 = v1 - s1
v2 = v1 * s1
v2 = v1 / s1
```

```C
// Add a scalar value to each element of a vector.
void vec_add_assign_scalar(vector_t *const v, const scalar_t scalar);
void vec_subtract_assign_scalar(vector_t *const v, const scalar_t scalar);
void vec_multiply_assign_scalar(vector_t *const v, const scalar_t scalar);
void vec_divide_assign_scalar(vector_t *const v, const scalar_t scalar);
```
- Mutable vector-scalar math operations. These are equivalent to:

```
v1 += s1
v1 -= s1
v1 *= s1
v1 /= s1
```

```C
// Prints the vector to a string.
int vec_snprintf(char *const str, const size_t count, const vector_t *const v);
```
- Used to print a vector to a char string.

```C
// Prints the vector to a string.
int vec_swprintf(wchar_t *const str, const size_t count, const vector_t *const v);
```
- Used to print a vector to a wchar_t string.

```C
bool vec_eq(const vector_t *const lhs, const vector_t *const rhs);
bool vec_ne(const vector_t *const lhs, const vector_t *const rhs);
bool vec_lt(const vector_t *const lhs, const vector_t *const rhs);
bool vec_le(const vector_t *const lhs, const vector_t *const rhs);
bool vec_gt(const vector_t *const lhs, const vector_t *const rhs);
bool vec_ge(const vector_t *const lhs, const vector_t *const rhs);
```
- Basic vector comparison functions. These can be used for sorting vectors or for storing vectors in ordered data structures. These functions to *NOT* compare the magnitudes of the vectors. The functions represent these comparison operations:

```
v1 == v2 // eq
v1 != v2 // ne
v1 <  v2 // lt
v1 <= v2 // le
v1 >  v2 // gt
v1 >= v2 // ge
```

```C
// Returns the scalar dot product of lhs and rhs.
scalar_t vec_dot_product(const vector_t *const lhs, const vector_t *const rhs);
```
- Calculates a vector dot product.

```C
// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
scalar_t vec_length_squared(const vector_t *const v);
```
- Calculates a vector's squared length. That is, (length * length). This saves a square root operation if you're only interested in the relative magnitude of a vector.

Functions Valid Only for Floating Point Vector Formats
------------------------------------------------------

```C
// Computes and returns the vector's magnitude.
scalar_t vec_length(const vector_t *const v);
```
- Computes the magnitude, or length, of a vector.

```C
// Make a unit vector from an existing vector.
vector_t vec_unit(const vector_t *const v);
```
- Computes and returns a unit vector with a direction equivalent to the source vector, but with a magnitude equal to 1.0.

```C
// Normalize the vector (make it a unit vector) and return its original length.
scalar_t vec_normalize(vector_t *const v);
```
- Modifies the source vector in-place to convert it into its own unit vector; additionally, returns the original magnitude of the vector.

Functions Valid Only for 2D Floating Point Vector Formats
---------------------------------------------------------

```C
// Calculates a counter-clockwise rotation of the vector about the Z-axis.
// x' = x cos(Theta) - y sin(Theta)
// y' = x sin(Theta) + y cos(Theta)
vector_t vec_rotate_counter_clockwise(const vector_t *const v, const scalar_t radians);
```
- Useful for rotating 2D vertices.

```C
// Calculates a clockwise rotation of the vector about the Z-axis.
// x' = x  cos(Theta) + y sin(Theta)
// y' = x -sin(Theta) + y cos(Theta)
vector_t vec_rotate_clockwise(const vector_t *const v, const scalar_t radians);
```
- Useful for rotating 2D vertices.

Functions Valid Only for 3D Floating Point Vector Formats
---------------------------------------------------------

```C
// Returns the vector cross product of lhs and rhs.
vector_t vec_cross_product(const vector_t *const lhs, const vector_t *const rhs);
```
- Calculates and returns the cross product of two vectors.

```C
// Gets the surface normal of three counter-clockwise points in space. 
vector_t vec_calc_surface_normal(const vector_t *const v0, const vector_t *const v1, const vector_t *const v2);
```
- Calculates and returns a vector perpendicular to the plane specified by the three source vectors.

Functions Valid Only for Signed Vector Formats
----------------------------------------------

```C
// Negates all elements of a vector and returns the result.
vector_t vec_negate(const vector_t *const v);
```
- Returns a negative copy of the source vector. e.g., v2 = -v1

```C
// Absolute value function.
vector_t vec_abs(const vector_t *const v);
```
- Returns an absolute value copy of the source vector. e.g., v2 = abs(v1)

Scalar Type Conversion Functions
--------------------------------

Functions to convert one vector type to another look like this: `vf = vec3_itof(&vi);` There are several conversion functions listed in the header file: `cvr_vec_conv.h`.
