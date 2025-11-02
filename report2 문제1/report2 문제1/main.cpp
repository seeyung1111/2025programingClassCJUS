#define _CRT_SECURE_NO_WARNINGS  // Visual Studio의 scanf 보안 경고 비활성화

#include <stdio.h>   // C 스타일 입출력 (printf, scanf)
#include <stdlib.h>  // exit() 함수 사용

// 문제분석 및 코딩전략:
// 1. 엘리베이터의 총 중량을 입력받는다.
// 2. 입력된 중량이 물리적으로 유효한지 검사한다.
// 3. 입력된 중량이 정격 중량(600kg) 이하인지 초과하는지 판단한다.
// 4. 결과에 따라 "OK" 또는 "Overload"를 출력한다.

int main(void) {
    double totalWeight;                 // 승객 및 짐을 포함한 총 중량
    const double RATED_CAPACITY = 600.0; // 엘리베이터의 정격 용량

    // 사용자에게 입력 요청
    printf("엘리베이터의 총 중량(kg)을 입력하세요: ");

    // scanf의 반환값으로 유효성 검사
    if (scanf("%lf", &totalWeight) != 1) {
        printf("invalid input: 숫자가 아닌 값이 입력되었습니다. 프로그램을 종료합니다.\n");
        exit(1);
    }

    // 음수 중량 입력 방지
    if (totalWeight < 0) {
        printf("invalid input: 음수 중량은 유효하지 않습니다. 프로그램을 종료합니다.\n");
        exit(1);
    }

    // 정격 용량 초과 여부 판단
    if (totalWeight <= RATED_CAPACITY) {
        printf("OK\n");
    }
    else {
        printf("Overload\n");
    }

    // 콘솔창이 바로 닫히지 않게 일시 정지 (Visual Studio용)
    system("pause");

    return 0;
}