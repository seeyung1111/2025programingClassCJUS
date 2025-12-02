#include <stdio.h>

int main() {
    // 1. 배열 선언 및 초기화 (정적 배열)
    int numbers[5] = { 10, 20, 30, 40, 50 }; // 5개의 정수를 저장하는 배열
    char message[] = "Hello";              // 문자열도 사실은 char 배열!

    // 2. 배열 요소 접근
    printf("첫 번째 숫자: %d\n", numbers[0]); // 인덱스 0부터 시작!
    printf("세 번째 문자: %c\n", message[2]);

    // 3. 배열 순회 (반복문으로 모두 출력)
    printf("모든 숫자: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // 4. 배열의 이름은 사실 첫 번째 요소의 주소!
    printf("배열 numbers의 시작 주소: %p\n", numbers);
    printf("numbers[0]의 주소: %p\n", &numbers[0]); // 같다는 걸 알 수 있어!

    // 5. 배열의 전체 크기 (바이트 단위)
    printf("배열 numbers의 크기: %zu 바이트\n", sizeof(numbers)); // int 5개니까 4*5=20 바이트!

    return 0;
}