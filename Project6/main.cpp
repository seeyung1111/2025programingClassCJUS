#include <stdio.h>

#define PI_VALUE 3.141592

int main(void)
{
    const int year = 2025;

    const char* title = "C\nprint\n demo";

    int width_demo_num = 123;

    char sample_char = 'A';

    printf("=== Constant & Formats ===\n");

    printf("Course: C Programming (v1, %u)\n", year);

    printf("Title : %s\n", title);

    printf("PI default \t : %f\n", PI_VALUE);
    printf("PI 2 digits \t : %.2f\n", PI_VALUE);

    printf("width demo \t : [%d]\n", width_demo_num);

    printf("char sample \t: %c\n", sample_char);
    printf("Backslash\t : \\\n");
    return 0;
}
	