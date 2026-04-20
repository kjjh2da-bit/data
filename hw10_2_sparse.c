#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int row;
    int col;
    int value;
} element;


typedef struct {
    element *array;
    int size;
    int capacity;
} ArrayList;


typedef struct {
    int rows;
    int cols;
    ArrayList *list; 
} SparseMatrix;


void init_list(ArrayList *list, int capacity) {
    list->array = (element *)malloc(capacity * sizeof(element));
    list->size = 0;
    list->capacity = capacity;
}

void add_last(ArrayList *list, element item) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (element *)realloc(list->array, list->capacity * sizeof(element));
    }
    list->array[list->size++] = item;
}


SparseMatrix* transpose(SparseMatrix *m, int *move_count) {
   
    SparseMatrix *tm = (SparseMatrix *)malloc(sizeof(SparseMatrix));
    tm->rows = m->cols;
    tm->cols = m->rows;
    
   
    tm->list = (ArrayList *)malloc(sizeof(ArrayList));
    init_list(tm->list, m->list->capacity);

    *move_count = 0;

   
    if (m->list->size > 0) {
        for (int c = 0; c < m->cols; c++) {
            for (int i = 0; i < m->list->size; i++) {
                if (m->list->array[i].col == c) {
                    element new_elem;
                    new_elem.row = m->list->array[i].col;
                    new_elem.col = m->list->array[i].row;
                    new_elem.value = m->list->array[i].value;
                    
                    add_last(tm->list, new_elem);
                    (*move_count)++; 
                }
            }
        }
    }
    return tm;
}


void print_sparse(SparseMatrix *m) {
    printf("크기: %dx%d, 저장된 데이터 개수: %d\n", m->rows, m->cols, m->list->size);
    for (int i = 0; i < m->list->size; i++) {
        printf("  [%d행 %d열] : %d \n", m->list->array[i].row, m->list->array[i].col, m->list->array[i].value);
    }
}

int main() {
    srand((unsigned int)time(NULL));

   
    SparseMatrix *m = (SparseMatrix *)malloc(sizeof(SparseMatrix));
    m->rows = 10;
    m->cols = 10;
    m->list = (ArrayList *)malloc(sizeof(ArrayList));
    init_list(m->list, 5);

    printf("--- 10x10 희소행렬 무작위 초기화 (데이터 20개) ---\n");
    int count = 0;
    int temp_matrix[10][10] = {0};

    
    while (count < 20) {
        int r = rand() % 10;
        int c = rand() % 10;
        if (temp_matrix[r][c] == 0) {
            temp_matrix[r][c] = rand() % 99 + 1; 
            count++;
        }
    }

    
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            if (temp_matrix[r][c] != 0) {
                element e = {r, c, temp_matrix[r][c]};
                add_last(m->list, e);
            }
        }
    }

    print_sparse(m);

    int move_count = 0;
    SparseMatrix *tm = transpose(m, &move_count);

    printf("\n--- 전치 행렬 결과 ---\n");
    print_sparse(tm);
    printf("\n=> 데이터 이동 횟수: %d회\n", move_count);

   
    free(m->list->array);
    free(m->list);
    free(m);
    free(tm->list->array);
    free(tm->list);
    free(tm);

    return 0;
}
