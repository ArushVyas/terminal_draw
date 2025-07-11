# Terminal draw documentation
FAIR WARNING: This may not remain up-to-date with the source code


## Classes:

1. ### `Position`:
Defines a Position (x, y)

**Example**:
```cpp
// Creates a position (4, 5)
Position pos;
pos.x = 4;
pos.y = 5;
```

<br>

2. ### `Vector2`:
A helper class used to define a position easily.

**Example**:
```cpp
// this also creates a position (4, 5) but is more readable
Position pos = Vector2(4, 5);
```




<br><br>




## Types:

- `typedef std::vector <Position> PointsArr;`:

Provides an easier way to define a vector containing `Position`s.

**Example**:
```cpp
// instead of writing....
std::vector <Position> array_of_points = {
    Vector2(0, 0),
    Vector2(10, 10),
    Vector2(20, 30),
    Vector2(40, 10)
};

// write....
PointsArr array_of_points = {
    Vector2(0, 0),
    Vector2(10, 10),
    Vector2(20, 30),
    Vector2(40, 10)
};
```




<br><br>




## Methods:

- ### `void initialize()`:

⚠ This function does nothing as of now.

Properly initializes the terminal window.

<br>

- ### `void draw_pixel(unsigned int x_coord, unsigned int y_coord)`:

Draws a pixel at the specified coordinates.

**Example**:
```cpp
draw_pixel(5, 9); // draws a pixel at (5, 9)
```

<br>

- ### `void draw_pixel(Position pos)`:

Draws a pixel at the specified `Position`.

**Example**:
```cpp
Position pos = Vector2(3, 8);

draw_pixel(pos); // draws a pixel at (3, 8)
```

<br>

- ### `void draw_string(std::string draw_this_string, unsigned int x_coord, unsigned int y_coord)`:

Draws text (string) starting from the specified location.

**Example**:
```cpp
// draws "hello world" starting from (5, 9)
draw_string("hello world", 5, 9);
```

<br>

- ### `void draw_string(std::string draw_this_string, Position pos)`:

Draws text (string) starting from the specified `Position`.

**Example**:
```cpp
Position str_pos = Vector2(10, 10);

// draws "hello world" starting from (10, 10)
draw_string("hello world", str_pos);
```

<br>

- ### `void draw_line(Position start_point, Position end_point)`:

Draws a line joining two `Position`s.

**Example**:
```cpp
Position pos_a = Vector2(2, 2);
Position pos_b = Vector2(5, 6);

draw_line(pos_a, pos_b); // draws a line joining pos_a & pos_b
```

<br>

- ### `void draw_poly(PointsArr points, bool closed = false)`:

Draws a polygon joining all points in `PointsArr` vector.

The polygon may be open (`closed = false`) or closed (`closed = true`).

**Example**:
```cpp
PointsArr points_arr = {
    Vector2(0, 0),
    Vector2(5, 10),
    Vector2(10, 5),
    Vector2(20, 20)
};

draw_poly(points_arr);
```

<br>

- ### `void draw_circle(Position centre, int radius, bool filled = false)`:

Draws a circle at specified `centre` `Position` with a given `radius`.

It may or may not be filled.

**Example**:
```cpp
Position centre_pos = Vector2(10, 10);
int radius = 5;

draw_circle(centre_pos, radius, true); // draws a filled circle of radius 5 at (10, 10); 
```

<br>

- ### `void draw_rect(Position top_left_corner, Position bottom_right_corner, bool filled = false)`:

Draws a rectangle having `top_left_corner` and `bottom_right_corner` specified.

It may or may not be filled.

**Example**:
```cpp
Position start_corner = Vector2(1, 1);
Position end_corner = Vector2(10, 10);

// draws a hollow rectangle starting from (1, 1) and ending at (10, 10)
draw_rect(start_corner, end_corner, false);
```