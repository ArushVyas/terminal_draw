# Terminal draw documentation

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



## Methods:

1. ### `void draw_pixel(unsigned int x_coord, unsigned int y_coord)`:

Draws a pixel at the specified coordinates.

**Example**:
```cpp
draw_pixel(5, 9); // draws a pixel at (5, 9)
```

<br>

2. ### `void draw_pixel(Position pos)`:

Draws a pixel at the specified `Position`.

**Example**:
```cpp
Position pos = Vector2(3, 8);

draw_pixel(pos); // draws a pixel at (3, 8)
```

<br>

3. ### `void draw_line(Position start_point, Position end_point)`:

Draws a line joining two `Position`s.

*NOTE: Order of `Position`s matters! Arrange positions in ascending order.*

**Example**:
```cpp
Position pos_a = Vector2(2, 2);
Position pos_b = Vector2(5, 6);

draw_line(pos_a, pos_b); // draws a line joining pos_a & pos_b

draw_line(pos_b, pos_a); // This will not draw any line
```

<br>

4. ### `void draw_circle(Position centre, int radius, bool filled = false)`:

Draws a circle at specified `centre` `Position` with a given `radius`.

It may or may not be filled.

**Example**:
```cpp
Position centre_pos = Vector2(10, 10);
int radius = 5;

draw_circle(centre_pos, radius, true); // draws a filled circle of radius 5 at (10, 10); 
```
