#include "Image.hpp"
#include <iostream>

Image::Image(int width, int height){
    this->width = width;
    this->height = height;
    this->matriks = int* [height];
    for (int i = 0; i < this->height; i ++)
    {
        this->matriks[i] = new int[this->width];
    
    }
}

Image :: ~Image(){
    for (int i = 0; i < this->height; i++)
    {
        delete [] this->matriks[i];
    }
    delete [] this->matriks;
}

int Image::getWidth()
{
	return this->width;
}

int Image::getHeight()
{
	return this->height;
}

int** Image::getMatriks()
{
	return this->matriks;
}

void Image::setWidtht(int w){
    this->width = w;
}

void Image::setHeight(int h){
    this->height = h;
}

void Image::setMatriks(int **mat){
    this->matriks = mat;
}