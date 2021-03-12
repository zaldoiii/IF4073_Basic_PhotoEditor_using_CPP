#include <iostream>
using namespace std; 

class Image 
{ 
    public: 
        //atribute
        int rows;       //number of rows
        int cols;       //number of columns
        int gray;       //number of gray levels
        unsigned char ***matriks; // 0 : red, 1 : green, 2 : blue
        int type; // 0 : biner, 1 : grayscale, 2 : coloredimg
        int rows_pad;
        int cols_pad;
        unsigned char ***matriks_padding; 

        //constructor
        Image(){
            this->rows = 0;
            this->cols = 0;
            this->gray = 0;
            this->type = 0;
            this->matriks = NULL;
            // this->rows_pad = 0;
            // this->cols_pad = 0;
            this->matriks_padding = NULL;  
        }

        Image(int numRows, int numCols, int grayLevels, int type){
            this->rows = numRows;
            this->cols = numCols;
            this->gray = grayLevels;
            this->type = type;
            // this->rows_pad = 0;
            // this->cols_pad = 0;
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

            // this->matriks_padding = new unsigned char**[3];
            // for (int i = 0; i < 3; i++){
            //     this->matriks_padding[i] = new unsigned char*[this->rows_pad];
            //     for (int j = 0; j < this->rows_pad; j++) {
            //         this->matriks_padding[i][j] = new unsigned char[this->cols_pad];
            //         for (int k = 0; k < this->cols_pad; k++) {
            //             this->matriks_padding[i][j][k] = 0;
            //         }
            //     }
            // }
        }

        Image(const Image &oldImage){
            this->rows = oldImage.rows;
            this->cols = oldImage.cols;
            this->gray = oldImage.gray; 
            this->type = oldImage.type;
            this->matriks = new unsigned char** [3];

            for (int i = 0; i < 3; i++){
                this->matriks[i] = new unsigned char*[this->rows];
                for (int j = 0; j < this->rows; j++) {
                    this->matriks[i][j] = new unsigned char[this->cols];
                    for (int k = 0; k < this->cols; k++) {
                        this->matriks[i][j][k] = oldImage.matriks[i][j][k];
                    }
                }
            }

            // this->matriks_padding = new unsigned char**[3];
            // for (int i = 0; i < 3; i++){
            //     this->matriks_padding[i] = new unsigned char*[this->rows_pad];
            //     for (int j = 0; j < this->rows_pad; j++) {
            //         this->matriks_padding[i][j] = new unsigned char[this->cols_pad];
            //         for (int k = 0; k < this->cols_pad; k++) {
            //             this->matriks_padding[i][j][k] = oldImage.matriks_padding[i][j][k];
            //         }
            //     }
            // }
        }

        //destroyer
        ~Image(){
            this->rows = 0;
            this->cols = 0;
            this->gray = 0;
            this->type = 0;
            // this->rows_pad = 0;
            // this->cols_pad = 0;

            for (int i = 0; i < 3; i++){
                for (int j = 0; j < this->rows; j++){
                    delete[] this->matriks [i][j];
                }
                delete[] this->matriks[i];
            }
            delete[] this->matriks;

            // for (int i = 0; i < 3; i++){
            //     for (int j = 0; j < this->rows_pad; j++){
            //         delete[] this->matriks_padding [i][j];
            //     }
            //     delete[] this->matriks_padding[i];
            // }
            // delete[] this->matriks_padding;
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

        unsigned char ***getMatriks(){
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
                	    cout << unsigned(this->matriks[i][j][k]) << " "; 
                    } 
                    cout << endl; 
                }
                cout << endl; 
            }
        }

        // int getRowsPad(){
        //     return this->rows_pad;
        // }

        // int getColsPad(){
        //     return this->cols_pad;
        // }

        // void setCellPad(int i, int j, int k, unsigned char val){
        //     this->matriks_padding[i][j][k] = val;
        // }

        // void createPadding(int rows_kernel, int cols_kernel){
        //     int diff_row, diff_col;
        //     if (rows_kernel % 2 == 0){
        //         this->rows_pad = this->rows + rows_kernel - 1;
        //         diff_row = rows_kernel/2;
        //     } else if (rows_kernel % 2 == 1) {
        //         this->rows_pad = this->rows + rows_kernel;
        //         diff_row = rows_kernel/2;
        //     }

        //     if (cols_kernel % 2 == 0){
        //         this->cols_pad = this->cols + cols_kernel - 1;
        //         diff_col = cols_kernel/2;
        //     } else if (cols_kernel % 2 == 1) {
        //         this->cols_pad = this->cols + cols_kernel;
        //         diff_col = cols_kernel/2;
        //     }

        //     this->matriks_padding = new unsigned char**[3];
        //     for (int i = 0; i < 3; i++){
        //         this->matriks_padding[i] = new unsigned char*[this->rows_pad];
        //         for (int j = 0; j < this->rows_pad; j++) {
        //             this->matriks_padding[i][j] = new unsigned char[this->cols_pad];
        //             for (int k = 0; k < this->cols_pad; k++) {
        //                 if((j >= diff_row) && (j <= this->rows_pad - diff_row - 1) && (k >= diff_col) && (k <= this->cols_pad - diff_col - 1)){
        //                     this->matriks_padding[i][j][k] = this->matriks[i][j-diff_row][k-diff_col];
        //                 } else {
        //                     this->matriks_padding[i][j][k] = 0;
        //                 }
        //             }
        //         }
        //     }
        // }

        // void printMatriksPadding(){
        //     for (int i = 0; i < 3; i++){
        //         for (int j = 0; j < this->rows_pad; j++){ 
        //             for (int k = 0; k < this->cols_pad; k++){ 
        //         	    cout << unsigned(this->matriks_padding[i][j][k]) << " "; 
        //             } 
        //             cout << endl; 
        //         }
        //         cout << endl; 
        //     }
        // }
}; 

// int main() {
//     cout << "Testing" << endl; 

//     Image clr(5,5,3,2);
//     cout << clr.getRows() << endl; 
//     clr.printMatriks();
//     clr.createPadding(4,4);
//     clr.printMatriksPadding();
    
//     return 0; 
// };