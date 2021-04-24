//https://leetcode.com/problems/search-a-2d-matrix/submissions/



bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
      bool f=0;
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<*matrixColSize;j++){
            if(matrix[i][j]==target){
                f = 1; 
                break;
            }
        }
    }
    return f;
}
