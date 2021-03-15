#include <iostream>
#include <math.h>  
using namespace std;
using namespace Custom;

int** createMatrix(int rows, int cols, int initValue) {
    //alloc matrix
    int** matrix = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    //Init matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = initValue;
        }
    }
    return matrix;
}

double** createMatrix(int rows, int cols, double initValue) {
    //alloc matrix
    double** matrix = new double* [rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }

    //Init matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = initValue;
        }
    }

    return matrix;
}

unsigned char** createMatrix(int rows, int cols, unsigned char initValue) {
    //alloc matrix
    unsigned char** matrix = new unsigned char* [rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new unsigned char[cols];
    }

    //Init matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = initValue;
        }
    }

    return matrix;
}

/*
Function citra negatif
*/
Image negatif(Image img){
    Image result_img(img.getRows(),img.getCols(),img.getGray(),img.getType());
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img.getGray() - img.getCell(k,i,j) - 1);
            }
        }
    }
    return result_img;
}

/*
Function convert colored img to Grayscale
*/
Image convert_to_Grayscale(Image img){
    Image result_img(img.getRows(),img.getCols(),img.getGray(),img.getType());
    unsigned char tmp;

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            tmp = (img.getCell(0,i,j) + img.getCell(1,i,j) + img.getCell(2,i,j))/3;
            result_img.setCell(0,i,j,tmp);
            result_img.setCell(1,i,j,tmp);
            result_img.setCell(2,i,j,tmp);
        }
    }
    return result_img;
}

/*
Function brightening
option :
    0 : addition
    1 : substract
    2 : multiply
    3 : division
*/
Image brightening(Image img, int option, double scale){
    Image result_img(img.getRows(),img.getCols(),img.getGray(), img.getType());
    unsigned char tmp;

    for (int k = 0; k < 3; k++){
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                if (option == 0){
                    tmp = img.getCell(k,i,j) + scale;
                } 
                else {
                    tmp = img.getCell(k, i, j) * scale;
                }

                if(tmp > img.getGray()) {
                    tmp = img.getGray();
                }
                else if (tmp < 0) {
                    tmp = 0;
                }
                result_img.setCell(k,i,j,tmp);
            }
        }
    }
    return result_img;
}

/*
Function Transformation log
*/
Image transformation_log(Image img, double c){
    Image result_img(img.getRows(),img.getCols(),img.getGray(), img.getType());
    double tmp;

    for (int k = 0; k < 3; k++){
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                tmp = c * log(1 + img.getCell(k,i,j));
                result_img.setCell(k,i,j,tmp);
            }
        }
    }
    return result_img;
}

/*
Function Transformation log inverse
*/
Image transformation_log_inverse(Image img, double c){
    Image result_img(img.getRows(),img.getCols(),img.getGray(), img.getType());
    double tmp;

    for (int k = 0; k < 3; k++){
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                tmp = c / log(1.01 + img.getCell(k,i,j));
                result_img.setCell(k,i,j,tmp);
            }
        }
    }
    return result_img;
}

/*
Function Transformation pangkat
*/
Image transformation_pangkat(Image img, double c, double y){
    Image result_img(img.getRows(),img.getCols(),img.getGray(), img.getType());
    double tmp;

    for (int k = 0; k < 3; k++){
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                tmp = c * pow(img.getCell(k,i,j), y);
                result_img.setCell(k,i,j,tmp);
            }
        }
    }
    return result_img;
}

/*
Function for Addition
Adding two images into a new image
*/
Image addition(Image img_1, Image img_2){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());
    int minRows, minCols, temp;

    if (img_1.getRows() < img_2.getRows()) minRows = img_1.getRows();
    else minRows = img_2.getRows();

    if (img_1.getCols() < img_2.getCols()) minCols = img_1.getCols();
    else minCols = img_2.getCols();

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                if ((i < minRows) && (j < minCols)) {
                    temp = img_1.getCell(k, i, j) + img_2.getCell(k, i, j);
                    if (temp > result_img.getGray()) {
                        result_img.setCell(k, i, j, result_img.getGray());
                    }
                    else {
                        result_img.setCell(k, i, j, temp);
                    }
                }
                else {
                    result_img.setCell(k, i, j, img_1.getCell(k, i, j));
                }
            }
        }
    }
    return result_img;
}

/*
Function for Substraction
Subtract first image with second image into a new image
*/
Image substraction(Image img_1, Image img_2){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());
    int minRows, minCols, temp;

    if (img_1.getRows() < img_2.getRows()) minRows = img_1.getRows();
    else minRows = img_2.getRows();

    if (img_1.getCols() < img_2.getCols()) minCols = img_1.getCols();
    else minCols = img_2.getCols();

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                if ((i < minRows) && (j < minCols)) {
                    temp = img_1.getCell(k, i, j) - img_2.getCell(k, i, j);
                    if (temp != 0) {
                        result_img.setCell(k, i, j, result_img.getGray());
                    }
                    else {
                        result_img.setCell(k, i, j, 0);
                    }
                }
                else {
                    result_img.setCell(k, i, j, img_1.getCell(k,i,j));
                }
            }
        }
    }
    return result_img;
}

/*
Function for AND Operation
Apply AND operation for first image against second image
*/
Image ANDOperation(Image img_1, Image img_2){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());
    int minRows, minCols, temp;

    if (img_1.getRows() < img_2.getRows()) minRows = img_1.getRows();
    else minRows = img_2.getRows();

    if (img_1.getCols() < img_2.getCols()) minCols = img_1.getCols();
    else minCols = img_2.getCols();

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                if ((i < minRows) && (j < minCols)) {
                    result_img.setCell(k, i, j, img_1.getCell(k, i, j) & img_2.getCell(k, i, j));
                }
                else {
                    result_img.setCell(k, i, j, img_1.getCell(k, i, j));
                }
            }
        }
    }
    return result_img;
}

/*
Function for OR Operation
Apply OR operation for first image against second image
*/
Image OROperation(Image img_1, Image img_2){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());
    int minRows, minCols, temp;

    if (img_1.getRows() < img_2.getRows()) minRows = img_1.getRows();
    else minRows = img_2.getRows();

    if (img_1.getCols() < img_2.getCols()) minCols = img_1.getCols();
    else minCols = img_2.getCols();

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                if ((i < minRows) && (j < minCols)) {
                    result_img.setCell(k, i, j, img_1.getCell(k, i, j) | img_2.getCell(k, i, j));
                }
                else {
                    result_img.setCell(k, i, j, img_1.getCell(k, i, j));
                }
            }
        }
    }
    return result_img;
}

/*
Function for XOR Operation
Apply XOR operation for first image against second image
*/
Image XOROperation(Image img_1, Image img_2){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());
    int minRows, minCols, temp;

    if (img_1.getRows() < img_2.getRows()) minRows = img_1.getRows();
    else minRows = img_2.getRows();

    if (img_1.getCols() < img_2.getCols()) minCols = img_1.getCols();
    else minCols = img_2.getCols();

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                if ((i < minRows) && (j < minCols)) {
                    result_img.setCell(k, i, j, img_1.getCell(k, i, j) ^ img_2.getCell(k, i, j));
                }
                else {
                    result_img.setCell(k, i, j, img_1.getCell(k, i, j));
                }
            }
        }
    }
    return result_img;
}

/*
Function for NOT Operation
Apply NOT operation for an image
*/
Image NOTOperation(Image img_1){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,~img_1.getCell(k,i,j));
            }
        }
    }
    return result_img;
}

/*
Function for Translation
Apply translation operation for an image 
int m : translation distance in horizontal axis
int n : translation distance in vertical axis
*/
Image translation(Image img_1,int m, int n){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++)
            {
                result_img.setCell(k, i, j, 0);
                if((i-m >= 0) && (i-m < result_img.getRows()) && (j-n >= 0) && (j-n < result_img.getCols()))
                {
                    result_img.setCell(k,i,j,img_1.getCell(k,i-m,j-n));
                }
            }
        }
    }
    return result_img;
}

Image rotate90CCW(Image img) {
    Image result_img(img.getCols(), img.getRows(), img.getGray(), img.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k, i, j, img.getCell(k,j,img.getCols()-1-i));
            }
        }
    }
    return result_img;
}

Image rotate90CW(Image img) {
    Image result_img(img.getCols(), img.getRows(), img.getGray(), img.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k, i, j, img.getCell(k, img.getRows()-1-j, i));
            }
        }
    }
    return result_img;
}

/*
Function for vertical flipping
Apply X-axis (cartesian) reflection of image 
*/
Image verticalFlip(Image img_1){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img_1.getCell(k,img_1.getRows()-1-i,j));
            }
        }
    }
    return result_img;
}

/*
Function for horizontal flipping
Apply Y-axis (cartesian) reflection of image 
*/
Image horizontalFlip(Image img_1){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img_1.getCell(k,i,img_1.getCols()-1-j));
            }
        }
    }
    return result_img;
}

/*
Function for point of origin relection flipping
Apply mirroring at the point of origin (0,0) reflection of image 
*/
Image POFFlip(Image img_1){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img_1.getCell(k,img_1.getRows()-1-i,img_1.getCols()-1-j));
            }
        }
    }
    return result_img;
}

/*
Function for reflection on x=y line flipping
Apply mirroring reflection on the line x = y of image 
*/
Image xyFlip(Image img_1){
    Image result_img(img_1.getCols(),img_1.getRows(),img_1.getGray(),img_1.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img_1.getCell(k,j,i));
            }
        }
    }
    return result_img;
}

/*
Function for Zoom Out Image 2 times 
Apply magnification of image by a scale factor of 2
*/
Image zoomIn(Image img_1){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img_1.getCell(k, (int)floor(0.5*i), (int)floor(0.5*j)));
            }
        }
    }
    return result_img;
}

/*
Function for Zoom In Image 2 times 
Apply magnification of image by a scale factor of 1/2
*/
Image zoomOut(Image img_1){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());
    unsigned char temp;
    int m = (int)floor(0.5 * img_1.getRows());
    int n = (int)floor(0.5 * img_1.getCols());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k, i, j, 0);
                if ((i < m) && (j < n))
                {
                    temp = 0.25 * (img_1.getCell(k, 2*i, 2*j) + img_1.getCell(k, 2*i+1, 2*j) + img_1.getCell(k, 2*i, 2*j+1) + img_1.getCell(k, 2*i+1, 2*j+1));
                    result_img.setCell(k, i, j, temp);
                }
            }
        }
    }
    return result_img;
}

Image preserveBackgroundGrayLevelSlicing(Image img, int a, int b, unsigned char val) {
    Image result_img(img.getRows(), img.getCols(), img.getGray(), img.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < img.getRows(); i++) {
            for (int j = 0; j < img.getCols(); j++) {
                if ((img.getCell(k, i, j) > a) && (img.getCell(k, i, j) < b)) {
                    result_img.setCell(k, i, j, img.getGray());
                }
                else {
                    result_img.setCell(k, i, j, img.getCell(k, i, j));
                }
            }
        }
    }
    return result_img;
}

Image discardBackgroundGrayLevelSlicing(Image img, int a, int b, unsigned char val, unsigned char discard_val) {
    Image result_img(img.getRows(), img.getCols(), img.getGray(), img.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < img.getRows(); i++) {
            for (int j = 0; j < img.getCols(); j++) {
                if ((img.getCell(k, i, j) > a) && (img.getCell(k, i, j) < b)) {
                    result_img.setCell(k, i, j, val);
                }
                else {
                    result_img.setCell(k, i, j, discard_val);
                }
            }
        }
    }
    return result_img;
}

Image bitPlaneSlicing(Image img, int plane) {
    Image result_img(img.getRows(), img.getCols(), img.getGray(), img.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < img.getRows(); i++) {
            for (int j = 0; j < img.getCols(); j++) {
                unsigned char res = img.getCell(k, i, j);
                unsigned char t = 128;
                for (int b = 7; b > plane; b--) {
                    if (res - t > 0) {
                        res = res - t;
                    }
                    t = t / 2;
                }
                result_img.setCell(k, i, j, res);
            }
        }
    }
    return result_img;
}

Image contrastStretching(Image img, int a, int b) {
    Image result_img(img.getRows(), img.getCols(), img.getGray(), img.getType());
    unsigned char tmp;
    int rmin = (a * img.getGray()) / 100;
    int rmax = (b * img.getGray()) / 100;
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {

                if (img.getCell(k, i, j) < rmin) {

                    result_img.setCell(k, i, j, 0);
                }
                else if (img.getCell(k, i, j) > rmax) {
                    result_img.setCell(k, i, j, img.getGray());
                }
                else {
                    result_img.setCell(k, i, j, (unsigned char)img.getGray() * (img.getCell(k, i, j) - rmin) / (rmax - rmin));

                }
            }
        }
    }
    return result_img;
}

Image histogramEqualization(Image img)
{
    Image result_img(img.getRows(), img.getCols(), img.getGray(), img.getType());
    float image_pixel_count = img.getRows() * img.getCols();

    for (int k = 0; k < 3; k++) {
        // create frequency histogram
        int freq[256];
        for (int i = 0; i < 256; i++) {
            freq[i] = 0;
        }
        for (int i = 0; i < img.getRows(); i++) {
            for (int j = 0; j < img.getCols(); j++) {
                freq[(int)img.getCell(k, i, j)] += 1;
            }
        }

        // histogram equalization
        float sum = 0.0;
        int new_hist[256];
        for (int i = 0; i < 256; i++) {
            sum = sum + freq[i];
            new_hist[i] = (int)floor((255 * sum) / image_pixel_count);
        }

        // updating image
        for (int i = 0; i < img.getRows(); i++) {
            for (int j = 0; j < img.getCols(); j++) {
                result_img.setCell(k, i, j, (unsigned char)new_hist[img.getCell(k, i, j)]);
            }
        }
    }
    return result_img;
}

float* histogram(Image img, int warna)
{
    Image result_img(img.getRows(), img.getCols(), img.getGray(), img.getType());
    float image_pixel_count = img.getRows() * img.getCols();

    int freq[2048];
    float normalized_histogram[2048];
    for (int i = 0; i < 256; i++) {
        freq[i] = 0;
        normalized_histogram[i] = 0;
    }
    for (int i = 0; i < img.getRows(); i++) {
        for (int j = 0; j < img.getCols(); j++) {
            freq[(int)img.getCell(warna, i, j)] += 1;
        }
    }
    for (int i = 0; i < 256; i++) {
        normalized_histogram[i] = freq[i] / image_pixel_count;
    }

    return normalized_histogram;
}

float* cekRandom()
{
    float Nr[2048];
    for (int i = 0; i < 256; i++)
    {
        if (i < 100) Nr[i] = i;
        else Nr[i] = 100;
    }
    return Nr;
}

Image convolute(Image img, double** kernel, int rows_kernel, int cols_kernel) {
    Image result_img(img.getRows(), img.getCols(), img.getGray(), img.getType());
    int conv = 0;
    int x, y; //img matrix index
    int rows_tmp = img.getRows() - rows_kernel + 1;
    int cols_tmp = img.getCols() - cols_kernel + 1;
    double** tmp = createMatrix(rows_tmp, cols_tmp, 0.0);

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < img.getRows(); i++)
        {
            for (int j = 0; j < img.getCols(); j++)
            {
                x = i;
                y = j;
                for (int k = 0; k < rows_kernel; k++)
                {
                    for (int l = 0; l < cols_kernel; l++)
                    {
                        conv = conv + kernel[k][l] * img.getCell(k, x, y);
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j; // Restart column position
                }
                if (conv < 0) {
                    tmp[i][j] = 0;
                }
                else {
                    if (conv > 255)
                        tmp[i][j] = 255;
                    else
                        tmp[i][j] = conv;
                }
                conv = 0;
            }
        }
        for (int i = 0; i < img.getRows(); i++)
        {
            for (int j = 0; j < img.getCols(); j++)
            {
                if (i >= (img.getRows() - rows_tmp) / 2) {
                    result_img.setCell(k, i, j, (unsigned char)tmp[i][j]);
                }
                else {
                    result_img.setCell(k, i, j, img.getCell(k, i, j));
                }

                if (i >= (img.getCols() - cols_tmp) / 2) {
                    result_img.setCell(k, i, j, (unsigned char)tmp[i][j]);
                }
                else {
                    result_img.setCell(k, i, j, img.getCell(k, i, j));
                }
            }
        }
    }
    return result_img;
}