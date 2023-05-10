#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct { // 환자 정보 구조체
    char name[20];
    char sex[2];
    int age;
    char phone[20]; // 010의 0 출력 위해 string으로 설정
    int birthday; // age 계산 위해 int로 설정
    int monthday;
    char address[100];
    char department[100];
    char symptom[100];
} Patient;

// 환자 정보 추가
int addInfo(Patient *p){
    char ch;
    struct tm *t;
    time_t now = time(NULL);
    t = localtime(&now);

    printf("환자 이름: ");
    scanf("%s", p->name);
    printf("성별(M or F): ");
    scanf("%s", p->sex);
    printf("생년월일은(8자리): ");
    scanf("%d", &p->birthday);
    getchar();
    printf("핸드폰 번호(숫자만): ");
    scanf("%s", p->phone);
    printf("주소: ");
    getchar();
    scanf(" %s", p->address);
    printf("진료과: ");
    scanf("%s", p->department);
    printf("증상: ");
    scanf("%s", p->symptom);
    ch = getchar();

    // 생년월일만 입력 받고 나이는 함수 내에서 따로 계산해 저장만 해 둠. 추후 필요할 때 출력.
    p->age = t->tm_year+1900-(p->birthday/10000)+1;

    printf("=> %s 환자 진료 예약이 추가되었습니다.\n\n", p->name);
    return 1;
}

// 환자 정보 수정/삭제 메뉴 시 번호 선택
int selectNum() {
    int num;
    printf("=> 환자 번호(취소:0) : ");
    scanf("%d", &num);
    return num;
}

// 특정환자 세부정보 조회
int OnereadInfo(Patient p, int infonum) {
    if(p.birthday == -1) {
        return 0;
    }
    printf("\n*** %d번 환자의 세부 정보 ***\n", infonum);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "Name ", "Sex", "Age", "Birthday   ", "PhoneNumber  ", "Address", "Department", "Symptom");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("%s\t%s\t%d\t%d\t%s\t%s\t%s\t%s\n", p.name, p.sex, p.age, p.birthday, p.phone, p.address, p.department, p.symptom);
    return 1;
}

// 세부정보 조회할 특정환자 
void OnelistInfo(Patient *p[], int count) {
    int infonum;
    printf("원하는 환자의 번호를 입력해주세요 : ");
    scanf("%d", &infonum);
    getchar();
    if(OnereadInfo(*p[infonum-1], infonum)==0) {
        printf("해당 환자의 데이터가 없습니다.\n");
    }
    printf("\n");
}

// 환자 정보 조회
void readInfo(Patient p){
    printf("%s\t%s\t%d\t%d\t%s\t%s\t%s\t%s\n", p.name, p.sex, p.age, p.birthday, p.phone, p.address, p.department, p.symptom);
}

// 환자 정보 조회 리스트 (최대 20명)
void listInfo(Patient *p[], int count){
    printf("===================================== 환자 진료 예약 리스트 =====================================\n");
    printf("%s %s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ", "PhoneNumber  ", "Address", "Department", "Symptom");
    printf("==============================================================================================\n");
    for(int i=0; i<count; i++) {
        if(p[i]->birthday == -1) continue;
        printf("%2d ", i+1);
        readInfo(*p[i]);
    } printf("\n");
}

// 환자 정보 수정
int updateInfo(Patient *p){
    char ch;
    struct tm *t;
    time_t now = time(NULL);
    t = localtime(&now);

    printf("환자 이름: ");
    scanf("%s", p->name);
    printf("성별(M or F): ");
    scanf("%s", p->sex);
    getchar();
    printf("생년월일은(8자리): ");
    scanf("%d", &p->birthday);
    printf("핸드폰 번호(숫자만): ");
    scanf("%s", p->phone);
    printf("주소: ");
    getchar();
    scanf("%s", p->address);
    printf("진료과: ");
    scanf("%s", p->department);
    printf("증상: ");
    scanf("%s", p->symptom);
    ch = getchar();

    // 생년월일만 입력 받고 나이는 함수 내에서 따로 계산해 저장만 해 둠. 추후 필요할 때 출력.
    p->age = t->tm_year+1900-(p->birthday/10000)+1;

    printf("=> %s 환자 진료 예약이 수정되었습니다.\n\n", p->name);
    return 1;
}

// 환자 정보 삭제
int deleteInfo(Patient *p) {
    p->birthday = -1;
    return 1;
}

// 1~11번 및 종료 메뉴 선택
int selectMenu(){
    int menu;
    printf("🏥 병원 환자 관리 시스템 🖥️\n");
    printf("1. 환자 조회\t2. 환자 추가\t3. 환자 정보 수정\t4. 환자 정보 삭제\n");
    printf("5. 파일 저장\t6. 환자 검색\t7. 과별 환자 정보\t8. 진단서 추가\n");
    printf("9. 처방전 조회\t10. 처방전 조회\t11. 수술 예약\t\t12. 결제 정보 조회\t0. 종료\n");
    printf("====> 원하는 메뉴: ");
    scanf("%d", &menu);
    printf("\n");
    return menu;
}

// 프로그램 실행시 txt 파일 로드
int loadData(Patient *p[]) {
    int i = 0;
    int count = 0;

    FILE *fp;
    fp = fopen("patient.txt", "rt"); // 읽어오는 용도로 파일 오픈
    
    if (fp == NULL) {
        printf("파일 로드 중\n==> 저장된 파일이 없습니다.\n\n");
        return i;
    } 
    for (; i<20; i++) {
        p[i] = malloc(sizeof(Patient));
        fscanf(fp, "%s", p[i]->name);
        if (feof(fp)) break; // 파일 끝을 만났을 때
        fscanf(fp, "%s", p[i]->sex);
        fscanf(fp, "%d", &p[i]->birthday);
        fscanf(fp, "%s", p[i]->phone);
        fscanf(fp, "%s", p[i]->address);
        fscanf(fp, "%s", p[i]->department);
        fscanf(fp, "%s", p[i]->symptom);
        if(p[i] == NULL) {
            free(p[i]); // 동적할당한 것 해제
            i--;
            continue;
        }
    }
    fclose(fp);
    printf("파일 로드 중\n=> 로딩 성공!\n\n");
    return i;
}

// 파일 저장
void saveData(Patient *p[], int count) {
    FILE *fp;
    fp = fopen("patient.txt","wt"); // 텍스트 쓰는 용도로 파일 오픈
    for (int i = 0; i<count; i++) {
        if (p[i] != NULL) {
            fprintf(fp, "%s %s %d %s %s %s %s\n", p[i]->name, p[i]->sex, p[i]->birthday, p[i]->phone, p[i]->address, p[i]->department, p[i]->symptom);
        }
    } 
    fclose(fp);
    printf("=> 파일 저장되었습니다.\n\n");
}

// 환자 이름 검색
void searchName(Patient *p[], int count) {
    int pcount = 0;
    char search[20];
    printf("=> 검색할 이름 : ");
    scanf("%s", search);
    printf("===================================== 리스트 검색 조회 결과 =====================================\n");
    printf("%s %s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ", "PhoneNumber  ", "Address", "Department", "Symptom");
    printf("==============================================================================================\n");
    for (int i=0; i<count; i++) {
        if (p[i] == NULL) continue;
        if (p[i]!= NULL) {
            if (strstr(p[i]->name, search)) { 
                printf("%2d\t", i+1);
                readInfo(*p[i]);
                pcount++;
            }
        }
    }
    if (pcount == 0) printf("=> 검색된 데이터가 없습니다.\n");
    printf("\n");
}

int main(void){
    int index, count, menu;
    count = 0;
    index = 0;
    char infocheck;
    Patient *plist[20]; // README.md 파일에 20명이라고 해놔서 100명->20명으로 고쳤어요!
    count = loadData(plist);
    index = count;

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        else if (menu == 1){ // 환자 조회
            if (count > 0) {
                listInfo(plist, index);
                getchar();
                while(1) {
                    printf("특정 학생의 정보를 조회하고 싶습니까?(Y/N) : ");
                    scanf("%c", &infocheck);
                    getchar();
                    if(infocheck == 'Y') {
                        OnelistInfo(plist, index);
                        printf("추가로 ");
                    } else {
                        printf("\n");
                        break;
                    }
                }
            }
            else printf("=> 조회할 데이터가 없습니다.(현재 데이터 0개)\n\n");
        } 
        else if (menu == 2){ // 환자 추가
            if (count >= 20) printf("=> 더이상 추가할 수 없습니다.(현재 데이터 20개)\n\n");
            else {
                plist[index] = (Patient *)malloc(sizeof(Patient));
                count += addInfo(plist[index++]);
            }
        }
        else if (menu == 3) { // 환자 정보 수정 
            if (count < 1) printf("=> 수정할 데이터가 없습니다.\n\n");
            else {
                listInfo(plist, index);
                int num = selectNum();

                if(num == 0){
                    printf("=> 취소되었습니다.\n\n");
                    continue;
                }

                updateInfo(plist[num-1]);
            }
        }
        else if (menu == 4) { // 환자 정보 삭제 
            if (count < 1) printf("=> 삭제할 데이터가 없습니다.\n\n");
            else {
                listInfo(plist, index);
                int num = selectNum();

                if(num == 0){
                    printf("=> 취소되었습니다.\n\n");
                    continue;
                }
                int deleteok;
                printf("=> 정말로 삭제하시겠습니까? (삭제:1) : ");
                scanf("%d", &deleteok);
                printf("\n");
                if (deleteok == 1) count -= deleteInfo(plist[num-1]);
                else continue;
            }
        }
        else if (menu == 5) { // 파일 저장
        printf("%d\n", count);
            if (count == 0) printf("=> 저장할 데이터가 없습니다.\n\n");
            else saveData(plist, index);
        }
        else if (menu == 6) { // 파일에서 이름 검색
            if (count == 0) printf("=> 데이터가 없습니다.\n\n");
            else searchName(plist, index);
        }
    }
    printf("=> 종료\n");
    return 0;
}
