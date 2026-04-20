#include <stdio.h>
#include <stdlib.h>


typedef int element;


typedef struct {
    element *array;
    int size;
    int capacity;
} ArrayList;


void init(ArrayList *list, int capacity) {
    list->array = (element *)malloc(capacity * sizeof(element));
    list->size = 0;
    list->capacity = capacity;
}


void error(const char *message) {
    printf("[오류] %s\n", message);
}


void insert(ArrayList *list, int pos, element item) {
    if (pos < 0 || pos > list->size) {
        error("잘못된 위치입니다.");
        return;
    }
    if (item <= 0) {
        error("양의 정수만 입력 가능합니다.");
        return;
    }
    
  
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (element *)realloc(list->array, list->capacity * sizeof(element));
    }
    
  
    for (int i = list->size - 1; i >= pos; i--) {
        list->array[i + 1] = list->array[i];
    }
    list->array[pos] = item;
    list->size++;
    printf("-> 추가 완료!\n");
}


void delete(ArrayList *list, int pos) {
    if (pos < 0 || pos >= list->size) {
        error("잘못된 위치입니다.");
        return;
    }
  
    for (int i = pos; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    printf("-> 삭제 완료!\n");
}


void replace(ArrayList *list, int pos, element item) {
    if (pos < 0 || pos >= list->size) {
        error("잘못된 위치입니다.");
        return;
    }
    if (item <= 0) {
        error("양의 정수만 입력 가능합니다.");
        return;
    }
    list->array[pos] = item;
    printf("-> 변경 완료!\n");
}


void print_list(ArrayList *list) {
    printf("\n--- 현재 리스트 (크기: %d) ---\n", list->size);
    for (int i = 0; i < list->size; i++) {
        printf("인덱스[%d] : %d\n", i, list->array[i]);
    }
    printf("------------------------------\n");
}


void clear(ArrayList *list) {
    list->size = 0;
    printf("-> 리스트의 모든 값이 삭제되었습니다.\n");
}

int main() {
    ArrayList list;
    init(&list, 2);
    int choice, pos, val;

    while (1) {
        printf("\n[메뉴] 1.추가 2.삭제 3.변경 4.출력 5.초기화 0.종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("추가할 위치와 양의 정수 값 입력 (예: 0 10): ");
                scanf("%d %d", &pos, &val);
                insert(&list, pos, val);
                break;
            case 2:
                printf("삭제할 위치 입력: ");
                scanf("%d", &pos);
                delete(&list, pos);
                break;
            case 3:
                printf("변경할 위치와 양의 정수 값 입력: ");
                scanf("%d %d", &pos, &val);
                replace(&list, pos, val);
                break;
            case 4:
                print_list(&list);
                break;
            case 5:
                clear(&list);
                break;
            default:
                printf("잘못된 선택입니다.\n");
        }
    }
    free(list.array);
    return 0;
}
