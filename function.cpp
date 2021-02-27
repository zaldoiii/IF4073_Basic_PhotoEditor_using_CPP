// #include "Image.cpp"
#include "read_image/pgm.cpp"
#include <iostream>
using namespace std;

/*
Function for Addition
Adding two images into a new image
*/
Grayscale addition(Grayscale img_1, Grayscale img_2){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());
    unsigned char temp;

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            temp = img_1.getCell(i,j) + img_2.getCell(i,j);

            if (temp>result_img.getGray())   {
                result_img.setCell(i,j,result_img.getGray());
            }
            else    {
                result_img.setCell(i,j,temp);
            }
        }
    }
    return result_img;
}

/*
Function for Substraction
Subtract first image with second image into a new image
*/
Grayscale substraction(Grayscale img_1, Grayscale img_2){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());
    unsigned char temp;

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            temp = img_1.getCell(i,j) - img_2.getCell(i,j);

            if (temp!=0)   {
                result_img.setCell(i,j,result_img.getGray());
            }
            else    {
                result_img.setCell(i,j,0);
            }
        }
    }
    return result_img;
}

/*
Function for AND Operation
Apply AND operation for first image against second image
*/
Grayscale ANDOperation(Grayscale img_1, Grayscale img_2){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            result_img.setCell(i,j,img_1.getCell(i,j) & img_2.getCell(i,j));
        }
    }
    return result_img;
}

/*
Function for OR Operation
Apply OR operation for first image against second image
*/
Grayscale OROperation(Grayscale img_1, Grayscale img_2){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            result_img.setCell(i,j,img_1.getCell(i,j) | img_2.getCell(i,j));
        }
    }
    return result_img;
}

/*
Function for XOR Operation
Apply XOR operation for first image against second image
*/
Grayscale XOROperation(Grayscale img_1, Grayscale img_2){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            result_img.setCell(i,j,img_1.getCell(i,j) ^ img_2.getCell(i,j));
        }
    }
    return result_img;
}

/*
Function for NOT Operation
Apply NOT operation for an image
*/
Grayscale NOTOperation(Grayscale img_1){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            result_img.setCell(i,j,~img_1.getCell(i,j));
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
Grayscale translation(Grayscale img_1,int m, int n){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            if((i-m >= 0) && (j-n >= 0))    {
                result_img.setCell(i,j,img_1.getCell(i-m,j-n));
            }
            else{
                result_img.setCell(i,j,0);
            }
        }
    }
    return result_img;
}

/*
Function for Rotation 90 Counterclockwise
Apply rotation 90 degrees counterclockwise for an image 
*/
Grayscale rotation90CCW(Grayscale img_1){
    Grayscale result_img(img_1.getCols(),img_1.getRows(),img_1.getGray());
    int k;

    for (int i=0; i<=img_1.getRows()-1; i++)
    {
        k = img_1.getCols() - 1;
        for (int j=0; j<=img_1.getCols()-1; j++)
        {
            result_img.setCell(k,i,img_1.getCell(i,j));
            k--;
        }
    }
    return result_img;
}

/*
Function for Rotation 90 Clockwise
Apply rotation 90 degrees clockwise for an image 
*/
Grayscale rotation90CW(Grayscale img_1){
    Grayscale result_img(img_1.getCols(),img_1.getRows(),img_1.getGray());
    int k;

    k=img_1.getCols()-1;
    for (int i=0; i<=img_1.getRows()-1; i++) {
        for (int j=0; j<=img_1.getCols()-1; j++) {
            result_img.setCell(j,k,img_1.getCell(i,j));
        }
        // cout<<i<<"\n";
        k--;
    }
    // cout<<"finish\n";
    return result_img;
}

/*
Function for vertical flipping
Apply X-axis (cartesian) reflection of image 
*/
Grayscale verticalFlip(Grayscale img_1){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            result_img.setCell(i,j,img_1.getCell(img_1.getRows()-1-i,j));
        }
    }
    return result_img;
}

/*
Function for horizontal flipping
Apply Y-axis (cartesian) reflection of image 
*/
Grayscale horizontalFlip(Grayscale img_1){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            result_img.setCell(i,j,img_1.getCell(i,img_1.getCols()-1-j));
        }
    }
    return result_img;
}

/*
Function for point of origin relection flipping
Apply mirroring at the point of origin (0,0) reflection of image 
*/
Grayscale POFFlip(Grayscale img_1){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            result_img.setCell(i,j,img_1.getCell(img_1.getRows()-1-i,img_1.getCols()-1-j));
        }
    }
    return result_img;
}

/*
Function for reflection on x=y line flipping
Apply mirroring reflection on the line x = y of image 
*/
Grayscale xyFlip(Grayscale img_1){
    Grayscale result_img(img_1.getCols(),img_1.getRows(),img_1.getGray());

    for (int i = 0; i < result_img.getRows(); i++) {
        for (int j = 0; j < result_img.getCols(); j++) {
            result_img.setCell(i,j,img_1.getCell(j,i));
        }
    }
    return result_img;
}

/*
Function for Zoom Out Image 2 times 
Apply magnification of image by a scale factor of 2
*/
Grayscale zoomOut(Grayscale img_1){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());
    int m = 0;
    int n = 0;

    for (int i = 0; i < result_img.getRows()/2; i++) {
        for (int j = 0; j < result_img.getCols()/2; j++) {
            result_img.setCell(m,n,img_1.getCell(i,j));
            result_img.setCell(m,n+1,img_1.getCell(i,j));
            result_img.setCell(m+1,n,img_1.getCell(i,j));
            result_img.setCell(m+1,n+1,img_1.getCell(i,j));
            n=n+2;
        }
        m=m+2;
        n=0;
    }
    return result_img;
}

/*
Function for Zoom In Image 2 times 
Apply magnification of image by a scale factor of 1/2
*/
Grayscale zoomIn(Grayscale img_1){
    Grayscale result_img(img_1.getRows(),img_1.getCols(),img_1.getGray());
    unsigned char temp;
    int m = 0;
    int n = 0;

    for (int i = 0; i < result_img.getRows()/2; i++) {
        for (int j = 0; j < result_img.getCols()/2; j++) {
            temp = (img_1.getCell(m,n)+img_1.getCell(m+1,n)+img_1.getCell(m,n+1)+img_1.getCell(m+1,n+1))/4;
            result_img.setCell(i,j,temp);
            n=n+2;
        }
        m=m+2;
        n=0;
    }
    return result_img;
}

/*
Function for Gray Level Slicing while Preserve Background
Change pixel value in range a~b to value val while preserving other pixel value same
int a : range starting value
int b : range stopping value
unsigned char :  value to be set
*/
Grayscale preserveBackgroundGrayLevelSlicing(Grayscale img, int a, int b, unsigned char val){
    Grayscale result_img(img.getRows(),img.getCols(),img.getGray());

    for (int i = 0; i < img.getRows(); i++) {
        for (int j = 0; j < img.getCols(); j++) {
            if ((img.getCell(i,j)>a) && (img.getCell(i,j)<b))   {
                result_img.setCell(i,j,255);
            }
            else    {
                result_img.setCell(i,j,img.getMatriks()[i][j]); 
            }
        }
    }

    return result_img;
}

/*
Function for Gray Level Slicing while Discarding Background
Change pixel value in range a~b to value val while chaneg other pixel value to discard_val
int a : range starting value
int b : range stopping value
unsigned char val:  value to be set for pixel in range a~b
unsigned char discard_val:  value to be set for pixel outside range a~b
*/
Grayscale discardBackgroundGrayLevelSlicing(Grayscale img, int a, int b, unsigned char val, unsigned char discard_val){
    Grayscale result_img(img.getRows(),img.getCols(),img.getGray());

    for (int i = 0; i < img.getRows(); i++) {
        for (int j = 0; j < img.getCols(); j++) {
            if((img.getCell(i,j)>a) && (img.getCell(i,j)<b))   {
                result_img.setCell(i,j,val);
            }
            else    {
                result_img.setCell(i,j,discard_val); 
            }
        }
    }
    return result_img;
}

/*
function to convert decimal to binary 
*/
// int* decToBinary(int n)  { 
//     int* binaryNum = new int[8];
//     int i = 0; 

//     while (n > 0) { 
//         binaryNum[i] = n % 2; 
//         n = n / 2; 
//         i++; 
//     } 

//     return binaryNum;
// } 

/*
Function for Bit Plane Slicing
Highlight the contribution of a particular bit in the image
int plane : choice of plane of bit to be highlighted (value : 0~7)
*/
Grayscale bitPlaneSlicing(Grayscale img, int plane){
    Grayscale result_img(img.getRows(),img.getCols(),img.getGray());

    for (int i = 0; i < img.getRows(); i++) {
        for (int j = 0; j < img.getCols(); j++) {
            // if(decToBinary(img.getCell(i,j))[7-plane])    {
            //     result_img.setCell(i,j,255);
            // }
            // else{
            //     result_img.setCell(i,j,0);
            // }
            unsigned char res = img.getCell(i,j);
            unsigned char t = 128;
            for(int b = 7; b>plane; b--)    {
                if(res-t>0)   {
                    res = res-t;
                }
                t = t/2;
            }
            result_img.setCell(i,j,res);
        }
    }
    return result_img;
}

int main(){
    Grayscale image = readPGM("pgm_sample.pgm");
    writePGM("new.pgm",bitPlaneSlicing(image,3));
}