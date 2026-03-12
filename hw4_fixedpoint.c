#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 대문자는 소문자
// 소문자는 대문자
// 숫자, 쉼표, 느낌표 같은 건 그대로 


int main()
{
    char str[100];
    int i = 0;

    printf("Input: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') //문자열 끝ㅌㅌ
    {
        //  대문자면 소문자로 변경
        if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            str[i] = str[i] + 32;
        }
        // 소문자면 대문자로 변경
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }

        i++;
    }

    printf("%s", str);

    return 0;
}
