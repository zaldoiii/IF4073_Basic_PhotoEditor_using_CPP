#include<stdio.h>
#include<stdlib.h>
#include"Image.cpp"
#include<iostream>

using namespace std;
using namespace Custom;

#define RGB_COMPONENT_COLOR 255

//read image from ppm file
Image readPPM(const char *filename)
{
     char buff[16];
     FILE *fp;
     int x, y, c, rgb_comp_color;
     unsigned char *temp;
     
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
     if (buff[0] != 'P' || buff[1] != '6') {
          cout<<"Invalid image format must be PPM\n";
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
     temp = (unsigned char*)malloc(3* x * sizeof(unsigned char));
     Image img(y, x, RGB_COMPONENT_COLOR,2);

     if (!img.getMatriks()) {
          cout<<"Unable to allocate memory\n";
          exit(1);
     }

     for (int i=0; i<img.getRows(); i++)  {
          fread(temp, sizeof(temp[0]), img.getCols()*3, fp);
          for (int j = 0; j < img.getCols(); j++) {
               for (int k = 0; k < 3; k++) {
                    img.setCell(k,i,j,temp[j*3+k]);
               }
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

Image readPGM(const char* filename)
{
    char buff[16];
    FILE* fp;
    int x, y, c, rgb_comp_color;
    unsigned char* temp;

    //open PGM file for reading
    fp = fopen(filename, "rb");
    if (!fp) {
        cout << "Unable to open file '%s'\n";
        exit(1);
    }

    //read image format
    if (!fgets(buff, sizeof(buff), fp)) {
        perror(filename);
        exit(1);
    }

    //check the image format
    if (buff[0] != 'P' || buff[1] != '5') {
        cout << "Invalid image format must be PGM\n";
        exit(1);
    }

    //check for comments
    c = getc(fp);
    while (c == '#') {
        while (getc(fp) != '\n');
        c = getc(fp);
    }

    ungetc(c, fp);
    //read image size information
    if (fscanf(fp, "%d %d", &x, &y) != 2) {
        cout << "Invalid image size (error loading '%s')\n";
        exit(1);
    }

    //read rgb component
    if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
        cout << "Invalid rgb component (error loading '%s')\n";
        exit(1);
    }

    //check rgb component depth
    if (rgb_comp_color != RGB_COMPONENT_COLOR) {
        cout << "'%s' does not have 8-bits components\n";
        exit(1);
    }

    while (fgetc(fp) != '\n');
    //memory allocation for pixel data
    temp = (unsigned char*)malloc(x * sizeof(unsigned char));
    Image img(y, x, RGB_COMPONENT_COLOR, 1);

    if (!img.getMatriks()) {
        cout << "Unable to allocate memory\n";
        exit(1);
    }

    for (int i = 0; i < img.getRows(); ++i) {
        fread(temp, sizeof(temp[0]), img.getCols(), fp);
        for (int j = 0; j < img.getCols(); j++) {
            img.setCell(0, i, j, temp[j]);
            img.setCell(1, i, j, temp[j]);
            img.setCell(2, i, j, temp[j]);
        }
    }

    fclose(fp);

    return img;
}

//save Image image to pgm file
void writePGM(const char* filename, Image img)
{
    FILE* fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) {
        cout << "Unable to open file '%s'\n";
        exit(1);
    }

    //write the header file
    //image format
    fprintf(fp, "P5\n");

    //image size
    fprintf(fp, "%d %d\n", img.getCols(), img.getRows());
    cout << "Size: " << img.getCols() << "x" << img.getRows() << "\n";

    // rgb component depth
    fprintf(fp, "%d\n", RGB_COMPONENT_COLOR);
    cout << RGB_COMPONENT_COLOR << "\n";

    // pixel data
    unsigned char* temp;
    temp = (unsigned char*)malloc(img.getCols() * sizeof(unsigned char));

    for (int i = 0; i < img.getRows(); ++i) {
        for (int j = 0; j < img.getCols(); ++j) {
            temp[j] = img.getCell(0, i, j);
        }
        fwrite(temp, sizeof(temp[0]), img.getCols(), fp);
    }

    fclose(fp);
}

Image readBMP(const char* filename)
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
    fread(info2, sizeof(unsigned char), buff2, fp);

    unsigned char* temp;
    temp = (unsigned char*)malloc(3 * x * sizeof(unsigned char));
    Image img(y, x, RGB_COMPONENT_COLOR, 2);

    for (int i = img.getRows() - 1; i >= 0; i--) {
        fread(temp, sizeof(temp[0]), 3 * x, fp);
        for (int j = img.getCols() - 1; j >= 0; j--) {
            img.setCell(2, i, j, temp[(img.getCols() - 1 - j) * 3]);
            img.setCell(1, i, j, temp[(img.getCols() - 1 - j) * 3 + 1]);
            img.setCell(0, i, j, temp[(img.getCols() - 1 - j) * 3 + 2]);
        }
    }

    fclose(fp);

    return img;
}

Image readRaw(const char* filename)
{
    int rgb_comp_color = 255;
    unsigned char* temp;

    //open PGM file for reading
    FILE* fp = fopen(filename, "rb");
    unsigned char info[4];

    // read the 54-byte header
    fread(info, sizeof(unsigned char), 4, fp);

    int x = 512;
    int y = 512;
    cout << x << " " << y << "\n";

    // while (fgetc(fp) != '\n') ;
    //memory allocation for pixel data
    temp = (unsigned char*)malloc(x * sizeof(unsigned char));
    Image img(y, x, RGB_COMPONENT_COLOR, 1);

    if (!img.getMatriks()) {
        cout << "Unable to allocate memory\n";
        exit(1);
    }

    for (int i = 0; i < img.getRows(); ++i) {
        fread(temp, sizeof(temp[0]), img.getCols(), fp);
        for (int j = 0; j < img.getCols(); j++) {
            img.setCell(0, i, j, temp[j]);
            img.setCell(1, i, j, temp[j]);
            img.setCell(2, i, j, temp[j]);
        }
    }
    fclose(fp);

    return img;
}

void writeRaw(const char* filename, Image img)
{
    FILE* fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) {
        cout << "Unable to open file '%s'\n";
        exit(1);
    }

    unsigned char* temp;
    temp = (unsigned char*)malloc(3 * img.getCols() * sizeof(unsigned char));

    // pixel data
    for (int i = 0; i < img.getRows(); ++i) {
        for (int j = 0; j < img.getCols(); ++j) {
            for (int k = 0; k < 3; ++k) {
                temp[j * 3 + k] = img.getCell(k, i, j);
            }
        }
        fwrite(temp, sizeof(temp[0]), 3 * img.getCols(), fp);
    }

    fclose(fp);
}

int* decToBinary(int n) {
    int* binaryNum = new int[8];
    for (int i = 7; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            binaryNum[7 - i] = 1;
        else
            binaryNum[7 - i] = 0;
    }
    return binaryNum;
}

int binaryToDec(int* binaryNum) {
    int n = 0;
    int base = 1;

    int i = 7;
    while (i >= 0) {
        if (binaryNum[i] == 0) {
            n += base;
        }
        base = base * 2;
        i = i - 1;
    }
    return n;
}

//read image from pbm file
Image readPBM(const char* filename)
{
    char buff[16];
    FILE* fp;
    int x, y, c, rgb_comp_color;
    unsigned char* temp;

    //open PbM file for reading
    fp = fopen(filename, "rb");
    if (!fp) {
        cout << "Unable to open file '%s'\n";
        exit(1);
    }

    //read image format
    if (!fgets(buff, sizeof(buff), fp)) {
        perror(filename);
        exit(1);
    }

    //check the image format
    if (buff[0] != 'P' || buff[1] != '4') {
        cout << "Invalid image format must be PBM\n";
        exit(1);
    }

    //check for comments
    c = getc(fp);
    while (c == '#') {
        while (getc(fp) != '\n');
        c = getc(fp);
    }

    ungetc(c, fp);
    //read image size information
    if (fscanf(fp, "%d %d", &x, &y) != 2) {
        cout << "Invalid image size (error loading '%s')\n";
        exit(1);
    }

    while (fgetc(fp) != '\n');
    //memory allocation for pixel data
    temp = (unsigned char*)malloc(x * sizeof(unsigned char));
    Image img(y, x, 2, 1);

    if (!img.getMatriks()) {
        cout << "Unable to allocate memory\n";
        exit(1);
    }

    for (int i = 0; i < img.getRows(); ++i) {
        fread(temp, sizeof(temp[0]), img.getCols() / 8, fp);
        int j = 0;
        int count = 0;
        while (j < img.getCols()) {
            int* binary_representation = new int[8];
            binary_representation = decToBinary((int)temp[count]);
            for (int k = 0; k < 8; k++) {
                if (binary_representation[k] == 0) {
                    img.setCell(0, i, j + k, 255);
                    img.setCell(1, i, j + k, 255);
                    img.setCell(2, i, j + k, 255);
                }
                else {
                    img.setCell(0, i, j + k, 0);
                    img.setCell(1, i, j + k, 0);
                    img.setCell(2, i, j + k, 0);
                }
            }
            j += 8;
            count += 1;
        }
    }

    fclose(fp);

    return img;
}

//save Image image to pbm file
void writePBM(const char* filename, Image img)
{
    FILE* fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) {
        cout << "Unable to open file '%s'\n";
        exit(1);
    }

    //write the header file
    //image format
    fprintf(fp, "P4\n");

    //image size
    fprintf(fp, "%d %d\n", img.getCols(), img.getRows());
    cout << "Size: " << img.getCols() << "x" << img.getRows() << "\n";

    // pixel data
    unsigned char* temp;
    temp = (unsigned char*)malloc(img.getCols() * sizeof(unsigned char));

    for (int i = 0; i < img.getRows(); ++i) {

        int j = 0;
        int count = 0;

        while (j < img.getCols()) {
            int binary_representation[8] = {
                 img.getCell(0,i,j),
                 img.getCell(0,i,j + 1),
                 img.getCell(0,i,j + 2),
                 img.getCell(0,i,j + 3),
                 img.getCell(0,i,j + 4),
                 img.getCell(0,i,j + 5),
                 img.getCell(0,i,j + 6),
                 img.getCell(0,i,j + 7)
            };
            temp[count] = binaryToDec(binary_representation);
            j += 8;
            count += 1;
        }
        fwrite(temp, sizeof(temp[0]), img.getCols() / 8, fp);
    }

    fclose(fp);
}