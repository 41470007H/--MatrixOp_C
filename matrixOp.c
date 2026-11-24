#include "matrixOp.h"
void MatrixDet_2x2(float* matrix, float* result) {
    // Calculate the determinant of a 2x2 matrix
    *result = matrix[0] * matrix[3] - matrix[1] * matrix[2];
}