#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
    LinkedList* list = createLinkedList();
    int choice, pos, val;
    PointType item;

    while (1) {
        printf("\n========== [연결 리스트 메뉴] ==========\n");
        printf("1. 맨 앞에 추가\n");
        printf("2. 맨 뒤에 추가\n");
        printf("3. 특정 위치에 추가\n");
        printf("4. 특정 위치 삭제\n");
        printf("5. 전체 목록 출력\n");
        printf("6. 리스트 크기 확인\n");
        printf("0. 종료\n");
        printf("========================================\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

       
        if (choice == 0) {
            destroyLinkedList(list);
            printf("-> 모든 메모리를 해제하고 프로그램을 종료합니다.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("맨 앞에 추가할 정수 입력: ");
                scanf("%d", &val);
                
                item.x = val; item.y = 0; item.next = NULL;
                insertFirstLinkedList(list, item);
                printf("-> 맨 앞에 %d 추가 완료\n", val);
                break;

            case 2:
                printf("맨 뒤에 추가할 정수 입력: ");
                scanf("%d", &val);
                item.x = val; item.y = 0; item.next = NULL;
                insertLastLinkedList(list, item);
                printf("-> 맨 뒤에 %d 추가 완료\n", val);
                break;

            case 3:
                printf("추가할 위치(인덱스)와 정수 입력 (예: 1 50): ");
                scanf("%d %d", &pos, &val);
                
                if (pos < 0 || pos > list->size) {
                    printf("-> [오류] 잘못된 위치입니다.\n");
                } 
                else if (pos == 0) { // 맨 앞인 경우
                    item.x = val; item.y = 0; item.next = NULL;
                    insertFirstLinkedList(list, item);
                    printf("-> [%d] 위치에 %d 추가 완료\n", pos, val);
                } 
                else {
                   
                    PointType* pre = list->head;
                    for (int i = 0; i < pos - 1; i++) {
                        pre = pre->next;
                    }
                    item.x = val; item.y = 0; item.next = NULL;
                    insertItemLinkedList(list, pre, item);
                    printf("-> [%d] 위치에 %d 추가 완료\n", pos, val);
                }
                break;

            case 4:
                printf("삭제할 위치(인덱스) 입력: ");
                scanf("%d", &pos);
                
                if (pos < 0 || pos >= list->size) {
                    printf("-> [오류] 잘못된 위치입니다.\n");
                } 
                else {
                
                    PointType* target = list->head;
                    for (int i = 0; i < pos; i++) {
                        target = target->next;
                    }
                    int deleted_val = target->x;
                    
                  
                    deleteAtLinkedList(list, pos);
                    printf("-> [%d] 위치의 노드 삭제 완료 (삭제된 값: %d)\n", pos, deleted_val);
                }
                break;

            case 5:
                printLinkedList(list);
                break;

            case 6:
                printf("-> 현재 리스트의 크기: %d개\n", sizeLinkedList(list));
                break;

            default:
                printf("-> [오류] 잘못된 메뉴 번호입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}
