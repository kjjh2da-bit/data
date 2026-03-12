#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    float num;
    unsigned int bits;
    int i;

    printf("Input: ");
    scanf("%f", &num);

    /* 
       float형 실수의 비트 값을 그대로 보기 위해
       num의 주소를 unsigned int 포인터로 바꿔서 저장했음
    */
    bits = *(unsigned int*)&num;

    /* 부호 비트 */
    printf("%u/", (bits >> 31) & 1);

    /* 지수 8비트 */
    for (i = 30; i >= 23; i--)
    {
        printf("%u", (bits >> i) & 1);

        if (i % 4 == 3 && i != 23)
            printf(" ");
    }

    printf("/");

    /* 가수 23비트 */
    for (i = 22; i >= 0; i--)
    {
        printf("%u", (bits >> i) & 1);

        if (i % 4 == 3 && i != 0)
            printf(" ");
    }

    printf("\n");

    return 0;
}
