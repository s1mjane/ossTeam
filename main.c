#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char sex[2];
    int age;
    char phone[20];
    int birthday;
    int monthday;
    char address[100];
    char department[100];
    char symptom[100];
} Patient;

int selectMenu(){
    int menu;
    printf("\n*** 병원 환자 관리 시스템 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("7. 학부검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    Patient *p[100];
    int count = 0, menu;
    int index = 0;

    index = count;

    while (1){
        menu = selectMenu();
        if (menu == 0) {
            break;
        }
        if (menu == 1){
            if(count > 0)
                //listScore(p, index);
                printf("데이터가 있습니다.\n");
            else   
                printf("데이터가 없습니다.\n");
        }
    }

    printf("\n");
    printf("종료됨!\n");
    return 0;
}
