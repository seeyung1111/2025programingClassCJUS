#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
    // ���� ���� �� �ʱ�ȭ (�� ����)
    char name[] = "�̽ÿ�";
    int studentID = 2024010684;
    float height_cm = 161.0f;
    float weight = 74.0f;
    float bmi;

    // BMI ���
    float height_m = height_cm / 100.0f;
    bmi = weight / (height_m * height_m);

    // ��� ���
    printf("[�Է� ����]\n");
    printf("�̸�: %s\n", name);
    printf("�й�: %d\n", studentID);
    printf("Ű: %.2f cm\n", height_cm);
    printf("������: %.2f kg\n", weight);
    printf("BMI: %.2f\n", bmi);

    // BMI ����
    if (bmi < 18.5)
        printf("����: ��ü���Դϴ�.\n");
    else if (bmi < 25.0)
        printf("����: ���� ü���Դϴ�.\n");
    else if (bmi < 30.0)
        printf("����: ��ü���Դϴ�.\n");
    else
        printf("����: ���Դϴ�.\n");

    return 0;
}