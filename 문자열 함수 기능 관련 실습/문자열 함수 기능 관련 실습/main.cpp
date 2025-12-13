#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// 무슨 일을 하는 함수인지 실행해보고 주석 작성
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ;
    }
}

int main(void)
{
    char str1[100];
    char str2[100];
    char copy[100];
    char sentence[200];
    char temp[200];

    char* pos;
    char ch;

    char* p_str1 = str1;
    char* p_str2 = str2;
    char* p_copy = copy;
    char* p_sentence = sentence;
    char* p_temp = temp;

    printf("Enter first string (no spaces): ");
    scanf("%99s", p_str1);

    printf("Enter second string (no spaces): ");
    scanf("%99s", p_str2);

    printf("\n--- Printed strings (using puts) ---\n");
    puts(p_str1);
    puts(p_str2);

    // -------------------------------------------------------

    // 무슨 일을 하는 부분인지 작성
    printf("\n--- strlen practice ---\n");
    printf("Length of str1: %zu\n", strlen(p_str1));
    printf("Length of str2: %zu\n", strlen(p_str2));
    // -------------------------------------------------------

    // 왜 여기에 이 함수를 넣었는지 작성
    clear_input_buffer();

    printf("\nEnter one sentence (can include spaces): ");
    fgets(p_sentence, sizeof(sentence), stdin);
    printf("\nYou entered (sentence) = ");
    puts(p_sentence);
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #1: strcpy function ---\n");
    strcpy(p_copy, p_str1);
    printf("copy = ");
    puts(p_copy);
    // -------------------------------------------------------

    // -------------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #2: strcat function ---\n");
    if (strlen(p_str1) + strlen(p_str2) < sizeof(str1)) {
        strcat(p_str1, p_str2);
        printf("After concatenation, str1 = ");
        puts(p_str1);
    }
    else {
        printf("str1 buffer is too small; cannot perform strcat!\n");
    }
    // -------------------------------------------------------

    // -------------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #3: strcmp function ---\n");
    {
        int cmp = strcmp(p_str1, p_str2);
        if (cmp == 0) {
            printf("str1 and str2 are equal.\n");
        }
        else if (cmp < 0) {
            printf("In lexicographical order, str1 comes before str2.\n");
        }
        else {
            printf("In lexicographical order, str1 comes after str2.\n");
        }
    }
    // -------------------------------------------------------

    // -------------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #4: strchr function ---\n");
    printf("\nEnter a character to search for: ");
    scanf(" %c", &ch);
    pos = strchr(p_str1, ch);
    if (pos != NULL) {
        printf("'%c' is at index %ld (0-based) in str1.\n", ch, (long)(pos - p_str1));
    }
    else {
        printf("'%c' is not found in str1.\n", ch);
    }
    // -------------------------------------------------------

    // -------------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #5: ????????? ---\n");
    pos = strstr(p_sentence, p_str2);
    if (pos != NULL) {
        printf("Found \"%s\" inside sentence.\n", p_str2);
        printf("Substring starting from the found position: ");
        puts(pos);
    }
    else {
        printf("Could not find \"%s\" in sentence.\n", p_str2);
    }
    // -------------------------------------------------------

    // -------------------------------------------------------
    // 무슨 일을 하는 부분인지 작성
    printf("\n--- Practice #6: strtok function ---\n");
    printf("\n--- strtok practice: split sentence by spaces ---\n");
    // 왜 이 실습에서는 temp 에 문자열을 복사하는가?
    strcpy(p_temp, p_sentence);
    char* token = strtok(p_temp, " ");
    int i = 1;
    while (token != NULL) {
        printf("Token %d: ", i++);
        puts(token);
        token = strtok(NULL, " ");
    }
    // -------------------------------------------------------

    printf("\nProgram finished.\n");
    return 0;
}