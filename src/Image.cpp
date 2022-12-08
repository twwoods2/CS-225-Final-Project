#include "Image.h"
#include <iostream>
#include <cmath>

void Image::lighten() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.l + 0.1 > 1.0) {
                pixel.l = 1.0;
            } else {
                pixel.l += 0.1;
            }
        }
    }
}

void Image::lighten(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.l + amount > 1.0) {
                pixel.l = 1.0;
            } else {
                pixel.l += amount;
            }
        }
    }
}

void Image::darken() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.l - 0.1 < 0) {
                pixel.l = 0;
            } else {
                pixel.l -= 0.1;
            }
        }
    }
}

void Image::darken(double amount) {
   for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.l - amount < 0) {
                pixel.l = 0;
            } else {
                pixel.l -= amount;
            }
        }
    }
}

void Image::saturate() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.s + 0.1 > 1.0) {
                pixel.s = 1.0;
            } else {
                pixel.s += 0.1;
            }
        }
    }
}

void Image::saturate(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.s + amount > 1.0) {
                pixel.s = 1.0;
            } else {
                pixel.s += amount;
            }
        }
    }
}

void Image::desaturate() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.s - 0.1 < 0) {
                pixel.s = 0;
            } else {
                pixel.s -= 0.1;
            }
        }
    }
}

void Image::desaturate(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.s - amount < 0) {
                pixel.s = 0;
            } else {
                pixel.s -= amount;
            }
        }
    }
}

void Image::grayscale() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            pixel.s = 0;
        }
    }
}

void Image::rotateColor(double degrees) {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.h + degrees < 0) {
                pixel.h = pixel.h + degrees + 360;
            }
            else if (pixel.h + degrees > 360) {
                pixel.h = pixel.h + degrees - 360;
            }
            else {
                pixel.h += degrees;
            }
        }
    }   
}

void Image::illinify(){
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& pixel = this->getPixel(x, y);
            if (pixel.h > 216) {
                if ((360 - std::abs(pixel.h - 11)) > (pixel.h - 216)) {
                    pixel.h = 216;
                } else {
                    pixel.h = 11;
                }
            } else {
                if ((std::abs(pixel.h - 11)) > (std::abs(pixel.h - 216))) {
                    pixel.h = 216;
                } else {
                    pixel.h = 11;
                }
            }
        }
    }
}

void Image::scale(double factor){
    int newWidth = this->width() * factor;
	int newHeight = this->height() * factor;
    PNG* scaled = new PNG(newWidth, newHeight); 
	for (int x = 0; x < newWidth; x++) {
		for (int y = 0; y < newHeight; y++) {
			cs225::HSLAPixel& originalPix = this->getPixel(x/factor, y/factor);
			cs225::HSLAPixel& scaledPix = scaled->getPixel(x, y);
			scaledPix.h = originalPix.h;
            scaledPix.s = originalPix.s;
            scaledPix.l = originalPix.l;
            scaledPix.a = originalPix.a;
		}
	}
    this->resize(newWidth, newHeight);
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel& originalPix = this->getPixel(x, y);
            cs225::HSLAPixel& scaledPix = scaled->getPixel(x, y);
            originalPix.h = scaledPix.h;
            originalPix.s = scaledPix.s;
            originalPix.l = scaledPix.l;
            originalPix.a = scaledPix.a;
        }
    } 
    delete scaled;
}

void Image::scale(unsigned w, unsigned h) {
    
    double widthFactor = double(w)/this->width();
    double heightFactor = double(h)/this->height();
    if(widthFactor > heightFactor) {
        this->scale(heightFactor);
    } else {
        this->scale(widthFactor);
    }
}