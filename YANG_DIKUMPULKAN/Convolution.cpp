class Convolution{
    private:
        //Attribute    
        int method;
        int rows;       //number of rows
        int cols;       //number of columns
        int convKernel[3][3];

        //constructor
        Convolution(){
            this->method = 0;
            this->rows = 0;
            this->cols = 0;
            this->convKernel[i][j] = NULL;
        }

        Convolution(int numRows, int numCols){
            this->method = 0;
            this->rows = numRows;
            this->cols = numCols;
            for (int i = 0; i < this->rows; i++){
                for (int j = 0; j < this->cols; j++){
                    this->convKernel[i][j] = 0;
                }                    
            }
        }
    
    public:
        void convolute(int **input, int **output, int **kernel){
            int convolute = 0; 
            int x, y; //input matrix index

            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    x = i;
                    y = j;

                    for (int k = 0; k < 3; k++)
                    {
                        for (int l = 0; l < 3; l++)
                        {
                            convolute += kernel[k][l] * input[x][y];
                            y++; // Move right.
                        }
                        x++; // Move down.
                        y = j; // Restart column position
                    }
                    output[i][j] = convolute; // Add result to output matrix.
                    convolute = 0; 
                }
            }
        }

        void setKernel(int **kernel){
            for (int i = 0; i < this->rows; i++){
                for (int j = 0; j < this->cols; j++){
                    convKernel[i][j] = kernel[i][j];
                }                    
            }
        }
};
