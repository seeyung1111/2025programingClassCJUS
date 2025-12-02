#include <stdio.h>

int main() {
    // 1차원 배열
    int arr1[5] = { 1,2,3,4,5 };
    int* p1 = arr1; // 1차원 배열-포인터 호환
    printf("1차원 배열: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", *(p1 + i));
    printf("\n");

    // 2차원 배열
    int arr2[2][3] = { {1,2,3},{4,5,6} };
    int (*p2)[3] = arr2; // 2차원 배열-포인터
    printf("2차원 배열:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", p2[i][j]); // p2[i][j] 또는 *(*(p2+i)+j)
        printf("\n");
    }

    // 3차원 배열
    int arr3[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    int (*p3)[2][3] = arr3; // 3차원 배열-포인터
    printf("3차원 배열:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++)
                printf("%d ", p3[i][j][k]); // *(*(*(p3+i)+j)+k) 도 가능
            printf("\n");
        }
        printf("---\n");
    }

    return 0;
}