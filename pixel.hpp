#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

/**
 * @brief A class that defines a Position in two dimensions
 * 
 * Position consists of x and y coordinates
 */
class Position {
    public:
    int x, y;

    // A helper function that returns the squared distance between two Positions
    float distance_squared_to(Position position2) {
        return ((position2.x - x) * (position2.x - x)) + ((position2.y - y) * (position2.y - y));
    }
};

/**
 * @brief A helper class used to define a Position easily
 */
class Vector2 : public Position {
    public:
    Vector2(int x_coord, int y_coord) {
        x = x_coord;
        y = y_coord;
    }
};


void draw_pixel(unsigned int x_coord, unsigned int y_coord) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD cursor_position;
    cursor_position.X = x_coord;
    cursor_position.Y = y_coord;

    SetConsoleCursorPosition(hConsole, cursor_position);

    cout << "O";
}


void draw_pixel(Position pos) {
    draw_pixel(pos.x, pos.y);
}


void draw_line(Position start_point, Position end_point) {

    if ((end_point.x - start_point.x) != 0) {

        float slope = (end_point.y - start_point.y) / (end_point.x - start_point.x);

        for (int i = start_point.x; i <= end_point.x; i++) {
            draw_pixel(i, (int)((slope * i) + start_point.y));
        }

    } else {

        for (int i = start_point.y; i < end_point.y; i++) {
            draw_pixel(start_point.x, i);
        }
    }
}


void draw_circle(Position centre, int radius, bool filled = false) {

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {

            Position current_pixel = Vector2(i, j);
            
            if (filled) {
                if (current_pixel.distance_squared_to(centre) <= radius * radius) {
                    draw_pixel(i, j);
                }

            } else {
                if (current_pixel.distance_squared_to(centre) == radius * radius) {
                    draw_pixel(i, j);
                }

            }
        }
    }
}


void draw_poly(std::vector <Position> positions_of_points) {
    // pass
}
