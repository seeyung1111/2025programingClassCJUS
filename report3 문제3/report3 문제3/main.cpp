#include <stdio.h> // 표준 입출력 함수 사용을 위한 헤더파일

// add_numbers 함수 정의
// 이 함수는 'int' 타입의 두 정수(num1, num2)를 입력받아서
// 두 수의 합을 계산하고, 그 합을 'int' 타입으로 반환합니다.
int add_numbers(int num1, int num2) {
    int sum; // 합을 저장할 변수 선언
    sum = num1 + num2; // 두 숫자를 더해서 sum에 저장
    return sum; // 계산된 합 반환
}

// main 함수: 프로그램의 시작점
int main() {
    int a = 10; // 첫 번째 숫자 변수 선언 및 초기화
    int b = 20; // 두 번째 숫자 변수 선언 및 초기화
    int result; // 함수의 반환값을 저장할 변수 선언

    // add_numbers 함수를 호출하고, 반환값을 result 변수에 저장
    // 함수를 호출함으로써 두 숫자를 더하는 로직을 재사용할 수 있습니다.
    result = add_numbers(a, b);

    // 계산된 결과 출력
    printf("두 수의 합: %d + %d = %d\n", a, b, result);

    // 다른 숫자로 함수를 다시 호출하여 재사용 예시
    int c = 100;
    int d = 200;
    result = add_numbers(c, d); // 함수 재사용
    printf("두 수의 합: %d + %d = %d\n", c, d, result);

    return 0; // 프로그램 정상 종료
}