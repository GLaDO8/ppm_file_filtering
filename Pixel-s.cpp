#include "Pixel-s.h"
#include "Image-s.h"
#include "Color-s.h"
Pixel::Pixel(){}
Pixel::~Pixel(){}
Pixel::Pixel(int xc, int yc, Color col){
    x = xc;
    y = yc;
    c=col;
}
Pixel::Pixel(const Pixel &px){
    x = px.x;
    y = px.y;
    c = px.c;
}
void Pixel::setcolor(Color newc){
    c = newc;
}
void Pixel::setcolor(int r, int g, int b){
    c.setcolor(r, g, b);
}
Color Pixel::getcolor(){
    return c;
}
void Pixel::setloc(int i, int j){
    x = i;
    y = j;
}
ostream& operator << (ostream& out, Pixel &p){
    out << p.c;
    return out;
}
istream& operator >> (istream& in, Pixel &p){
    int r, g, b;
    in >> r >> g >> b;
    //std::cout << r << g << b << '\n';
    Color c(r, g, b);
    p.setcolor(c);
    return in;
}
