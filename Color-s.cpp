#include "Color-s.h"
#include "Image-s.h"
#include "Pixel-s.h"
Color::Color(){}
Color::~Color(){}
Color::Color(float r, float g, float b){
    red = r;
    green  = g;
    blue = b;
}
Color::Color(const Color &colo){
    red = colo.red;
    green  = colo.green;
    blue = colo.blue;
}
float Color::getr(){
    return red;
}
float Color::getg(){
    return green;
}
float Color::getb(){
    return blue;
}
void Color::setcolor(int r, int g, int b){
    red = r;
    green = g;
    blue = b;
}
ostream& operator << (ostream& out, Color &c){
    out << c.red << " " << c.green << " " << c.blue << " ";
    return out;
}
istream& operator >> (istream& in, Color &c){
    in >> c.red >> c.green >> c.blue;;
    return in;
}
