// #include "Image.cpp"
#include "read_image/pgm.cpp"
#include <iostream>
using namespace std;

/*
Function citra negatif
*/
Image negatif(Image img){
    Image result_img(img.getRows(),img.getCols(),img.getGray(),img.getType());
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img.getGray() - img.getCell(k,i,j));
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
    int tmp;

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
Image brightening(Image img, int option, int scale){
    Image result_img(img.getRows(),img.getCols(),img.getGray(), img.getType());
    int tmp;

    for (int k = 0; k < 3; k++){
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                if (option == 0){
                    tmp = img.getCell(k,i,j) + scale;
                } else if (option == 1){
                    tmp = img.getCell(k,i,j) - scale;
                } else if (option == 2){
                    tmp = img.getCell(k,i,j)*scale;
                } else if (option == 3){
                    tmp = img.getCell(k,i,j)/scale;
                }

                if(tmp > img.getGray()){
                    tmp = img.getGray();
                } else if (tmp < 0){
                    tmp = 0;
                }
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
    unsigned char temp;

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                temp = img_1.getCell(k,i,j) + img_2.getCell(k,i,j);

                if (temp>result_img.getGray())   {
                    result_img.setCell(k,i,j,result_img.getGray());
                }
                else    {
                    result_img.setCell(k,i,j,temp);
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
    unsigned char temp;

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                temp = img_1.getCell(k,i,j) - img_2.getCell(k,i,j);

                if (temp!=0)   {
                    result_img.setCell(k,i,j,result_img.getGray());
                }
                else    {
                    result_img.setCell(k,i,j,0);
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

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img_1.getCell(k,i,j) & img_2.getCell(k,i,j));
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

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img_1.getCell(k,i,j) | img_2.getCell(k,i,j));
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

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows(); i++) {
            for (int j = 0; j < result_img.getCols(); j++) {
                result_img.setCell(k,i,j,img_1.getCell(k,i,j) ^ img_2.getCell(k,i,j));
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
            for (int j = 0; j < result_img.getCols(); j++) {
                if((i-m >= 0) && (j-n >= 0))    {
                    result_img.setCell(k,i,j,img_1.getCell(k,i-m,j-n));
                }
                else{
                    result_img.setCell(k,i,j,0);
                }
            }
        }
    }
    return result_img;
}

/*
Function for Rotation 90 Counterclockwise
Apply rotation 90 degrees counterclockwise for an image 
*/
Image rotation90CCW(Image img_1){
    Image result_img(img_1.getCols(),img_1.getRows(),img_1.getGray(),img_1.getType());
    int k;

    for (int l = 0; l < 3; l++) {
        for (int i=0; i<=img_1.getRows()-1; i++)
        {
            k = img_1.getCols() - 1;
            for (int j=0; j<=img_1.getCols()-1; j++)
            {
                result_img.setCell(l,k,i,img_1.getCell(l,i,j));
                k--;
            }
        }
    }
    return result_img;
}

/*
Function for Rotation 90 Clockwise
Apply rotation 90 degrees clockwise for an image 
*/
Image rotation90CW(Image img_1){
    Image result_img(img_1.getCols(),img_1.getRows(),img_1.getGray(),img_1.getType());
    int k;

    for (int l = 0; l < 3; l++) {
        k=img_1.getCols()-1;
        for (int i=0; i<=img_1.getRows()-1; i++) {
            for (int j=0; j<=img_1.getCols()-1; j++) {
                result_img.setCell(l,j,k,img_1.getCell(l,i,j));
            }
            k--;
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
Image zoomOut(Image img_1){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());
    int m = 0;
    int n = 0;

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < result_img.getRows()/2; i++) {
            for (int j = 0; j < result_img.getCols()/2; j++) {
                result_img.setCell(k,m,n,img_1.getCell(k,i,j));
                result_img.setCell(k,m,n+1,img_1.getCell(k,i,j));
                result_img.setCell(k,m+1,n,img_1.getCell(k,i,j));
                result_img.setCell(k,m+1,n+1,img_1.getCell(k,i,j));
                n=n+2;
            }
            m=m+2;
            n=0;
        }
    }
    return result_img;
}

/*
Function for Zoom In Image 2 times 
Apply magnification of image by a scale factor of 1/2
*/
Image zoomIn(Image img_1){
    Image result_img(img_1.getRows(),img_1.getCols(),img_1.getGray(),img_1.getType());
    unsigned char temp;
    int m = 0;
    int n = 0;

for (int k = 0; k < 3; k++) {
    for (int i = 0; i < result_img.getRows()/2; i++) {
        for (int j = 0; j < result_img.getCols()/2; j++) {
            temp = (img_1.getCell(k,m,n)+img_1.getCell(k,m+1,n)+img_1.getCell(k,m,n+1)+img_1.getCell(k,m+1,n+1))/4;
            result_img.setCell(k,i,j,temp);
            n=n+2;
        }
        m=m+2;
        n=0;
    }
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
Image preserveBackgroundGrayLevelSlicing(Image img, int a, int b, unsigned char val){
    Image result_img(img.getRows(),img.getCols(),img.getGray(),img.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < img.getRows(); i++) {
            for (int j = 0; j < img.getCols(); j++) {
                if ((img.getCell(k,i,j)>a) && (img.getCell(k,i,j)<b))   {
                    result_img.setCell(k,i,j,img.getGray());
                }
                else    {
                    result_img.setCell(k,i,j,img.getCell(k,i,j)); 
                }
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
Image discardBackgroundGrayLevelSlicing(Image img, int a, int b, unsigned char val, unsigned char discard_val){
    Image result_img(img.getRows(),img.getCols(),img.getGray(),img.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < img.getRows(); i++) {
            for (int j = 0; j < img.getCols(); j++) {
                if((img.getCell(k,i,j)>a) && (img.getCell(k,i,j)<b))   {
                    result_img.setCell(k,i,j,val);
                }
                else    {
                    result_img.setCell(k,i,j,discard_val); 
                }
            }
        }
    }
    return result_img;
}

/*
Function for Bit Plane Slicing
Highlight the contribution of a particular bit in the image
int plane : choice of plane of bit to be highlighted (value : 0~7)
*/
Image bitPlaneSlicing(Image img, int plane){
    Image result_img(img.getRows(),img.getCols(),img.getGray(),img.getType());

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < img.getRows(); i++) {
            for (int j = 0; j < img.getCols(); j++) {
                unsigned char res = img.getCell(k,i,j);
                unsigned char t = 128;
                for(int b = 7; b>plane; b--)    {
                    if(res-t>0)   {
                        res = res-t;
                    }
                    t = t/2;
                }
                result_img.setCell(k,i,j,res);
            }
        }
    }
    return result_img;
}

int main(){
    Image image = readPGM("pgm_sample.pgm");
    writePGM("new.pgm",bitPlaneSlicing(image,3));
}