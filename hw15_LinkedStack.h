#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

// 스택 노드 구조체 (URL 문자열 저장)
typedef struct StackNode {
    char url[256];
    struct StackNode* next;
} StackNode;

// 링크드 스택 구조체
typedef struct {
    StackNode* top;
} LinkedStack;

// ADT 연산 함수 원형
LinkedStack* createStack();
void destroyStack(LinkedStack* s);
void push(LinkedStack* s, const char* url);
int pop(LinkedStack* s, char* popped_url);
int isEmpty(LinkedStack* s);
int isFull(LinkedStack* s);
char* peek(LinkedStack* s);
void printStack(LinkedStack* s);

#endif
