#include <stdio.h>

int main()
{
    float input;
    int fixed;
    int i;

    printf("Input value: ");
    scanf("%f", &input);

    /*
    Q8.8 fixed point는
    정수 8비트 + 소수 8비트로 이루어진다.

    소수 8비트를 표현하려면
    입력값에 256(2^8)을 곱하면 된다.
    */

    fixed = (int)(input * 256);

    /*
    이제 fixed 값을
    16비트 이진수로 출력한다.
    */

    for (i = 15; i >= 0; i--)
    {
        if (fixed & (1 << i))
            printf("1");
        else
            printf("0");

        /* 정수부와 소수부 구분 */
        if (i == 8)
            printf(".");
    }

    printf("\n");

    return 0;
}
