//
//          Copyright Christopher Gassib 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//
// WARNING: Do not include this file directly from your code.
//
// This file is included by cvr_rect.c to generate rectangle operations based on different scalar types
// and rectangle types. The template code here depends on several macros being defined before this
// code may be expanded correctly.
//

#if defined _MSC_VER && _MSC_VER <= 1700
#pragma warning( push )
#pragma warning( disable : 4204 ) // This warning is out-of-date for C99.
#endif

// Returns a rectangle with all elements set to 0.
rect_t RECT_FUNC(zero)(void)
{
    rect_t result;
    size_t i = 0u;

    for (; i < 4; ++i)
    {
        result.elem[i] = 0;
    }

    return result;
}

// Returns a rectangle initialized to location (0, 0) with the specified width and height.
rect_t RECT_FUNC(init_to_size)(const scalar_t width, const scalar_t height)
{
    rect_t result;

    result.x = 0;
    result.y = 0;
    result.width = width;
    result.height = height;

    return result;
}

// Returns a rectangle initialized to the specified location and size.
rect_t RECT_FUNC(init)(const scalar_t x, const scalar_t y, const scalar_t width, const scalar_t height)
{
    rect_t result;

    result.x = x;
    result.y = y;
    result.width = width;
    result.height = height;

    return result;
}

// Returns a rectangle initialized to the specified location with a zero size.
rect_t RECT_FUNC(init_with_location)(const vector_t *const location)
{
    rect_t result;

    assert(NULL != location);

    result.x        = location->x;
    result.y        = location->y;
    result.width    = 0;
    result.height   = 0;

    return result;
}

// Returns a rectangle initialized to location (0, 0) with the specified size.
rect_t RECT_FUNC(init_with_size)(const vector_t *const size)
{
    rect_t result;

    assert(NULL != size);

    result.x        = 0;
    result.y        = 0;
    result.width    = size->width;
    result.height   = size->height;

    return result;
}

// Returns a rectangle initialized to the specified location and size.
rect_t RECT_FUNC(init_with)(const vector_t *const location, const vector_t *const size)
{
    rect_t result;

    assert(NULL != location);
    assert(NULL != size);

    result.x        = location->x;
    result.y        = location->y;
    result.width    = size->width;
    result.height   = size->height;

    return result;
}

// Calculates and returns the left bound of the rectangle.
scalar_t RECT_FUNC(get_left)(const rect_t *const r)
{
    assert(NULL != r);

    return r->x;
}

// Sets the left bound of the rectangle.
void RECT_FUNC(set_left)(rect_t *const r, const scalar_t value)
{
    assert(NULL != r);

    r->width += r->x - value;
    r->x = value;
}

// Calculates and returns the right bound of the rectangle.
scalar_t RECT_FUNC(get_right)(const rect_t *const r)
{
    assert(NULL != r);

    return r->x + r->width;
}

// Sets the right bound of the rectangle.
void RECT_FUNC(set_right)(rect_t *const r, const scalar_t value)
{
    assert(NULL != r);

    r->width = value - r->x;
}

// Returns true if two rectangles are equivalent.
bool RECT_FUNC(eq)(const rect_t *const lhs, const rect_t *const rhs)
{
    assert(NULL != lhs);
    assert(NULL != rhs);

    return lhs->elem[0] == rhs->elem[0] &&
        lhs->elem[1] == rhs->elem[1] &&
        lhs->elem[2] == rhs->elem[2] &&
        lhs->elem[3] == rhs->elem[3];
}

// Returns true if two rectangles are not equivalent.
bool RECT_FUNC(ne)(const rect_t *const lhs, const rect_t *const rhs)
{
    assert(NULL != lhs);
    assert(NULL != rhs);

    return !RECT_FUNC(eq)(lhs, rhs);
}

// Prints the rectangle to a string.
int RECT_FUNC(snprintf)(char *const str, const size_t count, const rect_t *const r)
{
    assert(NULL != str);
    assert(NULL != r);

    return SNPRINTF(
        str,
        count,
        "( " RECT_FMT_SPEC ", " RECT_FMT_SPEC " ), ( " RECT_FMT_SPEC ", " RECT_FMT_SPEC " )",
        r->elem[0],
        r->elem[1],
        r->elem[2],
        r->elem[3]
    );
}

// Prints the rectangle to a wide-string.
int RECT_FUNC(swprintf)(wchar_t *const str, const size_t count, const rect_t *const r)
{
    assert(NULL != str);
    assert(NULL != r);

    return SWPRINTF(
        str,
        count,
        L"( " RECT_WFMT_SPEC L", " RECT_WFMT_SPEC L" ), ( " RECT_WFMT_SPEC L", " RECT_WFMT_SPEC L" )",
        r->elem[0],
        r->elem[1],
        r->elem[2],
        r->elem[3]
    );
}

#if !defined RASTER_COORDINATES

// Calculates and returns the top bound of the rectangle.
scalar_t RECT_FUNC(get_top)(const rect_t *const r)
{
    assert(NULL != r);

    return r->y + r->height;
}

// Sets the top bound of the rectangle.
void RECT_FUNC(set_top)(rect_t *const r, const scalar_t value)
{
    assert(NULL != r);

    r->height = value - r->y;
}

// Calculates and returns the bottom bound of the rectangle.
scalar_t RECT_FUNC(get_bottom)(const rect_t *const r)
{
    assert(NULL != r);

    return r->y;
}

// Sets the bottom bound of the rectangle.
void RECT_FUNC(set_bottom)(rect_t *const r, const scalar_t value)
{
    assert(NULL != r);

    r->height += r->y - value;
    r->y = value;
}

// Returns true if the specified point is contained within the rectangle.
bool RECT_FUNC(contains)(const rect_t *const r, const vector_t *const p)
{
    assert(NULL != r);
    assert(NULL != p);

    if (p->x < r->x || p->y < r->y)
    {
        return false;
    }

    // NOTE: Inclusive coordinates.
    if (RECT_FUNC(get_right)(r) < p->x || RECT_FUNC(get_top)(r) < p->y)
    {
        return false;
    }

    return true;
}

// Returns true if the specified rectangles overlap.
bool RECT_FUNC(overlaps)(const rect_t *const lhs, const rect_t *const rhs)
{
    assert(NULL != lhs);
    assert(NULL != rhs);

    // NOTE: Inclusive coordinate checks.
    if (RECT_FUNC(get_right)(lhs) < RECT_FUNC(get_left)(rhs) || RECT_FUNC(get_right)(rhs) < RECT_FUNC(get_left)(lhs))
    {
        return false;
    }

    if (RECT_FUNC(get_top)(lhs) < RECT_FUNC(get_bottom)(rhs) || RECT_FUNC(get_top)(rhs) < RECT_FUNC(get_bottom)(lhs))
    {
        return false;
    }

    return true;
}

#else // RASTER_COORDINATES

// Calculates and returns the top bound of the rectangle.
scalar_t RECT_FUNC(get_top)(const rect_t *const r)
{
    assert(NULL != r);

    return r->y;
}

// Sets the top bound of the rectangle.
void RECT_FUNC(set_top)(rect_t *const r, const scalar_t value)
{
    assert(NULL != r);

    r->height += r->y - value;
    r->y = value;
}

// Calculates and returns the bottom bound of the rectangle.
scalar_t RECT_FUNC(get_bottom)(const rect_t *const r)
{
    assert(NULL != r);

    return r->y + r->height;
}

// Sets the bottom bound of the rectangle.
void RECT_FUNC(set_bottom)(rect_t *const r, const scalar_t value)
{
    assert(NULL != r);

    r->height = value - r->y;
}

// Returns true if the specified point is contained within the rectangle.
bool RECT_FUNC(contains)(const rect_t *const r, const vector_t *const p)
{
    assert(NULL != r);
    assert(NULL != p);

    if (p->x < r->x || p->y < r->y)
    {
        return false;
    }

    // NOTE: Exclusive coordinates.
    if (RECT_FUNC(get_right)(r) <= p->x || RECT_FUNC(get_bottom)(r) <= p->y)
    {
        return false;
    }

    return true;
}

// Returns true if the specified rectangles overlap.
bool RECT_FUNC(overlaps)(const rect_t *const lhs, const rect_t *const rhs)
{
    assert(NULL != lhs);
    assert(NULL != rhs);

    // NOTE: Exclusive coordinate checks.
    if (RECT_FUNC(get_right)(lhs) <= RECT_FUNC(get_left)(rhs) || RECT_FUNC(get_right)(rhs) <= RECT_FUNC(get_left)(lhs))
    {
        return false;
    }

    if (RECT_FUNC(get_bottom)(lhs) <= RECT_FUNC(get_top)(rhs) || RECT_FUNC(get_bottom)(rhs) <= RECT_FUNC(get_top)(lhs))
    {
        return false;
    }

    return true;
}

#ifdef _WINDEF_

// Initializes and returns an equivalent Win32 RECT from the specified rectangle.
RECT RECT_FUNC(to_windows_rect)(const rect_t *const r)
{
    RECT result;

    assert(NULL != r);

    result.left     = (LONG)RECT_FUNC(get_left)(r);
    result.top      = (LONG)RECT_FUNC(get_top)(r);
    result.right    = (LONG)RECT_FUNC(get_right)(r);
    result.bottom   = (LONG)RECT_FUNC(get_bottom)(r);
    return result;
}

// Initializes and returns an equivalent rectangle from a Win32 RECT.
rect_t RECT_FUNC(from_windows_rect)(const RECT *const r)
{
    assert(NULL != r);

    return RECT_FUNC(init)(
        (scalar_t)r->left,
        (scalar_t)r->top,
        (scalar_t)r->right - r->left,
        (scalar_t)r->bottom - r->top
        );
}

#endif // _WINDEF_

#ifdef __OBJC__

// Initializes and returns an equivalent Objective-C CGRect from the specified rectangle.
CGRect RECT_FUNC(to_objc_cgrect)(const rect_t *const r)
{
    CGRect result;

    assert(NULL != r);

    result.origin.x     = r->x;
    result.origin.y     = r->y;
    result.size.width   = r->width;
    result.size.height  = r->height;
    return result;
}

// Initializes and returns an equivalent rectangle from an Objective-C CGRect.
rect_t RECT_FUNC(from_objc_cgrect)(const CGRect *const r)
{
    assert(NULL != r);

    return RECT_FUNC(init)(
        r->origin.x,
        r->origin.y,
        r->size.width,
        r->size.height
        );
}

#endif // __OBJC__

#endif // RASTER_COORDINATES

#if defined _MSC_VER && _MSC_VER <= 1700
#pragma warning( pop ) // 4204
#endif
