#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 학생 구조체 정의
typedef struct {
    char name[50];
    int id;
    int score;
} Student;

int main() {
    int n;
    FILE* fp;
    char names[100][50]; 
    int name_count = 0;

    // 난수 시드 설정
    srand((unsigned int)time(NULL));

   
    fp = fopen("name_list.txt", "r"); 
    
    if (fp == NULL) {
        printf("Fail to open name_list.txt\n");
        printf("이름 파일을 찾을 수 없어 임시 이름으로 대체합니다.\n");
        strcpy(names[0], "김철수");
        strcpy(names[1], "이영희");
        strcpy(names[2], "박민수");
        name_count = 3;
    } else {
        char file_buff[50];
        while (fgets(file_buff, sizeof(file_buff), fp) != NULL) {
            
            file_buff[strcspn(file_buff, "\n")] = '\0'; 
            
            if (strlen(file_buff) > 0) { 
                strcpy(names[name_count], file_buff);
                name_count++;
            }
            memset(file_buff, 0, sizeof(file_buff));
        }
        fclose(fp);
    }

    printf("학생 수 N을 입력하세요: ");
    scanf("%d", &n);


  
   
  
    printf("\n--- 1) 배열 연산자 사용 결과 ---\n");
    Student* arr1 = (Student*)malloc(n * sizeof(Student));
    
    int total1 = 0;
    int max_idx1 = 0;
    int min_idx1 = 0;

    for (int i = 0; i < n; i++) {
       
        arr1[i].id = i + 1;
        arr1[i].score = rand() % 100 + 1; 
        strcpy(arr1[i].name, names[rand() % name_count]); 
        
        total1 += arr1[i].score;
        
        
        if (arr1[i].score > arr1[max_idx1].score) max_idx1 = i;
        if (arr1[i].score < arr1[min_idx1].score) min_idx1 = i;
    }

   
    for (int i = 0; i < n; i++) {
        printf("학번: %d | 이름: %s | 점수: %d\n", arr1[i].id, arr1[i].name, arr1[i].score);
    }
    
    printf("\n[1번 과제 통계]\n");
    printf("최고점: %s (학번: %d, %d점)\n", arr1[max_idx1].name, arr1[max_idx1].id, arr1[max_idx1].score);
    printf("최저점: %s (학번: %d, %d점)\n", arr1[min_idx1].name, arr1[min_idx1].id, arr1[min_idx1].score);
    printf("평균점: %.2f점\n", (double)total1 / n);

    free(arr1); 


   
    // 2) 포인터 연산자 (*(arr + idx)) 사용 방식
    
    printf("\n----------------------------------\n");
    printf("\n--- 2) 포인터 연산자 사용 결과 ---\n");
    Student* arr2 = (Student*)malloc(n * sizeof(Student));
    
    int total2 = 0;
    int max_idx2 = 0;
    int min_idx2 = 0;

    for (int i = 0; i < n; i++) {
       
        (*(arr2 + i)).id = i + 1;
        (*(arr2 + i)).score = rand() % 100 + 1;
        strcpy((*(arr2 + i)).name, names[rand() % name_count]);
        
        total2 += (*(arr2 + i)).score;
        
        if ((*(arr2 + i)).score > (*(arr2 + max_idx2)).score) max_idx2 = i;
        if ((*(arr2 + i)).score < (*(arr2 + min_idx2)).score) min_idx2 = i;
    }

   
    for (int i = 0; i < n; i++) {
        printf("학번: %d | 이름: %s | 점수: %d\n", (*(arr2 + i)).id, (*(arr2 + i)).name, (*(arr2 + i)).score);
    }
    
    printf("\n[2번 과제 통계]\n");
    printf("최고점: %s (학번: %d, %d점)\n", (*(arr2 + max_idx2)).name, (*(arr2 + max_idx2)).id, (*(arr2 + max_idx2)).score);
    printf("최저점: %s (학번: %d, %d점)\n", (*(arr2 + min_idx2)).name, (*(arr2 + min_idx2)).id, (*(arr2 + min_idx2)).score);
    printf("평균점: %.2f점\n", (double)total2 / n);

    free(arr2); 

    return 0;
}
