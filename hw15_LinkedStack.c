#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedStack.h"

// 1. 스택 생성 (create)
LinkedStack* createStack() {
    LinkedStack* s = (LinkedStack*)malloc(sizeof(LinkedStack));
    s->top = NULL;
    return s;
}

// 2. 스택 메모리 해제 (destroy)
void destroyStack(LinkedStack* s) {
    StackNode* curr = s->top;
    StackNode* nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    free(s);
}

// 3. 스택 비어있는지 확인 (empty)
int isEmpty(LinkedStack* s) {
    return (s->top == NULL);
}

// 4. 스택 꽉 찼는지 확인 (full)
// 연결 스택은 동적 할당을 사용하므로 메모리가 부족하지 않는 한 가득 차지 않음
int isFull(LinkedStack* s) {
    return 0; // 항상 0(거짓) 반환
}

// 5. 삽입 (push)
void push(LinkedStack* s, const char* url) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    strcpy(newNode->url, url);
    
    // 새 노드를 맨 위에 올리고 top 갱신
    newNode->next = s->top;
    s->top = newNode;
}

// 6. 삭제 및 데이터 반환 (pop)
int pop(LinkedStack* s, char* popped_url) {
    if (isEmpty(s)) {
        return 0; // 실패
    }
    
    StackNode* temp = s->top;
    strcpy(popped_url, temp->url); // 지워질 URL을 백업
    
    s->top = temp->next; // top을 아래로 내림
    free(temp); // 기존 top 메모리 해제
    
    return 1; // 성공
}

// 7. 맨 위 데이터 확인 (peek)
char* peek(LinkedStack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->top->url;
}

// 8. 스택 전체 출력 (print)
void printStack(LinkedStack* s) {
    StackNode* curr = s->top;
    printf("스택 내 전체 URL 목록 (위->아래):\n");
    while (curr != NULL) {
        printf("- %s\n", curr->url);
        curr = curr->next;
    }
}
