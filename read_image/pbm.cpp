#include<stdio.h>
#include<stdlib.h>
#include"../Image.cpp"
#include<iostream>
using namespace std;

typedef struct foo
{
    unsigned char x;
} PPMPixel;

typedef struct {
     int x, y;
     PPMPixel *data;
} PBMImage;

static PBMImage *readPBM(const char *filename)
{
         char buff[16];
         PBMImage *img;
         FILE *fp;
         int c;
         //open PBM file for reading
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

    //alloc memory form image
    img = (PBMImage *)malloc(sizeof(PBMImage));
    if (!img) {
         cout<<"Unable to allocate memory\n";
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
    if (fscanf(fp, "%d %d", &img->x, &img->y) != 2) {
         cout<<"Invalid image size (error loading '%s')\n";
         exit(1);
    }

    while (fgetc(fp) != '\n') ;
    //memory allocation for pixel data
    img->data = (PPMPixel*)malloc(img->x * img->y * sizeof(PPMPixel));

    if (!img) {
         cout<<"Unable to allocate memory\n";
         exit(1);
    }

    //read pixel data from file
    cout<<sizeof(PPMPixel);
    if (fread(img->data, img->x, img->y, fp) != img->y) {
         cout<<"Error loading image '%s'\n";
        //  exit(1);
    }

    fclose(fp);
    return img;
}

//Save File to PBM
void writePBM(const char *filename, PBMImage *img)
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
    fprintf(fp, "%d %d\n",img->x,img->y);
    cout<<"Size: "<<img->x<<"x"<<img->y<<"\n";

    // pixel data
    fwrite(img->data, img->x, img->y, fp);
    
    fclose(fp);
}

void changeColorPBM(PBMImage *img)
{
    int i;
    if(img){

         for(i=0;i<img->x*img->y;i++){
              img->data[i].x = 1;
         }
    }
}

int main(){
    PBMImage *image;
    image = readPBM("pbm_sample.pbm");
    changeColorPBM(image);

    writePBM("pbm_result.pbm",image);
    cout<<"Press any key...";
    getchar();
}