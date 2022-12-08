#include <iostream>
#include"cs225/PNG.h"
#include"cs225/HSLAPixel.h"
#include"StickerSheet.h"


StickerSheet::StickerSheet(const Image& picture, unsigned max) {
	this->base = picture;
    this->numS = 0;
	this->maxS = max;
	this->stickerArr = new Image *[max];  
	this->xCoord = new unsigned [max];
	this->yCoord = new unsigned [max];
}

StickerSheet::~StickerSheet() {
	delete[] xCoord;
	delete[] yCoord;
	delete[] stickerArr;
}

StickerSheet::StickerSheet(const StickerSheet& other){
    this->base = other.base;
    this->numS = other.numS;
	this->maxS = other.maxS;
	this->stickerArr = new Image *[maxS];  
	this->xCoord = new unsigned [maxS];
	this->yCoord = new unsigned [maxS];
	for(unsigned i = 0; i < this->maxS; i++){
		stickerArr[i] = other.stickerArr[i];
		xCoord[i] = other.xCoord[i];
		yCoord[i] = other.yCoord[i];
	}

}

const StickerSheet& StickerSheet:: operator=(const StickerSheet& other) {
    if (this == &other) {
        return *this;
    }
    delete[] xCoord;
	delete[] yCoord;
	delete[] stickerArr;
	this->base = other.base;
    this->numS = other.numS;
	this->maxS = other.maxS;
	this->stickerArr = new Image *[other.maxS];
	this->xCoord = new unsigned [other.maxS];
	this->yCoord = new unsigned [other.maxS];
	for(unsigned i = 0; i < this->numS; i++){
		stickerArr[i] = other.stickerArr[i];
		xCoord[i] = other.xCoord[i];
		yCoord[i] = other.yCoord[i];
	}

    return *this;
}

void StickerSheet::changeMaxStickers(unsigned max){
	Image **tempArr = new Image *[this->maxS];
	unsigned *tempX = new unsigned [this->maxS];
	unsigned *tempY = new unsigned [this->maxS];
	unsigned int tempMaxS = this->maxS;

	for(unsigned i = 0; i < this->numS; i++){
		tempArr[i] = stickerArr[i];
		tempX[i] = xCoord[i];
		tempY[i] = yCoord[i];

	}
    delete[] xCoord;
	delete[] yCoord;
	delete[] stickerArr;
    if(this->numS > max){
		numS = max;
	}
	if (tempMaxS >= max){
        this->stickerArr = new Image *[max];
		this->xCoord = new unsigned [max];
		this->yCoord = new unsigned [max];
		for (unsigned int i = 0; i < max; i++){
			this->stickerArr[i] = tempArr[i];
			this->xCoord[i] = tempX[i];
			this->yCoord[i] = tempY[i];
		}
		this->maxS = max;
	} else {
		this->stickerArr = new Image *[max];
		this->xCoord = new unsigned [max];
		this->yCoord = new unsigned [max];
		for (unsigned int i = 0; i < this->numS; i++){
			this->stickerArr[i] = tempArr[i];
			this->xCoord[i] = tempX[i];
			this->yCoord[i] = tempY[i];
		}
		this->maxS = max;
    }

	delete [] tempX;
	delete [] tempY;
    delete [] tempArr;
}

int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y){
	if(this->numS < this->maxS){
		stickerArr[this->numS] = &sticker;
		xCoord[this->numS] = x;
		yCoord[this->numS] = y;
		numS++;
		return numS;
	} 
    return -1;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
    if(index >= this->numS){
        return false;
	} 
    this->xCoord[index] = x;
	this->yCoord[index] = y;
	return true;
}

void StickerSheet::removeSticker(unsigned index) {
	if(index < this->numS){
		unsigned int tempMax = this->maxS;
		Image **tempArr = new Image *[tempMax];
		unsigned *tempX = new unsigned [tempMax];
		unsigned *tempY = new unsigned [tempMax];
		for(unsigned i = 0; i < this->numS; i++){
			tempArr[i] = stickerArr[i];
			tempX[i] = xCoord[i];
			tempY[i] = yCoord[i];
		}
        delete[] xCoord;
	    delete[] yCoord;
	    delete[] stickerArr;
		this->stickerArr = new Image *[tempMax];
		this->xCoord = new unsigned [tempMax];
		this->yCoord = new unsigned [tempMax];
		for(unsigned i = 0; i < index; i++) {
			stickerArr[i] = tempArr[i];
			xCoord[i] = tempX[i];
			yCoord[i] = tempY[i];

		}
		for(unsigned i = index; i < this->numS; i++){
			stickerArr[i] = tempArr[i+1];
			xCoord[i] = tempX[i+1];
			yCoord[i] = tempY[i+1];
		}

		this->numS -= 1;

        delete [] tempX;
		delete [] tempY;
		delete [] tempArr;
	}
}

Image* StickerSheet::getSticker(unsigned index) {
	if(index >= this->numS){

		return NULL;

	}
    return stickerArr[index];
}

Image StickerSheet::render() const {
	Image toReturn = this->base;
	for(unsigned i = 0; i < numS; i++){
		for(unsigned x = xCoord[i]; x < ((stickerArr[i]->width()) + xCoord[i]); x++){
			for(unsigned y = yCoord[i]; y < ((stickerArr[i]->height()) + yCoord[i]); y++){
				if(x < toReturn.width() && y < toReturn.height()) {
					cs225::HSLAPixel &returnPix = toReturn.getPixel(x, y);
					cs225::HSLAPixel &tempPix = stickerArr[i]->getPixel(x - xCoord[i], y - yCoord[i]);
					if(tempPix.a != 0) {
						returnPix = tempPix;
					}
				}
			}
		}
	}
	return toReturn;
}




