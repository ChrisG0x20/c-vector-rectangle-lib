//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//
// WARNING: Do not include this file directly from your code.
//
// This file is included by cvr_vec.c to generate vector operations based on different scalar types
// and vector dimension. The template code here depends on several macros being defined before this
// code may be expanded correctly.
//

// Returns vector with all elements set to zero.
vector_t VEC_FUNC(zero)(void)
{
    size_t i = 0u;
    vector_t zero_vector;

    for (; i < DIMENSION; ++i)
    {
        zero_vector.elem[i] = (scalar_t)0.0;
    }

    return zero_vector;
}

// Copy the elements of the source array to the elements of the destination vector and zero any remaining elements.
void VEC_FUNC(copy_array)(vector_t *const dst, const scalar_t *const src, const size_t count)
{
    size_t i = 0u;

    assert(NULL != dst);
    assert(NULL != src);
    assert(count <= DIMENSION);

    for (; i < count && i < DIMENSION; ++i)
    {
        dst->elem[i] = src[i];
    }

    for (; i < DIMENSION; ++i)
    {
        dst->elem[i] = (scalar_t)0.0;
    }
}

// Fill all elements of the destination vector with the same scalar value.
void VEC_FUNC(fill)(vector_t *const dst, const scalar_t src)
{
    size_t i = 0u;

    assert(NULL != dst);

    for (; i < DIMENSION; ++i)
    {
        dst->elem[i] = src;
    }
}

// Swaps the contents of two vectors.
void VEC_FUNC(swap)(vector_t *const lhs, vector_t *const rhs)
{
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        const scalar_t temp = lhs->elem[i];
        lhs->elem[i] = rhs->elem[i];
        rhs->elem[i] = temp;
    }
}

// The swizzle function implementation depends heavily on x-macro tricks; er, technique.
#define ADD_ELEM_TO_ARGS(i) , const unsigned int e##i
#define ASSERT_RANGE(i) assert(e##i < DIMENSION);
#define DO_SWIZZLE(i) result.elem[i] = v->elem[e##i];

// Returns a vector with elements swizzled from the original.
vector_t VEC_FUNC(swizzle)(const vector_t *const v, const unsigned int e0 FOR_EACH_ADDITIONAL_ELEM(ADD_ELEM_TO_ARGS))
{
    vector_t result = VEC_FUNC(zero)();

    assert(NULL != v);
    assert(e0 < DIMENSION);
    FOR_EACH_ADDITIONAL_ELEM(ASSERT_RANGE);

    result.elem[0] = v->elem[e0];
    FOR_EACH_ADDITIONAL_ELEM(DO_SWIZZLE);

    return result;
}

#undef DO_SWIZZLE
#undef ASSERT_RANGE
#undef ADD_ELEM_TO_ARGS

// Add vectors and return the result.
vector_t VEC_FUNC(add)(const vector_t *const lhs, const vector_t *const rhs)
{
    vector_t result = VEC_FUNC(zero)();
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = lhs->elem[i] + rhs->elem[i];
    }

    return result;
}

// Add the right-hand vector to the left-hand vector.
void VEC_FUNC(add_assign)(vector_t *const lhs, const vector_t *const rhs)
{
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        lhs->elem[i] += rhs->elem[i];
    }
}

// Add a scalar value to each element of a vector and return the result.
vector_t VEC_FUNC(add_scalar)(const vector_t *const v, const scalar_t scalar)
{
    vector_t result = VEC_FUNC(zero)();
    size_t i = 0u;

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = v->elem[i] + scalar;
    }

    return result;
}

// Add a scalar value to each element of a vector.
void VEC_FUNC(add_assign_scalar)(vector_t *const v, const scalar_t scalar)
{
    size_t i = 0u;

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        v->elem[i] += scalar;
    }
}

// Subtract the right-hand vector from the left-hand and return the result.
vector_t VEC_FUNC(subtract)(const vector_t *const lhs, const vector_t *const rhs)
{
    vector_t result = VEC_FUNC(zero)();
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = lhs->elem[i] - rhs->elem[i];
    }

    return result;
}

// Subtract the right-hand vector from the left-hand vector.
void VEC_FUNC(subtract_assign)(vector_t *const lhs, const vector_t *const rhs)
{
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        lhs->elem[i] -= rhs->elem[i];
    }
}

// Subtract a scalar value from each element of a vector and return the result.
vector_t VEC_FUNC(subtract_scalar)(const vector_t *const v, const scalar_t scalar)
{
    vector_t result = VEC_FUNC(zero)();
    size_t i = 0u;

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = v->elem[i] - scalar;
    }

    return result;
}

// Subtract a scalar value from each element of a vector.
void VEC_FUNC(subtract_assign_scalar)(vector_t *const v, const scalar_t scalar)
{
    size_t i = 0u;

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        v->elem[i] -= scalar;
    }
}

// Multiply vectors and return the result.
vector_t VEC_FUNC(multiply)(const vector_t *const lhs, const vector_t *const rhs)
{
    vector_t result = VEC_FUNC(zero)();
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = lhs->elem[i] * rhs->elem[i];
    }

    return result;
}

// Multiply vectors and store the product in the left-hand vector.
void VEC_FUNC(multiply_assign)(vector_t *const lhs, const vector_t *const rhs)
{
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        lhs->elem[i] *= rhs->elem[i];
    }
}

// Multiply each element of a vector by a scalar and return the result.
vector_t VEC_FUNC(multiply_scalar)(const vector_t *const v, const scalar_t scalar)
{
    vector_t result = VEC_FUNC(zero)();
    size_t i = 0u;

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = v->elem[i] * scalar;
    }

    return result;
}

// Multiply each element of a vector by a scalar.
void VEC_FUNC(multiply_assign_scalar)(vector_t *const v, const scalar_t scalar)
{
    size_t i = 0u;

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        v->elem[i] *= scalar;
    }
}

// Divide the left-hand by the right-hand and return the result.
vector_t VEC_FUNC(divide)(const vector_t *const lhs, const vector_t *const rhs)
{
    vector_t result = VEC_FUNC(zero)();
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = lhs->elem[i] / rhs->elem[i];
    }

    return result;
}

// Divide the left-hand by the right-hand vector.
void VEC_FUNC(divide_assign)(vector_t *const lhs, const vector_t *const rhs)
{
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        lhs->elem[i] /= rhs->elem[i];
    }
}

// Divide each element of a vector by a scalar and return the result.
vector_t VEC_FUNC(divide_scalar)(const vector_t *const v, const scalar_t scalar)
{
    vector_t result = VEC_FUNC(zero)();
    size_t i = 0u;

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = v->elem[i] / scalar;
    }

    return result;
}

// Divide each element of a vector by a scalar.
void VEC_FUNC(divide_assign_scalar)(vector_t *const v, const scalar_t scalar)
{
    size_t i = 0u;

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        v->elem[i] /= scalar;
    }
}

// A little x-macro exapansion magic of the vector's elements for the sprintf format string and its
// arguments.
#define ADD_ELEM_TO_ARGS(i) , v->elem[i]
#define ADD_FMT_SPEC(x) ", " VEC_FMT_SPEC

// Prints the vector to a string.
int VEC_FUNC(snprintf)(char *const str, const size_t count, const vector_t *const v)
{
    const char fmt[] = "( " VEC_FMT_SPEC FOR_EACH_ADDITIONAL_ELEM(ADD_FMT_SPEC) " )";

    assert(NULL != str);
    assert(NULL != v);

    return SNPRINTF(str, count, fmt, v->elem[0] FOR_EACH_ADDITIONAL_ELEM(ADD_ELEM_TO_ARGS));
}

#undef ADD_FMT_SPEC
#define ADD_WFMT_SPEC(x) L", " VEC_WFMT_SPEC

// Prints the vector to a string.
int VEC_FUNC(swprintf)(wchar_t *const str, const size_t count, const vector_t *const v)
{
    const wchar_t fmt[] = L"( " VEC_WFMT_SPEC FOR_EACH_ADDITIONAL_ELEM(ADD_WFMT_SPEC) L" )";

    assert(NULL != str);
    assert(NULL != v);

    return SWPRINTF(str, count, fmt, v->elem[0] FOR_EACH_ADDITIONAL_ELEM(ADD_ELEM_TO_ARGS));
}

#undef ADD_WFMT_SPEC
#undef ADD_ELEM_TO_ARGS

// Returns true if the two vectors are equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool VEC_FUNC(eq)(const vector_t *const lhs, const vector_t *const rhs)
{
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        if (lhs->elem[i] != rhs->elem[i])
        {
            return false;
        }
    }

    return true;
}

// Returns true if the two vectors are not equal. NOTE: This does not compare magnitudes, but is valid for sorting.
bool VEC_FUNC(ne)(const vector_t *const lhs, const vector_t *const rhs)
{
    assert(NULL != lhs);
    assert(NULL != rhs);

    return !VEC_FUNC(eq)(lhs, rhs);
}

// Returns true if the lhs is less-than (<) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool VEC_FUNC(lt)(const vector_t *const lhs, const vector_t *const rhs)
{
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION - 1; ++i)
    {
        if (lhs->elem[i] < rhs->elem[i])
        {
            return true;
        }

        if (lhs->elem[i] != rhs->elem[i])
        {
            return false;
        }
    }

    return lhs->elem[DIMENSION - 1] < rhs->elem[DIMENSION - 1];
}

// Returns true if the lhs is less-than-or-equal-to (<=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool VEC_FUNC(le)(const vector_t *const lhs, const vector_t *const rhs)
{
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION - 1; ++i)
    {
        if (lhs->elem[i] < rhs->elem[i])
        {
            return true;
        }

        if (lhs->elem[i] != rhs->elem[i])
        {
            return false;
        }
    }

    return lhs->elem[DIMENSION - 1] <= rhs->elem[DIMENSION - 1];
}

// Returns true if the lhs is greater-than (>) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool VEC_FUNC(gt)(const vector_t *const lhs, const vector_t *const rhs)
{
    assert(NULL != lhs);
    assert(NULL != rhs);

    return !VEC_FUNC(le)(lhs, rhs);
}

// Returns true if the lhs is greater-than-or-equal-to (>=) the rhs. NOTE: This does not compare magnitudes, but is valid for sorting.
bool VEC_FUNC(ge)(const vector_t *const lhs, const vector_t *const rhs)
{
    assert(NULL != lhs);
    assert(NULL != rhs);

    return !VEC_FUNC(lt)(lhs, rhs);
}

// Returns the scalar dot product of lhs and rhs.
scalar_t VEC_FUNC(dot_product)(const vector_t *const lhs, const vector_t *const rhs)
{
    scalar_t dotProduct = (scalar_t)0.0;
    size_t i = 0u;

    assert(NULL != lhs);
    assert(NULL != rhs);

    for (; i < DIMENSION; ++i)
    {
        dotProduct += lhs->elem[i] * rhs->elem[i];
    }

    return dotProduct;
}

// Returns the square of the vector's magnitude. NOTE: This function is faster than vec_length() if you only care about relative magnitude.
scalar_t VEC_FUNC(length_squared)(const vector_t *const v)
{
    size_t i = 0u;
    scalar_t length2 = (scalar_t)0.0;

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        length2 += v->elem[i] * v->elem[i];
    }
 
    return length2;
}

////////////////////////////////////////////////////////////////
// Functions not valid for non-floating point vector formats. //
////////////////////////////////////////////////////////////////
#if !defined SCALAR_INTEGER && !defined SCALAR_UNSIGNED

// Computes and returns the vector's magnitude.
scalar_t VEC_FUNC(length)(const vector_t *const v)
{
    assert(NULL != v);

    return (scalar_t)VEC_SQRT(VEC_FUNC(length_squared)(v));
}

// Make a unit vector from an existing vector.
vector_t VEC_FUNC(unit)(const vector_t *const v)
{
    const scalar_t length = VEC_FUNC(length)(v);
    vector_t result;

    assert(NULL != v);

    result = *v;

    if (0.0 != length)
    {
        const scalar_t inverse_length = ((scalar_t)1.0) / length;
        VEC_FUNC(multiply_assign_scalar)(&result, inverse_length);
    }

    return result;
}

// Normalize the vector (make it a unit vector) and return its original length.
scalar_t VEC_FUNC(normalize)(vector_t *const v)
{
    const scalar_t length = VEC_FUNC(length)(v);

    assert(NULL != v);

    if (0.0 != length)
    {
        const scalar_t inverse_length = ((scalar_t)1.0) / length;
        VEC_FUNC(multiply_assign_scalar)(v, inverse_length);
    }

    return length;
}

/////////////////////////////////////////////////
// Functions valid only for 2D vector formats. //
/////////////////////////////////////////////////
#if DIMENSION == 2u

// Calculates a counter-clockwise rotation of the vector about the Z-axis.
// x' = x cos(Theta) - y sin(Theta)
// y' = x sin(Theta) + y cos(Theta)
vector_t VEC_FUNC(rotate_counter_clockwise)(const vector_t *const v, const scalar_t radians)
{
    vector_t result = VEC_FUNC(zero)();
    const scalar_t cos_theta = VEC_COS(radians);
    const scalar_t sin_theta = VEC_SIN(radians);

    assert(NULL != v);

    result.elem[0] = v->elem[0] * cos_theta - v->elem[1] * sin_theta;
    result.elem[1] = v->elem[0] * sin_theta + v->elem[1] * cos_theta;

    return result;
}

// Calculates a clockwise rotation of the vector about the Z-axis.
// x' = x  cos(Theta) + y sin(Theta)
// y' = x -sin(Theta) + y cos(Theta)
vector_t VEC_FUNC(rotate_clockwise)(const vector_t *const v, const scalar_t radians)
{
    vector_t result = VEC_FUNC(zero)();
    const scalar_t cos_theta = VEC_COS(radians);
    const scalar_t sin_theta = VEC_SIN(radians);

    assert(NULL != v);

    result.elem[0] = v->elem[0] *  cos_theta + v->elem[1] * sin_theta;
    result.elem[1] = v->elem[0] * -sin_theta + v->elem[1] * cos_theta;

    return result;
}

#endif // DIMENSION == 2u

/////////////////////////////////////////////////
// Functions valid only for 3D vector formats. //
/////////////////////////////////////////////////
#if DIMENSION == 3u

// Returns the vector cross product of lhs and rhs.
vector_t VEC_FUNC(cross_product)(const vector_t *const lhs, const vector_t *const rhs)
{
    vector_t result = VEC_FUNC(zero)();

    assert(NULL != lhs);
    assert(NULL != rhs);

    result.elem[0] = lhs->elem[1] * rhs->elem[2] - lhs->elem[2] * rhs->elem[1];
    result.elem[1] = lhs->elem[2] * rhs->elem[0] - lhs->elem[0] * rhs->elem[2];
    result.elem[2] = lhs->elem[0] * rhs->elem[1] - lhs->elem[1] * rhs->elem[0];

    return result;
}

// Gets the surface normal of three counter-clockwise points in space. 
vector_t VEC_FUNC(calc_surface_normal)(const vector_t *const v0, const vector_t *const v1, const vector_t *const v2)
{
    const vector_t first = VEC_FUNC(subtract)(v0, v1);
    const vector_t second = VEC_FUNC(subtract)(v1, v2);
    const vector_t xproduct = VEC_FUNC(cross_product)(&first, &second);
    return VEC_FUNC(unit)(&xproduct);
}

#endif // DIMENSION == 3u

#endif // !defined SCALAR_INTEGER && !defined SCALAR_UNSIGNED

//////////////////////////////////////////////////////
// Functions not valid for unsigned vector formats. //
//////////////////////////////////////////////////////
#ifndef SCALAR_UNSIGNED

// Negates all elements of a vector and returns the result.
vector_t VEC_FUNC(negate)(const vector_t *const v)
{
    size_t i = 0u;
    vector_t result = VEC_FUNC(zero)();

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = -v->elem[i];
    }

    return result;
}

// Absolute value function.
vector_t VEC_FUNC(abs)(const vector_t *const v)
{
    size_t i = 0u;
    vector_t result = VEC_FUNC(zero)();

    assert(NULL != v);

    for (; i < DIMENSION; ++i)
    {
        result.elem[i] = VEC_ABS(v->elem[i]);
    }

    return result;
}

#endif // SCALAR_UNSIGNED
