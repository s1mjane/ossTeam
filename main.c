#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int addInfo(Patient *p){
    char ch;
    struct tm *t;
    time_t now = time(NULL);
    t = localtime(&now);

    printf("환자 이름은? ");
    scanf("%s", p->name);
    printf("성별은?(M or F) ");
    scanf("%s", p->sex);
    //printf("나이는? ");
    //scanf("%d", &s->age);
    printf("생년월일은(8자리)? ");
    scanf("%d", &p->birthday);
    printf("핸드폰 번호는? ");
    scanf("%s", p->phone);
    printf("주소는? ");
    scanf("%s", p->address);
    printf("진료과는? ");
    scanf("%s", p->department);
    printf("증상은? ");
    scanf("%s", p->symptom);
    ch = getchar();

    p->age = t->tm_year+1900-(p->birthday/10000)+1;

    printf("=> 추가됨!\n");

    return 1;
}


void readInfo(Patient p){
    printf("%s\t%s\t%d\t%d\t%s\t%s\t%s\t%s\n", p.name, p.sex, p.age, p.birthday, p.phone, p.address, p.department, p.symptom);
}

void listInfo(Patient *p[], int count){
    printf("\n%s %s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ", "PhoneNumber  ", "Address", "Department", "Symptom");
    printf("==============================================================================================\n");

    for(int i=0; i<count; i++) {
        if(p[i] == NULL) {
            continue;
        }
        printf("%2d ", i+1);
        readInfo(*p[i]);
    }
}

int selectMenu(){
    int menu;
    printf("\n*** 병원 환자 관리 시스템 ***\n");
    printf("1. 환자 조회\n");
    printf("2. 환자 추가\n");
    printf("3. 환자 정보 수정\n");
    printf("4. 환자 정보 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 환자 이름 검색\n");
    printf("7. 진단서 조회\n");
    printf("8. 진단서 수정\n");
    printf("9. 약 처방\n");
    printf("10. 수술 예약\n");
    printf("11. 환자 결제 정보 조회\n");
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
                listInfo(p, index);
            else   
                printf("데이터가 없습니다.\n");
        } else if (menu == 2){
            p[index] = (Patient *)malloc(sizeof(Patient));
            count += addInfo(p[index++]);
        }
    }

    printf("\n");
    printf("종료됨!\n");
    return 0;
}
