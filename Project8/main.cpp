#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
    // 변수 선언 및 초기화 (네 정보)
    char name[] = "이시영";
    int studentID = 2024010684;
    float height_cm = 161.0f;
    float weight = 74.0f;
    float bmi;

    // BMI 계산
    float height_m = height_cm / 100.0f;
    bmi = weight / (height_m * height_m);

    // 결과 출력
    printf("[입력 정보]\n");
    printf("이름: %s\n", name);
    printf("학번: %d\n", studentID);
    printf("키: %.2f cm\n", height_cm);
    printf("몸무게: %.2f kg\n", weight);
    printf("BMI: %.2f\n", bmi);

    // BMI 판정
    if (bmi < 18.5)
        printf("판정: 저체중입니다.\n");
    else if (bmi < 25.0)
        printf("판정: 정상 체중입니다.\n");
    else if (bmi < 30.0)
        printf("판정: 과체중입니다.\n");
    else
        printf("판정: 비만입니다.\n");

    return 0;
}