#ifndef DRAW_H_
#define DRAW_H_

#include "tga.h"
#include "geometry.h"

namespace hank
{
    bool line(TGAImage &im,
        int x0, int y0,
        int x1, int y1,
        int color);


    bool draw(TGAImage &im,
        Rectangle<int> &rect, 
        int color);

    bool draw(TGAImage &im,
        Triangle<int> &tri,
        int color);
}

#endif /* DRAW_H_ */