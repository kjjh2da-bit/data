#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i = 1;

    /*
     * [판별 원리]
     *
     * 컴퓨터에서 음수를 표현하는 방법에는
     * 1의 보수와 2의 보수가 있다.
     *
     * 2의 보수 방식에서는 어떤 정수 i의 음수 -i가
     * 비트를 반전한 값(~i)에 1을 더한 값과 같다.
     *
     * 즉,
     *      -i == (~i + 1)
     *
     * 이 식이 성립하면 2의 보수이고,
     * 성립하지 않으면 1의 보수라고 판단할 수 있다.
     */

    if (-i == (~i + 1))
    {
        printf("2's complement\n");
    }
    else
    {
        printf("1's complement\n");
    }

    return 0;
}
