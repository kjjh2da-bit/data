#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *array;     
    int size;      
    int capacity;  
} ArrayList;


void init(ArrayList *list, int init_capacity) {
    // int 포인터에 맞게 sizeof로 정확히 할당
    list->array = (int *)malloc(init_capacity * sizeof(int));
    if (list->array == NULL) {
        printf("메모리 할당 에러\n");
        return;
    }
    list->size = 0;
    list->capacity = init_capacity;
    printf("[알림] 초기 용량 %d인 리스트가 생성되었습니다.\n", init_capacity);
}

// 데이터 마지막에 추가
void add_last(ArrayList *list, int data) {
  
    if (list->size == list->capacity) {
        int new_capacity = list->capacity * 2;
        printf("\n--- [포화 상태] 용량을 %d에서 %d(으)로 2배 확장합니다! ---\n", list->capacity, new_capacity);
        
        
       
     
        int *temp = (int *)realloc(list->array, new_capacity * sizeof(int));
        
        if (temp == NULL) {
            printf("메모리 재할당 실패!\n");
            return;
        }
        
   
        list->array = temp;
        list->capacity = new_capacity;
    }

 
    list->array[list->size] = data;
    list->size++;
    printf("%d 추가 완료 (현재 상태: %d / %d)\n", data, list->size, list->capacity);
}


void print_list(ArrayList *list) {
    printf("현재 리스트 내용: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

int main() {
    ArrayList my_list;
    int input_num;


    init(&my_list, 2);

    printf("\n숫자를 차례대로 입력하세요 (0을 입력하면 종료):\n");
    while (1) {
        printf("입력: ");
        scanf("%d", &input_num);
        
        if (input_num == 0) break;
        
        add_last(&my_list, input_num);
        print_list(&my_list);
    }

   
    free(my_list.array);
    printf("\n프로그램을 종료하고 메모리를 반환합니다.\n");

    return 0;
}
