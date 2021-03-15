#include<stdio.h>
#include<stdlib.h>
#include"../Image.cpp"
#include<iostream>
#include <windows.h>
#include <wingdi.h>

using namespace std;

#define RGB_COMPONENT_COLOR 255

//read image from ppm file
Image readRaw(const char *filename)
{
     int rgb_comp_color=255;
     unsigned char *temp;
     
     //open PGM file for reading
     FILE* fp = fopen(filename, "rb");
     unsigned char info[4];

     // read the 54-byte header
     fread(info, sizeof(unsigned char), 4, fp); 

     // extract image height and width from header
     // x = (unsigned char*)malloc(2 * sizeof(unsigned char));
     // unsigned char *temp_x;
     // unsigned char *temp_y;
     // temp_x = (unsigned char*)malloc(2 * sizeof(unsigned char));
     // temp_y = (unsigned char*)malloc(2 * sizeof(unsigned char));
     // temp_x = &info[0];
     // temp_y = &info[2];
     int x = 512;
     int y = 512;
     cout<<x<<" "<<y<<"\n";

     // while (fgetc(fp) != '\n') ;
     //memory allocation for pixel data
     temp = (unsigned char*)malloc(x * sizeof(unsigned char));
     Image img(y, x, RGB_COMPONENT_COLOR,1);

     if (!img.getMatriks()) {
          cout<<"Unable to allocate memory\n";
          exit(1);
     }

     for (int i=0; i<img.getRows(); ++i)  {
          fread(temp, sizeof(temp[0]), img.getCols(), fp);
          for (int j = 0; j < img.getCols(); j++) {
               img.setCell(0,i,j,temp[j]);
               img.setCell(1,i,j,temp[j]);
               img.setCell(2,i,j,temp[j]);
          } 
     }
     fclose(fp);
     
     return img;
}

//save colored image to ppm file
void writeRaw(const char *filename, Image img)
{
    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) {
         cout<<"Unable to open file '%s'\n";
         exit(1);
    }

     unsigned char *temp;
     temp = (unsigned char*)malloc(3* img.getCols() * sizeof(unsigned char));

    // pixel data
     for (int i=0; i<img.getRows(); ++i) {
          for (int j=0; j<img.getCols(); ++j)     {
               for (int k=0; k<3; ++k)     {
                    temp[j*3+k] = img.getCell(k,i,j);
               }
          }
          fwrite(temp, sizeof(temp[0]), 3*img.getCols(), fp);
     }
     
    fclose(fp);

}

// int main(){
//     Image curImg = readRaw("raw_sample.raw");
//     writeRaw("test.raw", curImg);
// }