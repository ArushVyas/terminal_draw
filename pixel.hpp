#include <iostream>
#include <vector>
#include <windows.h>




/*
Use these for virtual terminal sequences:
    - https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
    - https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
*/






typedef unsigned int uint;



// A class that defines a Position in two dimensions
// Position consists of x and y coordinates
class Position {
    public:
    int x, y;

    Position(uint x_coord, uint y_coord) {
        x = x_coord;
        y = y_coord;
    }
    
    // A helper function that returns the squared distance between two Positions
    float distance_squared_to(Position position2) {
        return ((position2.x - x) * (position2.x - x)) + ((position2.y - y) * (position2.y - y));
    }
};


// Color value range from 0 to 255
class Color {
    public:
    uint r, g, b;

    Color(uint red, uint green, uint blue) {
        r = red;
        g = green;
        b = blue;
    }
};




typedef std::vector <Position> PointsArr; // easy way to initialize a vector storing Positions




// Required to enable virtual terminal processing on windows platforms
void initialize() {

    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD dwModeIn, dwModeOut;

    // Get current console modes
    GetConsoleMode(hIn, &dwModeIn);
    GetConsoleMode(hOut, &dwModeOut);

    // Enable virtual terminal flags
    dwModeIn |= ENABLE_VIRTUAL_TERMINAL_INPUT;
    dwModeOut |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    SetConsoleMode(hIn, dwModeIn);
    SetConsoleMode(hOut, dwModeOut);

}




// Draws a square block
void draw_pixel(uint x_coord, uint y_coord, Color color = Color(255, 255, 255)) {
    std::cout << "\x1b[38;2;" << color.r << ";" << color.g << ";" << color.b << "m"; // set color
    
    std::cout << "\x1b[" << y_coord + 1 << ";" << (x_coord * 2) + 1 << "H"; // set cursor position
    std::wcout << L'\xDB' << L'\xDB'; // draw two "full block" characters, this is the pixel

    std::cout << "\x1b[0m"; // reset color
}


void draw_pixel(Position pos, Color color = Color(255, 255, 255)) {
    draw_pixel(pos.x, pos.y, color);
}




void draw_string(std::string draw_this_string, uint x_coord, uint y_coord, Color bg_color = Color(0, 0, 0), Color fg_color = Color(255, 255, 255)) {
    std::cout << "\x1b[48;2;" << bg_color.r << ";" << bg_color.g << ";" << bg_color.b << "m"; // set background color
    std::cout << "\x1b[38;2;" << fg_color.r << ";" << fg_color.g << ";" << fg_color.b << "m"; // set foreground color


    std::cout << "\x1b[" << y_coord << ";" << x_coord * 2 << "H"; // set cursor position
    std::cout << draw_this_string;

    std::cout << "\x1b[0m"; // reset color
}


void draw_string(std::string draw_this_string, Position pos, Color bg_color = Color(0, 0, 0), Color fg_color = Color(255, 255, 255)) {
    draw_string(draw_this_string, pos.x, pos.y, bg_color, fg_color);
}




// this function does not look very good
void draw_line(Position start_point, Position end_point, Color color = Color(255, 255, 255)) {

    if ((end_point.x - start_point.x) != 0) {

        float slope = (end_point.y - start_point.y) / (end_point.x - start_point.x);
        
        if (end_point.x > start_point.x) {
            
            for (int i = start_point.x; i <= end_point.x; i++) {
                draw_pixel(i, (int)((slope * (i - start_point.x)) + start_point.y), color);
            }

        } else if (end_point.x < start_point.x) {

            for (int i = end_point.x; i <= start_point.x; i++) {
                draw_pixel(i, (int)((slope * (i - end_point.x)) + end_point.y), color);
            }
        }

    } else {

        if (end_point.y > start_point.y) {

            for (int i = start_point.y; i < end_point.y; i++) {
                draw_pixel(start_point.x, i, color);
            }

        } else if (end_point.y < start_point.y) {

            for (int i = end_point.y; i <= start_point.y; i++) {
                draw_pixel(end_point.x, i, color);
            }
        }
    }

}




void draw_poly(PointsArr points, bool closed = false, Color color = Color(255, 255, 255)) {

    if (closed) {

        for (int i = 0; i < points.size() - 1; i++) {
            draw_line(points[i], points[i + 1]);
        }
        draw_line(points[0], points[points.size() - 1], color);

    } else {
        
        for (int i = 0; i < points.size() - 1; i++) {
            draw_line(points[i], points[i + 1], color);
        }
    }
    
}




void draw_circle(Position centre, int radius, bool filled = false, Color color = Color(255, 255, 255)) {

    const int SEARCH_MARGIN = 1;

    const int HORIZONTAL_SEARCH_START = centre.x  - radius - SEARCH_MARGIN;
    const int HORIZONTAL_SEARCH_END = centre.x  + radius + SEARCH_MARGIN;

    const int VERTICAL_SEARCH_START = centre.y  - radius - SEARCH_MARGIN;
    const int VERTICAL_SEARCH_END = centre.y  + radius + SEARCH_MARGIN;


    for (int i = HORIZONTAL_SEARCH_START; i <= HORIZONTAL_SEARCH_END; i++) {
        for (int j = VERTICAL_SEARCH_START; j <= VERTICAL_SEARCH_END; j++) {

            Position current_pixel(i, j);
            
            if (filled) {

                if (current_pixel.distance_squared_to(centre) <= radius * radius) {
                    draw_pixel(current_pixel, color);
                }

            } else {

                if (current_pixel.distance_squared_to(centre) == radius * radius) {
                    draw_pixel(current_pixel, color);
                }

            }
        }
    }

}




void draw_rect(Position top_left_corner, Position bottom_right_corner, bool filled = false, Color color = Color(255, 255, 255)) {

    if (!filled) {

        draw_line(top_left_corner, Position(bottom_right_corner.x, top_left_corner.y), color); // top edge
        draw_line(top_left_corner, Position(top_left_corner.x, bottom_right_corner.y), color); // left edge
        draw_line(Position(top_left_corner.x, bottom_right_corner.y), bottom_right_corner, color); // bottom edge
        draw_line(Position(bottom_right_corner.x, top_left_corner.y), bottom_right_corner, color); // right edge

    } else {

        for (int i = top_left_corner.x; i <= bottom_right_corner.x; i++) {
            for (int j = top_left_corner.y; j <= bottom_right_corner.y; j++) {

                draw_pixel(i, j, color);
            }
        }
    }

}