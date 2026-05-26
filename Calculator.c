#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100


typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;


void init(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int item) { s->data[++(s->top)] = item; }
int pop(Stack *s) { if(isEmpty(s)) return -1; return s->data[(s->top)--]; }
int peek(Stack *s) { if(isEmpty(s)) return -1; return s->data[s->top]; }


void printStackChar(Stack *s) {
    for (int i = 0; i <= s->top; i++) printf("%c ", s->data[i]);
}
void printStackInt(Stack *s) {
    for (int i = 0; i <= s->top; i++) printf("%d ", s->data[i]);
}


int precedence(char op) {
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}


void infixToPostfix(char* exp, char* postfix) {
    Stack s;
    init(&s);
    int p = 0; 
    
    printf("Transform:\n");
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == ' ') continue; 

        if (isdigit(ch)) {
            
            postfix[p++] = ch;
            postfix[p++] = ' ';
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
           
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[p++] = pop(&s);
                postfix[p++] = ' ';
            }
            pop(&s); 
        } else {
         
            while (!isEmpty(&s) && precedence(ch) <= precedence(peek(&s))) {
                postfix[p++] = pop(&s);
                postfix[p++] = ' ';
            }
            push(&s, ch);
        }
        
        
        postfix[p] = '\0';
        printf("- Postfix: %s| Stack: ", postfix);
        printStackChar(&s);
        printf("\n");
    }

  
    while (!isEmpty(&s)) {
        postfix[p++] = pop(&s);
        postfix[p++] = ' ';
        
        postfix[p] = '\0';
        printf("- Postfix: %s| Stack: ", postfix);
        printStackChar(&s);
        printf("\n");
    }
    
    postfix[p-1] = '\0';
    printf("\n- Result: %s\n\n", postfix);
}


int evalPostfix(char* postfix) {
    Stack s;
    init(&s);
    printf("Eval:\n");
    printf("- Postfix: %s\n", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (ch == ' ') continue; 

        if (isdigit(ch)) {
            
            push(&s, ch - '0'); 
        } else {
            
            int op2 = pop(&s); 
            int op1 = pop(&s);
            int res = 0;
            switch (ch) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
            }
            push(&s, res); 
        }
        
       
        printf("- Current: %c | Stack: ", ch);
        printStackInt(&s);
        printf("\n");
    }
    
    int finalResult = pop(&s);
    printf("\n- Result: %d\n", finalResult);
    return finalResult;
}

int main() {
    char infixExp[] = "3 + 4 * (5 + 6) * 7";
    char postfixExp[MAX_SIZE] = {0};

    
    infixToPostfix(infixExp, postfixExp);

    
    evalPostfix(postfixExp);

    return 0;
}
