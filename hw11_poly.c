#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int coef; 
    int exp;  
} Term;


typedef struct {
    Term *array;
    int size;
    int capacity;
} PolyList;


void init_poly(PolyList *p, int cap) {
    p->array = (Term *)malloc(cap * sizeof(Term));
    p->size = 0;
    p->capacity = cap;
}


void insert_term(PolyList *p, int coef, int exp) {
    if (coef == 0) return; 

    
    for (int i = 0; i < p->size; i++) {
        if (p->array[i].exp == exp) {
            p->array[i].coef += coef;
            return;
        }
    }

 
    if (p->size == p->capacity) {
        p->capacity = (p->capacity == 0) ? 2 : p->capacity * 2;
        p->array = (Term *)realloc(p->array, p->capacity * sizeof(Term));
    }

  
    int i = p->size - 1;
    while (i >= 0 && p->array[i].exp < exp) {
        p->array[i + 1] = p->array[i];
        i--;
    }
    p->array[i + 1].coef = coef;
    p->array[i + 1].exp = exp;
    p->size++;
}


void parse_polynomial(const char *str, PolyList *p) {
    char buffer[256];
    strcpy(buffer, str); 
    
   
    char *token = strtok(buffer, "+");
    while (token != NULL) {
        int c = 0, e = 0;
      
        if (sscanf(token, "%dX^%d", &c, &e) == 2) {
            insert_term(p, c, e);
        }
        token = strtok(NULL, "+"); 
    }
}


PolyList add_poly(PolyList *A, PolyList *B) {
    PolyList C;
    init_poly(&C, A->size + B->size);
    
    
    for (int i = 0; i < A->size; i++) insert_term(&C, A->array[i].coef, A->array[i].exp);
    for (int i = 0; i < B->size; i++) insert_term(&C, B->array[i].coef, B->array[i].exp);
    
    return C;
}


PolyList mult_poly(PolyList *A, PolyList *B) {
    PolyList C;
    init_poly(&C, A->size * B->size);
    
    
    for (int i = 0; i < A->size; i++) {
        for (int j = 0; j < B->size; j++) {
            int new_coef = A->array[i].coef * B->array[j].coef; 
            int new_exp = A->array[i].exp + B->array[j].exp;    
            insert_term(&C, new_coef, new_exp);
        }
    }
    return C;
}


void print_poly(PolyList *p) {
    if (p->size == 0) {
        printf("0\n");
        return;
    }
    for (int i = 0; i < p->size; i++) {
        printf("%dX^%d", p->array[i].coef, p->array[i].exp);
        if (i < p->size - 1) printf(" + ");
    }
    printf("\n");
}

int main() {
    PolyList A, B, AddResult, MultResult;
    init_poly(&A, 5);
    init_poly(&B, 5);

    char strA[256], strB[256];

    printf("첫 번째 다항식 입력 (예: 3X^2+2X^1+1X^0): ");
    scanf("%s", strA);
    printf("두 번째 다항식 입력: ");
    scanf("%s", strB);

    parse_polynomial(strA, &A);
    parse_polynomial(strB, &B);

    printf("\n[입력된 다항식]\n");
    printf("A: "); print_poly(&A);
    printf("B: "); print_poly(&B);

   
    AddResult = add_poly(&A, &B);
    printf("\n[덧셈 결과 (A + B)]\n=> ");
    print_poly(&AddResult);

 
    MultResult = mult_poly(&A, &B);
    printf("\n[곱셈 결과 (A * B)]\n=> ");
    print_poly(&MultResult);

    free(A.array); free(B.array);
    free(AddResult.array); free(MultResult.array);

    return 0;
}
