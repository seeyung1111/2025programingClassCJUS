#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// 행렬 생성 (0~9 정수 무작위)
void generateMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            mat[i][j] = rand() % 10; // 0~9 무작위
}

// 행렬 출력
void printMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%4d", mat[i][j]);
        printf("\n");
    }
}

// 행렬 덧셈
void addMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = A[i][j] + B[i][j];
}

// 행렬 뺄셈
void subMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = A[i][j] - B[i][j];
}

// 스칼라 곱
void scalarMultiply(int mat[SIZE][SIZE], int scalar, int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = mat[i][j] * scalar;
}

// 행렬 곱셈
void multiplyMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
}

// 3x3 행렬 행렬식 계산
int determinant(int mat[SIZE][SIZE]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
        - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
        + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

// 역행렬 계산 (행렬식 != 0일 때만)
void inverseMatrix(int mat[SIZE][SIZE], double inv[SIZE][SIZE]) {
    int det = determinant(mat);
    if (det == 0) {
        printf("역행렬 존재하지 않음 (행렬식 = 0)\n");
        return;
    }

    // 수반행렬(Adjoint) 계산
    inv[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) / (double)det;
    inv[0][1] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]) / (double)det;
    inv[0][2] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) / (double)det;

    inv[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) / (double)det;
    inv[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) / (double)det;
    inv[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]) / (double)det;

    inv[2][0] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) / (double)det;
    inv[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]) / (double)det;
    inv[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) / (double)det;
}

// double 행렬 출력
void printDoubleMatrix(double mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%8.3f", mat[i][j]);
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // 난수 초기화

    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int scalar;

    // 행렬 및 스칼라 생성
    generateMatrix(A);
    generateMatrix(B);
    scalar = rand() % 10; // 0~9 정수

    printf("행렬 A:\n");
    printMatrix(A);
    printf("\n행렬 B:\n");
    printMatrix(B);
    printf("\n스칼라: %d\n", scalar);

    // 덧셈
    addMatrix(A, B, C);
    printf("\nA + B:\n");
    printMatrix(C);

    // 뺄셈
    subMatrix(A, B, C);
    printf("\nA - B:\n");
    printMatrix(C);

    // 스칼라 곱
    scalarMultiply(A, scalar, C);
    printf("\nA * scalar:\n");
    printMatrix(C);

    // 행렬 곱
    multiplyMatrix(A, B, C);
    printf("\nA * B:\n");
    printMatrix(C);

    // 역행렬 계산
    double inv[SIZE][SIZE];
    printf("\nA 역행렬:\n");
    inverseMatrix(A, inv);
    printDoubleMatrix(inv);

    printf("\nB 역행렬:\n");
    inverseMatrix(B, inv);
    printDoubleMatrix(inv);

    return 0;
}