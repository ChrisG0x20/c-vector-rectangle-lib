Basic Rectangle Functions
-------------------------

```C
// Returns a rectangle with all elements set to 0.
raster_recti raster_recti_zero(void);
```
- Similar to doing a `memset(&r, 0, sizeof(r));`, but less error prone.

```C
// Returns a rectangle initialized to location (0, 0) with the specified width and height.
raster_recti raster_recti_init_to_size(const int_fast32_t width, const int_fast32_t height);
```
- Used to quickly create a rectangle of a certain size.

```C
// Returns a rectangle initialized to the specified location and size.
raster_recti raster_recti_init(const int_fast32_t x, const int_fast32_t y, const int_fast32_t width, const int_fast32_t height);
```
- Used to quickly create a rectangle with a specific location and size.

```C
// Returns a rectangle initialized to the specified location with a zero size.
raster_recti raster_recti_init_with_location(const vec2i *const location);
```
- Used to quickly create a rectangle at a specified location.

```C
// Returns a rectangle initialized to location (0, 0) with the specified size.
raster_recti raster_recti_init_with_size(const vec2i *const size);
```
- Used to quickly create a rectangle of a certain size.

```C
// Returns a rectangle initialized to the specified location and size.
raster_recti raster_recti_init_with(const vec2i *const location, const vec2i *const size);
```
- Used to quickly create a rectangle with a specific location and size.

```C
// Calculates and returns the left bound of the rectangle.
int_fast32_t raster_recti_get_left(const raster_recti *const r);
```
- Gets the left bound of the rectangle.

```C
// Sets the left bound of the rectangle.
void raster_recti_set_left(raster_recti *const r, const int_fast32_t value);
```
- Sets the left bound of the rectangle.

```C
// Calculates and returns the right bound of the rectangle.
int_fast32_t raster_recti_get_right(const raster_recti *const r);
```
- Gets the right bound of the rectangle.

```C
// Sets the right bound of the rectangle.
void raster_recti_set_right(raster_recti *const r, const int_fast32_t value);
```
- Sets the right bound of the rectangle.

```C
// Returns true if two rectangles are equivalent.
bool raster_recti_eq(const raster_recti *const lhs, const raster_recti *const rhs);
```
- Returns *true*, if the two rectangles are equal.

```C
// Returns true if two rectangles are not equivalent.
bool raster_recti_ne(const raster_recti *const lhs, const raster_recti *const rhs);
```
- Returns *true*, if the two rectangles are NOT equal.

```C
// Prints the rectangle to a string.
int raster_recti_snprintf(char *const str, const size_t count, const raster_recti *const r);
```
- Used to print a rectangle to a char string.

```C
// Prints the rectangle to a wide-string.
int raster_recti_swprintf(wchar_t *const str, const size_t count, const raster_recti *const r);
```
- Used to print a rectangle to a wchar_t string.

```C
// Calculates and returns the top bound of the rectangle.
int_fast32_t raster_recti_get_top(const raster_recti *const r);
```
- Gets the top bound of the rectangle.

```C
// Sets the top bound of the rectangle.
void raster_recti_set_top(raster_recti *const r, const int_fast32_t value);
```
- Sets the top bound of the rectangle.

```C
// Calculates and returns the bottom bound of the rectangle.
int_fast32_t raster_recti_get_bottom(const raster_recti *const r);
```
- Gets the bottom bound of the rectangle.

```C
// Sets the bottom bound of the rectangle.
void raster_recti_set_bottom(raster_recti *const r, const int_fast32_t value);
```
- Sets the bottom bound of the rectangle.

```C
// Returns true if the specified point is contained within the rectangle.
bool raster_recti_contains(const raster_recti *const r, const vec2i *const p);
```
- Determines whether the given vector is contained within the given rectangle.

```C
// Returns true if the specified rectangles overlap.
bool raster_recti_overlaps(const raster_recti *const lhs, const raster_recti *const rhs);
```
- Determines whether or not two given rectangles overlap at all.

Win32 RECT Interoperation
-------------------------

```C
// Initializes and returns an equivalent Win32 RECT from the specified rectangle.
RECT raster_recti_to_windows_rect(const raster_recti *const r);
```
- Creates a Win32 RECT struct from a raster_recti.

```C
// Initializes and returns an equivalent rectangle from a Win32 RECT.
raster_recti raster_recti_from_windows_rect(const RECT *const r);
```
- Creates a raster_recti from a Win32 RECT struct.

Cocoa CGRect Interoperation
---------------------------

#### NOTE: These functions may be completely wrong for what you're doing:
- Cocoa CGRects get used in coordinates systems with the Y-axis pointing up or down.
- Cocoa CGRects may commonly have negative size values.

```C
// Initializes and returns an equivalent Objective-C CGRect from the specified rectangle.
CGRect raster_recti_to_objc_cgrect(const raster_recti *const r);
```
- Creates a Cocoa CGRect struct from a raster_recti.

```C
// Initializes and returns an equivalent rectangle from an Objective-C CGRect.
raster_recti raster_recti_from_objc_cgrect(const CGRect *const r);
```
- Creates a raster_recti from a Cocoa CGRect struct.

Scalar Type Conversion Functions
--------------------------------

Functions to convert one rectangle type to another look like this: `rf = rect_itof(&ri);` There are several conversion functions listed in the header file: `cvr_rect_conv.h`.
