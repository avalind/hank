#ifndef DRAW_H_
#define DRAW_H_

#include "tga.h"

namespace hank
{
    bool line(TGAImage &im,
        int x0, int y0,
        int x1, int y1,
        int color);
}

#endif /* DRAW_H_ */