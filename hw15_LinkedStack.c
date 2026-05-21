#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedStack.h"


LinkedStack* createStack() {
    LinkedStack* s = (LinkedStack*)malloc(sizeof(LinkedStack));
    s->top = NULL;
    return s;
}


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


int isEmpty(LinkedStack* s) {
    return (s->top == NULL);
}



int isFull(LinkedStack* s) {
    return 0; 
}


void push(LinkedStack* s, const char* url) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    strcpy(newNode->url, url);
    
   
    newNode->next = s->top;
    s->top = newNode;
}


int pop(LinkedStack* s, char* popped_url) {
    if (isEmpty(s)) {
        return 0; 
    }
    
    StackNode* temp = s->top;
    strcpy(popped_url, temp->url); 
    
    s->top = temp->next; 
    free(temp); 
    
    return 1; 
}


char* peek(LinkedStack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->top->url;
}


void printStack(LinkedStack* s) {
    StackNode* curr = s->top;
    printf("스택 내 전체 URL 목록 (위->아래):\n");
    while (curr != NULL) {
        printf("- %s\n", curr->url);
        curr = curr->next;
    }
}
