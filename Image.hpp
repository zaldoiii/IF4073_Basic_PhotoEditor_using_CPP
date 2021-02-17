#ifndef IMAGE_HPP
#define IMAGE_HPP

class Image
{
    protected:
        //atribute
        int width;
        int height;
        int **matriks;

    public:
        //constructor
        Image(int width, int height);

        //destroyer
        ~Image();
    
        //method 
        int getWidth();
        int getHeight();
        
        void setWidth(int w);
        void setHeight(int h);

};
#endif