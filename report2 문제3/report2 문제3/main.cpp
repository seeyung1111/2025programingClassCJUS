#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846  // M_PI 정의

int main() {
    const double m = 100.0;
    const double mu_s = 0.5;
    const double mu_k = 0.4;
    const double g = 9.81;
    double theta_deg, theta_rad;

    printf("램프의 경사각(도)을 입력하세요 (0 ~ 90): ");
    if (scanf("%lf", &theta_deg) != 1) {
        printf("invalid input: 경사각 입력이 잘못되었습니다. 프로그램을 종료합니다.\n");
        exit(1);
    }

    if (theta_deg < 0 || theta_deg > 90) {
        printf("invalid input: 경사각은 0도에서 90도 사이여야 합니다.\n");
        exit(1);
    }

    theta_rad = theta_deg * (M_PI / 180.0);

    double Fg_parallel = m * g * sin(theta_rad);
    double Fg_normal = m * g * cos(theta_rad);
    double f_s_max = mu_s * Fg_normal;

    if (Fg_parallel <= f_s_max) {
        printf("파렛트는 정지 상태를 유지합니다 (미끄러지지 않습니다).\n");
    }
    else {
        double f_k = mu_k * Fg_normal;
        double acceleration = (Fg_parallel - f_k) / m;
        printf("파렛트가 경사면 아래로 %.2f m/s²로 가속됩니다.\n", acceleration);
    }

    return 0;
}