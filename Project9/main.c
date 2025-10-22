#include <stdio.h>

int main() {
    int a, b;           // 사용자 입력 변수
    int sum, diff;      // 합과 차 저장

    // 입력
    printf("두 정수를 입력하세요 (예: 5 3): ");
    scanf("%d %d", &a, &b);

    // 합과 차 계산
    sum = a + b;
    diff = a - b;

    // 관계 연산자
    if (a > b) printf("%d가 %d보다 큽니다.\n", a, b);
    else if (a < b) printf("%d가 %d보다 작습니다.\n", a, b);
    else printf("두 수는 같습니다.\n");

    // 논리 연산자
    if ((a > 0) && (b > 0)) printf("두 수 모두 양수입니다.\n");
    if ((a % 2 == 0) || (b % 2 == 0)) printf("두 수 중 적어도 하나는 짝수입니다.\n");

    // 증감 연산자
    a++; b--;
    printf("증가/감소 후 a=%d, b=%d\n", a, b);

    // 결과 출력
    printf("합: %d, 차: %d\n", sum, diff);

    return 0;
}