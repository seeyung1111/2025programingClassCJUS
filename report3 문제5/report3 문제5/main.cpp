#include <stdio.h>   // 표준 입출력 함수 (printf, scanf_s)
#include <stdlib.h>  // 난수 생성 함수 (rand, srand)
#include <time.h>    // 난수 시드 설정을 위한 time 함수

#define MAX_ATTEMPTS 10 // 최대 시도 횟수
#define MIN_NUM 1       // 맞출 숫자의 최소 범위
#define MAX_NUM 100     // 맞출 숫자의 최대 범위

// 1. 특정 범위 내에서 목표 숫자를 생성하여 반환하는 함수
// num_min (최소값) 과 num_max (최대값) 사이의 난수를 생성합니다.
int generate_target_number(int num_min, int num_max) {
    // 난수 시드 설정 (main에서 한 번만 호출하면 됨, 함수 내에서 호출하면 매번 같은 시드가 될 수 있음)
    // srand((unsigned int)time(NULL)); // 이 부분은 main에서 한번만!
    return (rand() % (num_max - num_min + 1)) + num_min;
}

// 2. 사용자에게 숫자를 입력받는 함수
// 사용자가 입력한 숫자를 반환합니다.
int get_user_guess() {
    int guess; // 사용자의 추측을 저장할 변수
    printf("숫자를 입력하세요 (%d ~ %d): ", MIN_NUM, MAX_NUM);
    // scanf_s는 버퍼 오버플로우 방지를 위한 보안 강화 함수입니다.
    // 만약 컴파일 오류가 난다면 scanf("%d", &guess); 로 변경해 보세요.
    while (scanf_s("%d", &guess) != 1) { // 입력이 정수가 아니거나 잘못된 경우
        printf("잘못된 입력입니다. 숫자를 다시 입력해주세요: ");
        while (getchar() != '\n'); // 입력 버퍼를 비웁니다.
    }
    return guess; // 입력받은 숫자 반환
}

// 3. 사용자의 추측을 확인하고 결과를 출력하는 함수
// target (컴퓨터가 생성한 숫자), guess (사용자가 추측한 숫자)를 입력받습니다.
// 정답을 맞추면 1을, 아니면 0을 반환합니다.
int check_guess(int target, int guess) {
    if (guess > target) { // 추측한 숫자가 목표보다 크면
        printf("DOWN!\n");
        return 0; // 정답 아님
    }
    else if (guess < target) { // 추측한 숫자가 목표보다 작으면
        printf("UP!\n");
        return 0; // 정답 아님
    }
    else { // 추측한 숫자가 목표와 같으면 (정답!)
        printf("정답입니다! 축하해요!\n");
        return 1; // 정답 맞춤
    }
}

// main 함수: 프로그램의 시작점 (게임 로직)
int main() {
    // 난수 시드 설정: 프로그램 실행 시마다 다른 난수를 생성하도록 현재 시간을 이용합니다.
    srand((unsigned int)time(NULL));

    // generate_target_number 함수를 호출하여 컴퓨터가 맞출 숫자를 생성합니다.
    int target_number = generate_target_number(MIN_NUM, MAX_NUM);
    int guess;          // 사용자가 입력할 숫자
    int attempts = 0;   // 시도 횟수
    int is_correct = 0; // 정답 여부를 저장 (0: 오답, 1: 정답)

    printf("----------------------------------------\n");
    printf("         Up & Down 게임 시작!           \n");
    printf(" %d ~ %d 사이의 숫자를 %d번 안에 맞춰보세요!\n", MIN_NUM, MAX_NUM, MAX_ATTEMPTS);
    printf("----------------------------------------\n");

    // 최대 시도 횟수만큼 반복하거나 정답을 맞출 때까지 반복합니다.
    for (attempts = 1; attempts <= MAX_ATTEMPTS; attempts++) {
        printf("---------- %d번째 시도 ----------\n", attempts);
        guess = get_user_guess(); // 사용자에게 숫자 입력받기

        // 사용자가 입력한 숫자가 유효 범위 내에 있는지 확인 (선택문 사용)
        if (guess < MIN_NUM || guess > MAX_NUM) {
            printf("경고: 범위(%d ~ %d) 밖의 숫자입니다. 다시 입력해주세요.\n", MIN_NUM, MAX_NUM);
            attempts--; // 시도 횟수 차감하지 않음
            continue;   // 다음 반복으로 넘어감 (continue 사용 예시)
        }

        // check_guess 함수를 호출하여 사용자의 추측을 확인합니다.
        is_correct = check_guess(target_number, guess);

        if (is_correct) { // 정답을 맞췄으면
            break; // for 반복문 즉시 종료 (break 사용 예시)
        }
    }

    // 게임 종료 후 결과 출력 (선택문 사용)
    if (is_correct) {
        printf("----------------------------------------\n");
        printf(" %d번 만에 정답을 맞췄습니다! 대단해요!\n", attempts);
        printf("----------------------------------------\n");
    }
    else {
        printf("----------------------------------------\n");
        printf("  아쉽네요... %d번의 시도를 모두 사용했습니다. ㅠㅠ\n", MAX_ATTEMPTS);
        printf("  정답은 %d 였습니다!\n", target_number);
        printf("----------------------------------------\n");
    }

    return 0; // 프로그램 정상 종료
}