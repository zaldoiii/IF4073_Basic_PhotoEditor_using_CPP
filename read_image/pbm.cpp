#include<stdio.h>
#include<stdlib.h>
#include"../Image.cpp"
#include<iostream>
using namespace std;

//read image from pbm file
Image readPBM(const char *filename)
{
     char buff[16];
     FILE *fp;
     int x, y, c, rgb_comp_color;
     unsigned char *temp;
     
     //open PbM file for reading
     fp = fopen(filename, "rb");
     if (!fp) {
          cout<<"Unable to open file '%s'\n";
          exit(1);
     }

     //read image format
     if (!fgets(buff, sizeof(buff), fp)) {
          perror(filename);
          exit(1);
     }

     //check the image format
     if (buff[0] != 'P' || buff[1] != '4') {
          cout<<"Invalid image format must be PBM\n";
          exit(1);
     }

     //check for comments
     c = getc(fp);
     while (c == '#') {
     while (getc(fp) != '\n') ;
          c = getc(fp);
     }

     ungetc(c, fp);
     //read image size information
     if (fscanf(fp, "%d %d", &x, &y) != 2) {
          cout<<"Invalid image size (error loading '%s')\n";
          exit(1);
     }

     while (fgetc(fp) != '\n') ;
     //memory allocation for pixel data
     temp = (unsigned char*)malloc(x * sizeof(unsigned char));
     Image img(y, x, 2,1);

     if (!img.getMatriks()) {
          cout<<"Unable to allocate memory\n";
          exit(1);
     }
     
     for (int i=0; i<img.getRows(); ++i)  {
          fread(temp, sizeof(temp[0]), img.getCols(), fp);
          for (int j = 0; j < img.getCols(); j++) {
               cout<<(int)temp[j]<<" ";
               img.setCell(0,i,j,temp[j]);
               img.setCell(1,i,j,temp[j]);
               img.setCell(2,i,j,temp[j]);
          } 
          cout<<"\n";
     }
     
     fclose(fp);

     return img;
}

//save Image image to pbm file
void writePBM(const char *filename, Image img)
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
     fprintf(fp, "P4\n");

     //image size
     fprintf(fp, "%d %d\n", img.getCols(), img.getRows());
     cout<<"Size: "<<img.getCols()<<"x"<<img.getRows()<<"\n";

     // pixel data
     unsigned char *temp;
     temp = (unsigned char*)malloc(img.getCols() * sizeof(unsigned char));
     
     for (int i=0; i<img.getRows(); ++i) {
          for (int j=0; j<img.getCols(); ++j) {
               temp[j] = img.getCell(0,i,j); 
          }
          fwrite(temp, sizeof(temp[0]), img.getCols(), fp);
     }
     
    fclose(fp);
}

int main(){
    Image image = readPBM("pbm_sample.pbm");
    writePBM("pbm_result.pbm",image);
}