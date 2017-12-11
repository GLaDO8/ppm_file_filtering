#ifndef __PIXEL_H_INCLUDED__
#define __PIXEL_H_INCLUDED__
#include <iostream>
#include "Color-s.h"
using namespace std;
class Pixel{
    private:
        int x, y;
        Color c;
    public:
        Pixel();
        ~Pixel();
        Pixel(int xc, int yc, Color col);
        Pixel(const Pixel &px);
        void setcolor(Color newc);
        Color getcolor();
        void setloc(int i, int j);
        void setcolor(int r, int g, int b);
        friend ostream& operator << (ostream& out, Pixel &p);
        friend istream& operator >> (istream& in, Pixel &p);
};
#endif
