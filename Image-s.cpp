#include "Image-s.h"
#include "Color-s.h"
#include "Pixel-s.h"
#include <fstream>
#include <string>
Image::Image(){}
Image::~Image(){}
Image::Image(int w, int h){
    width = w;
    height = h;
}
void Image::arrini(){
    pixarr = new Pixel*[width];
    for(int i=0; i<width; i++){
        pixarr[i] = new Pixel[height];
    }
}
void Image::setwidth(int w){
    width = w;
}
void Image::setheight(int h){
    height = h;
}
int Image::getwidth(){
    return width;
}
int Image::getheight(){
    return height;
}
void Image::setpixarr(int i, int j, int r, int g, int b){
    pixarr[i][j].setcolor(r, g, b);
}
Pixel& Image::getpixarr(int i, int j){
    return pixarr[i][j];
}
Image Image::filter(Color c, float alpha){
    Color currcolor; Color *finalcolor; int r, g, b, newr, newg, newb;
    Image result(width, height);
    result.arrini();
    for(int i = 0; i<width; i++){
        for(int j = 0; j<height; j++){
            currcolor = getpixarr(i, j).getcolor();
            newr = (1-alpha)*currcolor.getr()+alpha*c.getr();
            newb = (1-alpha)*currcolor.getb()+alpha*c.getb();
            newg = (1-alpha)*currcolor.getg()+alpha*c.getg();
            result.setpixarr(i, j, newr, newg, newb);
        }
    }
    return result;
}
istream& operator>>(istream& in, Image &im){
    string type; int maxcolor, w, h; Pixel p;
    in >> type;
    in >> w >> h;
    im.setwidth(w); im.setheight(h);
    in >> maxcolor;
    im.arrini();
    for(int i = 0; i < im.width; i++) {
        for(int j = 0; j < im.height; j++) {
            in >> p;
            p.setloc(i, j);
            im.pixarr[i][j] = p;
        }
    }
    return in;
}

ostream& operator<< (ostream& os, Image &im){
    os << "P3" << endl;
    os << im.getwidth() << " " << im.getheight() << endl;
    os << "255" << endl;
    for(int i = 0; i<im.width; i++){
        for(int j = 0; j<im.height; j++){
            os << im.pixarr[i][j];
        }
    }
    return os;
}

int main(int argc, char *argv[]){
    string filename; Color filter_c; float filter_factor;
    std::cout << "This is a ppm file filtering tool" << '\n';
    std::cout << "Enter the name of the file below" << '\n';
    std::cin >> filename;
    std::cout << "Enter the color of the filter you want to apply (R<space>G<space>B)" << '\n';
    std::cin >> filter_c;
    std::cout << "Enter the amount of filter you want to apply (In the scale 0-1, Eg. 0.5 is half intense filter)" << '\n';
    cin >> filter_factor;
    ifstream input(filename);
    Image img, result_image;
    input >> img;
    result_image = img.filter(filter_c, filter_factor);
    ofstream output("filteredimage.ppm");
    output << result_image;
}
