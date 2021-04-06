#ifndef TGA_H_
#define TGA_H_

namespace hank {

struct tga_header_t {
  unsigned char id;
  unsigned char colormap;
  unsigned char imagetype;
  unsigned char cmap[5];
  unsigned short x_origin;
  unsigned short y_origin;
  unsigned short width;
  unsigned short height;
  unsigned char pixeldepth;
  unsigned char imagedesc;
};

class TGAImage {
  
  private:

    struct tga_header_t header;
    unsigned int *pixbuf;

  public:

    TGAImage() {};
    TGAImage(unsigned short width, unsigned short height);

    ~TGAImage();
    bool to_file(const std::string& filename);
    void put_pixel(int x, int y, int pixel);
    void fill(int color);
};

unsigned int rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
unsigned int rgb(unsigned char r, unsigned char g, unsigned char b);

}

#endif /* TGA_H_ */
