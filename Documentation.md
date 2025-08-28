FAIR WARNING: This may not remain up-to-date with the source code


## Classes:

- ### `Position`
Defines a Position (x, y)

**Example**:
```cpp
// Creates a position (4, 5)
Position pos;
pos.x = 4;
pos.y = 5;

// also creates a Position (4, 5) but is more readable
Position pos2(4, 5);
```

<br>

- ### `Color`
A class that holds a color value in (r, g, b) format.

`Color` values are in range [0, 255]

**Example**:
```cpp
Color c1(255, 0, 0); // pure red
Color c2(62, 141, 179); // a nice blue color
```

You may refer to external sources to generate a color instead of having to guess the values.

I prefer something like [this website](https://rgbcolorpicker.com/).




<br><br>




## Types

- `PointsArr`

`typedef std::vector <Position> PointsArr;`

Provides an easier way to define a vector containing `Position`s.

**Example**:
```cpp
// instead of writing....
std::vector <Position> array_of_points = {
    Position(0, 0),
    Position(10, 10),
    Position(20, 30),
    Position(40, 10)
};

// write....
PointsArr array_of_points = {
    Position(0, 0),
    Position(10, 10),
    Position(20, 30),
    Position(40, 10)
};
```

<br>

- `uint`

`typedef unsigned int uint;`

`uint` is just a shorthand version of `unsigned int`.




<br><br>




## Methods:

- ### initialize

`void initialize()`

Properly initializes the terminal window on Windows platforms.

Required to enable [virtual terminal processing](https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences) on windows platforms, which the header file uses to set position and color.


<br>

- ### draw_pixel

`void draw_pixel(uint x_coord, uint y_coord, Color color = Color(255, 255, 255)) {`

Draws a pixel at the specified coordinates with the specified `color`.

**Example**:
```cpp
draw_pixel(5, 9, Color(255, 255, 255)); // draws a white pixel at (5, 9)
```

<br>

- ### draw_pixel

`void draw_pixel(Position pos, Color color = Color(255, 255, 255)) {`

Draws a pixel at the specified `Position` with the specified `color`.

**Example**:
```cpp
Position pos(3, 8);

draw_pixel(pos, Color(255, 0, 0)); // draws a red pixel at (3, 8)
```

<br>

- ### draw_string

`void draw_string(std::string draw_this_string, uint x_coord, uint y_coord, Color bg_color = Color(0, 0, 0), Color fg_color = Color(255, 255, 255))`

Draws text (string) starting from the specified location with the specified `bg_color` (background color) and `fg_color` (foreground color).

**Example**:
```cpp
// draws "hello world" starting from (5, 9) with black background and green foreground
draw_string("hello world", 5, 9, Color(0, 0, 0), Color(0, 255, 0));
```

<br>

- ### draw_string

`void draw_string(std::string draw_this_string, Position pos, Color bg_color = Color(0, 0, 0), Color fg_color = Color(255, 255, 255))`

Draws text (string) starting from the specified `Position` with the specified `bg_color` (background color) and `fg_color` (foreground color).

**Example**:
```cpp
Position str_pos(10, 10);

// draws "hello world" starting from (10, 10) with black background and blue foreground.
draw_string("hello world", str_pos, Color(0, 0, 0), Color(0, 0, 255));
```

<br>

- ### draw_line

`void draw_line(Position start_point, Position end_point, Color color = Color(255, 255, 255))`

Draws a line joining two `Position`s with the specified `color`.

**Example**:
```cpp
Position pos_a(2, 2);
Position pos_b(5, 6);

draw_line(pos_a, pos_b, Color(227, 28, 149)); // draws a pink-ish line joining pos_a & pos_b
```

<br>

- ### draw_poly

`void draw_poly(PointsArr points, bool closed = false, Color color = Color(255, 255, 255))`

Draws a polygon joining all points in `PointsArr` vector with the specified `color`.

The polygon may be open (`closed = false`) or closed (`closed = true`).

**Example**:
```cpp
PointsArr points_arr = {
    Position(0, 0),
    Position(5, 10),
    Position(10, 5),
    Position(20, 20)
};

// draws an open polygon with a green-ish color.
draw_poly(points_arr, false, Color(78, 227, 28));
```

<br>

- ### draw_circle

`void draw_circle(Position centre, int radius, bool filled = false, Color color = Color(255, 255, 255))`

Draws a circle at specified `centre` `Position` with a given `radius` with the specified `color`.

It may or may not be filled.

**Example**:
```cpp
Position centre_pos(10, 10);
int radius = 5;

draw_circle(centre_pos, radius, true, Color(255, 181, 0)); // draws an orange-ish, filled circle of radius 5 at (10, 10); 
```

<br>

- ### draw_rect

`void draw_rect(Position top_left_corner, Position bottom_right_corner, bool filled = false, Color color = Color(255, 255, 255))`

Draws a rectangle having `top_left_corner` and `bottom_right_corner` specified with the given `color`.

It may or may not be filled.

**Example**:
```cpp
Position start_corner(1, 1);
Position end_corner(10, 10);

// draws a blue-ish hollow rectangle starting from (1, 1) and ending at (10, 10)
draw_rect(start_corner, end_corner, false, Color(79, 0, 255));
```