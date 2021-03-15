#include<stdio.h>
#include<stdlib.h>
#include"../Image.cpp"
#include<iostream>
using namespace std;

#define RGB_COMPONENT_COLOR 255

Image readBMP(const char *filename)
{
    int i;
    FILE* fp = fopen(filename, "rb");
    unsigned char info[54];

    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, fp); 

    // extract image height and width from header
    int x = *(int*)&info[18];
    int y = *(int*)&info[22];

    int buff2 = (int)*(int*)&info[10] - 54;
    
    unsigned char* info2;
    info2 = (unsigned char*)malloc(buff2 * sizeof(unsigned char));
    fread(info2, sizeof(unsigned char),buff2, fp); 

    unsigned char *temp;
    temp = (unsigned char*)malloc(3* x * sizeof(unsigned char));
    Image img(y, x, RGB_COMPONENT_COLOR,2);

    for (int i=img.getRows()-1; i>=0; i--)  {
        fread(temp, sizeof(temp[0]), 3* x, fp);
        for (int j = img.getCols()-1; j >= 0 ; j--) {
            img.setCell(2,i,j,temp[(img.getCols()-1-j)*3]);
            img.setCell(1,i,j,temp[(img.getCols()-1-j)*3+1]);
            img.setCell(0,i,j,temp[(img.getCols()-1-j)*3+2]);
        } 
    }

    fclose(fp);

    return img;
}

//save colored image to ppm file
void writePPM(const char *filename, Image img)
{
    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) {
         cout<<"Unable to open file '%s'\n";
         exit(1);
    }

    //write the header file
    //image format
    fprintf(fp, "P6\n");

    //image size
    fprintf(fp, "%d %d\n", img.getCols(), img.getRows());
    cout<<"Size: "<<img.getCols()<<"x"<<img.getRows()<<"\n";

    // rgb component depth
    fprintf(fp, "%d\n",RGB_COMPONENT_COLOR);
    cout<<RGB_COMPONENT_COLOR<<"\n";

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
//     Image image = readBMP("bmp_sample.bmp");
//     writePPM("bmp_result.ppm",image);
// }