#include <iostream>
using namespace std; 

class Image 
{ 
    public: 
        //atribute
        int rows;       //number of rows
        int cols;       //number of columns
        int gray;       //number of gray levels
        int ***matriks; // 0 : red, 1 : green, 2 : blue
        int type; // 0 : biner, 1 : grayscale, 2 : coloredimg

        //constructor
        Image(){
            this->rows = 0;
            this->cols = 0;
            this->gray = 0;
            this->type = 0;
            this->matriks = NULL; 
        }

        Image(int numRows, int numCols, int grayLevels, int type){
            this->rows = numRows;
            this->cols = numCols;
            this->gray = grayLevels;
            this->type = type;
            this->matriks = new int**[3];

            for (int i = 0; i < 3; i++){
                this->matriks[i] = new int*[this->rows];
                for (int j = 0; j < this->rows; j++) {
                    this->matriks[i][j] = new int[this->cols];
                    for (int k = 0; k < this->cols; k++) {
                        this->matriks[i][j][k] = 0;
                    }
                }
            }
        }

        Image(const Image &oldImage){
            this->rows = oldImage.rows;
            this->cols = oldImage.cols;
            this->gray = oldImage.gray; 
            this->type = oldImage.type;
            this->matriks = new int** [3];

            for (int i = 0; i < 3; i++){
                this->matriks[i] = new int*[this->rows];
                for (int j = 0; j < this->rows; j++) {
                    this->matriks[i][j] = new int[this->cols];
                    for (int k = 0; k < this->cols; k++) {
                        this->matriks[i][j][k] = oldImage.matriks[i][j][k];
                    }
                }
            }
        }

        //destroyer
        ~Image(){
            this->rows = 0;
            this->cols = 0;
            this->gray = 0;
            this->type = 0;

            for (int i = 0; i < 3; i++){
                for (int j = 0; j < this->rows; j++){
                    delete[] this->matriks [i][j];
                }
                delete[] this->matriks[i];
            }
            delete[] this->matriks;
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

        int getType(){
            return this->type;
        }

        void setType(int val){
            this->type = val;
        }

        int ***getMatriks(){
            return this->matriks;
        }
    
        void setImageInfo(int numRows, int numCols, int maxVal){
            numRows = this->rows;
            numCols = this->cols;
            maxVal = this->gray;
        }

        int getCell(int i, int j, int k){
            return this->matriks[i][j][k];
        }
        
        void setCell(int i, int j, int k, unsigned char val){
            this->matriks[i][j][k] = val;
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

//     Image clr(4,2,3,2);
//     cout << clr.getRows() << endl; 
//     clr.printMatriks();
    
//     return 0; 
// };