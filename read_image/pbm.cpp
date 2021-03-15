#include<stdio.h>
#include<stdlib.h>
#include"../Image.cpp"
#include<iostream>
// using namespace std;

/*
function to convert decimal to binary 
*/
int* decToBinary(int n)  { 
    int* binaryNum = new int[8];
    for (int i = 7; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
          binaryNum[7-i]=1; 
        else
          binaryNum[7-i]=0;
    } 
    return binaryNum;
} 

int binaryToDec(int* binaryNum)  { 
    int n = 0;
    int base = 1;

    int i = 7; 
    while (i >= 0) { 
          if(binaryNum[i]==0)  {
               n+=base;
          }
          base = base*2;
          i = i-1; 
    } 
    return n;
} 

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
          fread(temp, sizeof(temp[0]), img.getCols()/8, fp);
          int j=0;
          int count=0;
          while(j < img.getCols()) {
               int* binary_representation = new int[8];
               binary_representation = decToBinary((int)temp[count]);
               for (int k = 0; k < 8; k++) {
                    if(binary_representation[k]==0)    {
                         img.setCell(0,i,j+k,255);
                         img.setCell(1,i,j+k,255);
                         img.setCell(2,i,j+k,255);
                    }
                    else {     
                         img.setCell(0,i,j+k,0);
                         img.setCell(1,i,j+k,0);
                         img.setCell(2,i,j+k,0);
                    }
               }
               j+=8;
               count+=1;
          }
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

          int j=0;
          int count=0;

          while(j<img.getCols())   {
               int binary_representation[8] = {
                    img.getCell(0,i,j), 
                    img.getCell(0,i,j+1), 
                    img.getCell(0,i,j+2), 
                    img.getCell(0,i,j+3), 
                    img.getCell(0,i,j+4), 
                    img.getCell(0,i,j+5), 
                    img.getCell(0,i,j+6), 
                    img.getCell(0,i,j+7) 
               };
               temp[count] = binaryToDec(binary_representation);
               j+=8;
               count+=1;
          }
          fwrite(temp, sizeof(temp[0]), img.getCols()/8, fp);
     }
     
    fclose(fp);
}

int main(){
    Image image = readPBM("pbm_sample.pbm");
    writePBM("pbm_result.pbm",image);
}