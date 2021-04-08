#include <utility>
#include <cmath>
#include "draw.h"
#include "geometry.h"


namespace hank {

bool _draw_horizontal(TGAImage &im, int x0, int y0, int x1, int y1, int color) {
    if(x0 >= x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    for(int dx = x0; dx < x1; dx++) {
        im.put_pixel(dx, y0, color);
    }
    return true;
}

bool _draw_vertical(TGAImage &im, int x0, int y0, int x1, int y1, int color) {
    if(y0 >= y1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    for(int dy = y0; dy < y1; dy++) {
        im.put_pixel(x0, dy, color);
    }
    return true;
}


bool line(TGAImage &im, int x0, int y0, int x1, int y1, int color) {
    // first, handle special cases where y0 == y1 or x0 == x1
    if(y0 == y1) {
        return _draw_horizontal(im, x0, y0, x1, y1, color);
    } else if (x0 == x1) {
        return _draw_vertical(im, x0, y0, x1, y1, color);
    } else {
        int dx = std::abs(x1 - x0);
        int sx = x0 < x1 ? 1 : -1;
        int dy = -std::abs(y1 - y0);
        int sy = y0 < y1 ? 1 : -1;
        int error = dx + dy;
        int error2;
        while(true) {
            im.put_pixel(x0, y0, color);
            if(x0 == x1 && y0 == y1) {
                return true;
            }
            error2 = 2 * error;
            if(error2 > dy) {
                error += dy;
                x0 += sx;
            }
            if(error2 <= dx) {
                error += dx;
                y0 += sy;
            }
        }
    }
    return true;
}

bool draw(TGAImage &im, Rectangle<int> &rect, int color) {
    bool retcode;
    retcode = line(im, 
        rect.upper_left[0],
        rect.upper_left[1],
        rect.upper_left[0] + rect.width,
        rect.upper_left[1],
        color);

    retcode = line(im,
        rect.upper_left[0] + rect.width,
        rect.upper_left[1],
        rect.upper_left[0] + rect.width,
        rect.upper_left[1] - rect.height,
        color);

    retcode = line(im,
        rect.upper_left[0] + rect.width,
        rect.upper_left[1] - rect.height,
        rect.upper_left[0],
        rect.upper_left[0] - rect.height,
        color);

    retcode = line(im,
        rect.upper_left[0],
        rect.upper_left[0] - rect.height,
        rect.upper_left[0],
        rect.upper_left[1],
        color);
    return retcode;
};

bool draw(TGAImage& im, Triangle<int> &rect, int color) {
    return true;
}

}