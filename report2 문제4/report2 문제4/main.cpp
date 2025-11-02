#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  // C 스타일 입출력
#include <stdlib.h> // exit() 사용
#include <math.h>   // pow() 함수

int main() {
    const double D = 0.05;       // 배관 내경 (m)
    const double rho = 998.2;    // 냉각수 밀도 (kg/m^3)
    const double mu = 0.001002;  // 냉각수 점도 (Pa·s)
    double V;                     // 유속 (m/s)

    printf("배관 내 유체의 유속(m/s)을 입력하세요: ");
    if (scanf_s("%lf", &V) != 1) { // scanf_s 사용
        printf("invalid input: 유속 입력이 잘못되었습니다. 프로그램을 종료합니다.\n");
        exit(1);
    }

    // 유속 유효성 검사
    if (V < 0) {
        printf("invalid input: 유속은 0m/s 이상이어야 합니다. 프로그램을 종료합니다.\n");
        exit(1);
    }

    // 레이놀즈 수 계산
    double Re = (rho * V * D) / mu;

    // 동압 계산
    double q = 0.5 * rho * pow(V, 2);

    const char* flow_status;

    // 유동 상태 판단
    if (Re < 2100) {
        flow_status = "층류 (Laminar Flow)";
    }
    else if (Re <= 4000) { // Re >= 2100 자동 포함
        flow_status = "천이 (Transitional Flow)";
    }
    else {
        flow_status = "난류 (Turbulent Flow)";
    }

    // 결과 출력
    printf("배관 내 유체의 유동 상태: %s\n", flow_status);
    printf("배관 내 유체의 동압 q: %.4f Pa\n", q);

    return 0;
}