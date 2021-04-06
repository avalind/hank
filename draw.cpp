#include <utility>
#include "draw.h"


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

    }
    return true;
}

}