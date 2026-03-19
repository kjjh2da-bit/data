#pragma execution_character_set("utf-8") // 비주얼 스튜디오 한글 깨짐 방지 1단계
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_math.h"
#include "my_fraction.h"

int main(int c, char** v) {
    system("chcp 65001 > nul"); // 까만 창 한글 깨짐 방지 2단계

    // c: 입력된 단어 개수, v: 단어들이 들어있는 상자
    if (c < 3) {
        printf("[사용법] 실행할 때 가로 세로 숫자를 같이 적어주세요!\n");
        printf("예시: program.exe 3/7 4/9\n");
        return 1;
    }

    // v[1]은 가로, v[2]는 세로
    Fraction width = parse_fraction(v[1]);
    Fraction height = parse_fraction(v[2]);

    // [둘레 구하기] (가로 + 세로) * 2
    Fraction sum = add_fraction(width, height);
    Fraction two = {2, 1}; // 숫자 2를 분수 2/1로 만들기
    Fraction perimeter = mul_fraction(sum, two);

    // [넓이 구하기] 가로 * 세로
    Fraction area = mul_fraction(width, height);

    // 결과 출력
    printf("Perimeter: ");
    print_fraction(perimeter);
    printf(", Area: ");
    print_fraction(area);
    printf("\n");

    return 0;
}
