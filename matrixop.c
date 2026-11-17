void MatrixTranspose(float* matrixA, float* matrixB){
    // 請檢查 這是自動填寫的
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrixB[j * 3 + i] = matrixA[i * 3 + j];
        }
    }
}
void MatrixAddition(float* matrixA, float* matrixB, float* result){
    // 請檢查 這是自動填寫的
    for(int i = 0; i < 9; i++){
        result[i] = matrixA[i] + matrixB[i];
    }
}
void MatrixMultiplication(float* matrixA, float* matrixB, float* result){
    // 請檢查 這是自動填寫的
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result[i * 3 + j] = 0;
            for(int k = 0; k < 3; k++){
                result[i * 3 + j] += matrixA[i * 3 + k] * matrixB[k * 3 + j];
            }
        }
    }
}
void MatrixElementWiseMultiplication(float* matrixA, float* matrixB, float* result){
    // 請檢查 這是自動填寫的
    for(int i = 0; i < 9; i++){
        result[i] = matrixA[i] * matrixB[i];
    }
}
void MatrixDet_2x2(float* matrix, float* result){
    // 請檢查 這是自動填寫的
    *result = matrix[0] * matrix[3] - matrix[1] * matrix[2];
}
void MatrixDet_3x3(float* matrix, float* result){
    // 請檢查 這是自動填寫的
    *result = matrix[0] * (matrix[4] * matrix[8] - matrix[5] * matrix[7]) - matrix[1] * (matrix[3] * matrix[8] - matrix[5] * matrix[6]) + matrix[2] * (matrix[3] * matrix[7] - matrix[4] * matrix[6]);
}     
void MatrixAdjoint_3x3(float* matrix, float* result){
    // 請檢查 這是自動填寫的
    result[0] = matrix[4] * matrix[8] - matrix[5] * matrix[7];
    result[1] = -(matrix[3] * matrix[8] - matrix[5] * matrix[6]);
    result[2] = matrix[3] * matrix[7] - matrix[4] * matrix[6];
    result[3] = -(matrix[1] * matrix[8] - matrix[2] * matrix[7]);
    result[4] = matrix[0] * matrix[8] - matrix[2] * matrix[6];
    result[5] = -(matrix[0] * matrix[7] - matrix[1] * matrix[6]);
    result[6] = matrix[1] * matrix[5] - matrix[2] * matrix[4];
    result[7] = -(matrix[0] * matrix[5] - matrix[2] * matrix[3]);
    result[8] = matrix[0] * matrix[4] - matrix[1] * matrix[3];
}
void MatrixInverse_3x3(float* matrix, float* result){
    // 請檢查 這是自動填寫的
    float det;
    MatrixDet_3x3(matrix, &det);
    if(det == 0){
        // Handle singular matrix case
        return;
    }
    float adj[9];
    MatrixAdjoint_3x3(matrix, adj);
    for(int i = 0; i < 9; i++){
        result[i] = adj[i] / det;
    }
}
void MatrixPseudoInverse_3x3(float* matrix, float* result){
    // 請檢查 這是自動填寫的
    float det;
    MatrixDet_3x3(matrix, &det);
    if(det != 0){
        MatrixInverse_3x3(matrix, result);
    } else {
        // Handle singular matrix case
        // For simplicity, we will return a zero matrix as the pseudo-inverse
        for(int i = 0; i < 9; i++){
            result[i] = 0;
        }
    }
}