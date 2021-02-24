#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct {
     int x, y;
     unsigned char *data;
} PGMImage;

#define RGB_COMPONENT_COLOR 255

static PGMImage *readPGM(const char *filename)
{
         char buff[16];
         PGMImage *img;
         FILE *fp;
         int c, rgb_comp_color;
         //open PGM file for reading
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
    if (buff[0] != 'P' || buff[1] != '5') {
         cout<<"Invalid image format must be PGM\n";
         exit(1);
    }

    //alloc memory form image
    img = (PGMImage *)malloc(sizeof(PGMImage));
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

    //read rgb component
    if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
         cout<<"Invalid rgb component (error loading '%s')\n";
         exit(1);
    }

    //check rgb component depth
    if (rgb_comp_color!= RGB_COMPONENT_COLOR) {
         cout<<"'%s' does not have 8-bits components\n";
         exit(1);
    }

    while (fgetc(fp) != '\n') ;
    //memory allocation for pixel data
    img->data = (unsigned char*)malloc(img->x * img->y * sizeof(unsigned char));

    if (!img) {
         cout<<"Unable to allocate memory\n";
         exit(1);
    }

    //read pixel data from file
    if (fread(img->data, img->x, img->y, fp) != img->y) {
         cout<<"Error loading image '%s'\n";
         exit(1);
    }

    fclose(fp);
    return img;
}

//Save File to PGM
void writePGM(const char *filename, PGMImage *img)
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
    fprintf(fp, "P5\n");

    //image size
    fprintf(fp, "%d %d\n",img->x,img->y);
    cout<<"Size: "<<img->x<<"x"<<img->y<<"\n";

    // rgb component depth
    fprintf(fp, "%d\n",RGB_COMPONENT_COLOR);
    cout<<RGB_COMPONENT_COLOR<<"\n";

    // pixel data
    fwrite(img->data, img->x, img->y, fp);
    
    fclose(fp);
}

void changeColorPGM(PGMImage *img)
{
    int i;
    if(img){

         for(i=0;i<img->x*img->y;i++){
              img->data[i] = 128;
         }
    }
}

int main(){
    PGMImage *image;
    image = readPGM("pgm_sample.pgm");
    changeColorPGM(image);

    writePGM("pgm_result.pgm",image);
    cout<<"Press any key...";
    getchar();
}