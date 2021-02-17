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
        int** getMatriks();
        
        void setWidth(int w);
        void setHeight(int h);
        void setMatriks(int **mat)

};
#endif