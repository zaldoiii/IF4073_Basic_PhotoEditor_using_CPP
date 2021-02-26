#include <iostream>
using namespace std; 

class Image 
{ 
    public: 
        //atribute
        int rows;       //number of rows
        int cols;       //number of columns
        int gray;       //number of gray levels

        //constructor
        Image(){
            this->rows = 0;
            this->cols = 0;
            this->gray = 0;
        }

        Image(int numRows, int numCols, int grayLevels){
            this->rows = numRows;
            this->cols = numCols;
            this->gray = grayLevels;
        }

        Image(const Image &oldImage){
            this->rows = oldImage.rows;
            this->cols = oldImage.cols;
            this->gray = oldImage.gray; 
            // this->matriks = new int* [rows];
            // for (int i = 0; i < rows; i++) {
            //     this->matriks[i] = new int [this->cols];
            //     for (int j = 0; j < this->cols; j++)
            //         this->matriks[i][j] = oldImage.matriks[i][j];
            // }   
        }
    
        //method 
        int getRows(){
            return this->rows;
        }
        int getCols(){
            return this->cols;
        }
        int getGray(){
            return this->gray;
        }

        void setImageInfo(int numRows, int numCols, int maxVal){
            numRows = this->rows;
            numCols = this->cols;
            maxVal = this->gray;
        }

        // Pure virtual function.
        // virtual int getCell(int i, int j) = 0;   
        // virtual void setCell(int i, int j, int val) = 0;   
        // virtual int **getMatriks() = 0;   
        virtual void printMatriks() = 0;
}; 


class Grayscale:public Image {
    public:
        // attribute
        unsigned char **matriks;

        //contructor
        Grayscale(){ 
            this->matriks = NULL;
        } 

        Grayscale(int numRows, int numCols, int grayLevels):Image(numRows, numCols, grayLevels){ 
            this->matriks = new unsigned char*[this->rows];
            for (int i = 0; i < this->rows; i++) {
                this->matriks[i] = new unsigned char[this->cols];
                for (int j = 0; j < this->cols; j++) {
                    this->matriks[i][j] = 0;
                }
            }
        }

        //destroyer
        ~Grayscale() {
            this->rows = 0;
            this->cols = 0;
            this->gray = 0;
        
            for (int i = 0; i < this->rows; i++)
                delete this->matriks [this->rows];
        
            delete this->matriks;
        }

        unsigned char getCell(int i, int j){
            return this->matriks[i][j];
        }
        
        void setCell(int i, int j, unsigned char val){
            this->matriks[i][j] = val;
        }

        unsigned char **getMatriks(){
            return this->matriks;
        }

        void printMatriks(){
            for (int i = 0; i < this->rows; i++){ 
                for (int j = 0; j < this->cols; j++){ 
            	    cout << this->matriks[i][j] << " "; 
                } 
                cout << endl; 
            }

        }
};

class ColoredImg:public Image {
    public:
        // attribute
        unsigned char ***matriks;

        //contructor
        ColoredImg(){ 
            this->matriks = NULL;
        } 

        ColoredImg(int numRows, int numCols, int grayLevels):Image(numRows, numCols, grayLevels){ 
            this->matriks = new unsigned char**[3];

            for (int i = 0; i < 3; i++){
                this->matriks[i] = new unsigned char*[this->rows];
                for (int j = 0; j < this->rows; j++) {
                    this->matriks[i][j] = new unsigned char[this->cols];
                    for (int k = 0; k < this->cols; k++) {
                        this->matriks[i][j][k] = 0;
                    }
                }
            }
        }

        //destroyer
        ~ColoredImg() {
            this->rows = 0;
            this->cols = 0;
            this->gray = 0;

            for (int i = 0; i < 3; i++){
                for (int j = 0; j < this->rows; j++){
                    delete[] this->matriks [i][j];
                }
                delete[] this->matriks[i];
            }
            delete[] this->matriks;
        }

        unsigned char getCell(int i, int j, int k){
            return this->matriks[i][j][k];
        }
        
        void setCell(int i, int j, int k, unsigned char val){
            this->matriks[i][j][k] = val;
        }

        unsigned char ***getMatriks(){
            return this->matriks;
        }

        void printMatriks(){
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < this->rows; j++){ 
                    for (int k = 0; k < this->cols; k++){ 
                	    cout << this->matriks[i][j][k] << " "; 
                    } 
                    cout << endl; 
                }
                cout << endl; 
            }
        }
};

// int main() {
//     cout << "Testing" << endl; 

//     Grayscale gray(3,2,3);
//     cout << gray.getRows() << endl; 
//     gray.setCell(1,1,10);
//     gray.printMatriks();

//     ColoredImg clr(4,2,3);
//     cout << clr.getRows() << endl; 
//     clr.printMatriks();
    
//     return 0; 
// };