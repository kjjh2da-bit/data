#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "LinkedStack.h"

int main() {
    LinkedStack* browserStack = createStack();
    int choice;
    char input_url[256];
    char popped_url[256];

    while (1) {
        printf("입력 ");
        scanf("%d", &choice);

        if (choice == 1) { 
            printf("출력 URL 입력:\n");
            printf("입력 ");
            scanf("%s", input_url);
            
            push(browserStack, input_url);
            printf("출력 현재 창: %s\n", peek(browserStack));
        } 
        else if (choice == 2) {
            if (pop(browserStack, popped_url)) {
                printf("출력 이탈: %s\n", popped_url);
                
                if (isEmpty(browserStack)) {
                    printf("       브라우저가 종료되었습니다.\n");
                    destroyStack(browserStack); 
                    break;
                } else {
                    printf("       현재 창: %s\n", peek(browserStack));
                }
            }
        } 
        else if (choice == 3) { 
            if (!isEmpty(browserStack)) {
                printf("출력 현재 창: %s\n", peek(browserStack));
            }
        }
        else if (choice == 4) { 
            printStack(browserStack);
        }
    }

    return 0;
}
