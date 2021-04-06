#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>

#include "tga.h"

namespace hank {

unsigned int rgba(
    unsigned char r,
    unsigned char g,
    unsigned char b,
    unsigned char a) {
  unsigned int pixel = (a << 24) + (r << 16) + (g << 8) + b;
  return pixel;
};

unsigned int rgb(
    unsigned char r,
    unsigned char g,
    unsigned char b) {
  return rgba(r, g, b, 255);
};

TGAImage::TGAImage(unsigned short width, unsigned short height)
{
  struct tga_header_t hdr = {
    0,
    0,
    2,
    {0,0,0,0,0},
    0,
    0,
    width,
    height,
    32,
    0x20,
  };

  this->header = hdr;
  this->pixbuf = (unsigned int *)malloc(width * height * sizeof(int));

  if(this->pixbuf == NULL) {
    std::cerr << "TGAImage::TGAImage: unable to allocate space for image\n";
  };
};

TGAImage::~TGAImage()
{
  if(this->pixbuf != NULL) {
    free(this->pixbuf);
  }
};

bool TGAImage::to_file(const std::string& filename)
{
  int pixels_to_write = this->header.width * this->header.height;
  std::fstream fp(filename, std::ios::out | std::ios::binary);
  fp.write((char *)&this->header, sizeof(tga_header_t));
  fp.write((char *)this->pixbuf, pixels_to_write * sizeof(int));
  fp.close();
  return true;
};

void TGAImage::put_pixel(int x, int y, int pixel) {
  int idx = this->header.width * y + x;
  this->pixbuf[idx] = pixel;
};

void TGAImage::fill(int color) {
  for(int idx = 0; idx < this->header.height * this->header.width; idx++) {
    this->pixbuf[idx] = color;
  }
}

}