#include <stdio.h>

int main() {
    int i, j;  // 반복 변수 2개 선언

    for (i = 2; i <= 9; i++) {           // i는 구구단 번호 (2단부터 9단까지)
        for (j = 1; j <= 9; j++) {       // j는 각 단의 곱하는 값(1부터 9까지)
            printf("%d * %d = %d\n", i, j, i * j);
        }
        printf("\n");  // 단과 단 사이 줄 바꿈
    }

    return 0;
}