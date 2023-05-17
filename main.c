#include <stdio.h>
#include <stdlib.h> // 동적할당
#include <string.h> // strstr
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

    // 여기서부터 아래는 진단서 작성 및 수술 예약 메뉴 등에 필요한 추가 정보
    char diagnosis[100]; // 진단
    char treatment[100]; // 치료 방법
    char recommendation[100]; //예방 및 권고사항
    char medicine[100]; // 약 처방
    char needSurgery[10]; // 수술필요여부
    char surgeryName[100]; // 수술 이름
    int surgeryDate; // 수술 날짜
    int diagcheck2; // 진단서 작성되었는지 
    char billok[2]; // 결제 여부
} Patient;

// [for 메뉴 1번] 글자수 세는 함수 (department 글자수 계산 위해)
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

// [메뉴 1번 세부] 특정환자 세부정보 조회
int OnereadInfo(Patient p, int infonum) {

    if(p.birthday == -1) return 0;
    char diag[10];
    
    printf("\n*** %d번 환자의 세부 정보 ***\n", infonum);
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("%s\t%s\t%s\t\t\t\t\t%s\t%s\t%s\n", 
            "Name ", "PhoneNumber  ", "Address", "Diagnosis", "수술 날짜", "결제 여부");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    int len = stringLength(p.address);

    if(p.diagcheck2 == 1) {
        strcpy(diag, "있음");
    } else {
        strcpy(diag, "없음");
    }

    if (len <= 16) {
        if (p.surgeryDate == 0) printf("%s\t%s\t%s\t\t\t\t\t%s\t\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
        else printf("%s\t%s\t%s\t\t\t\t\t%s\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
    } else if (len <= 32) {
        if (p.surgeryDate == 0) printf("%s\t%s\t%s\t\t\t\t%s\t\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
        else printf("%s\t%s\t%s\t\t\t\t\t%s\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
    } else if (len <= 48) {
        if (p.surgeryDate == 0) printf("%s\t%s\t%s\t\t\t%s\t\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
        else printf("%s\t%s\t%s\t\t\t\t\t%s\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
    } else if (len <= 64) {
        if (p.surgeryDate == 0) printf("%s\t%s\t%s\t\t%s\t\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
        else printf("%s\t%s\t%s\t\t\t\t\t%s\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
    } else if (len <= 96) {
        if (p.surgeryDate == 0) printf("%s\t%s\t%s\t%s\t\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
        else printf("%s\t%s\t%s\t\t\t\t\t%s\t%d\t\t%s\n", p.name, p.phone, p.address, diag, p.surgeryDate, p.billok);
    }
    return 1;
}

// [for 메뉴 1번 세부] 세부정보 조회할 특정환자 선택
void OnelistInfo(Patient *p[], int count) {
    int infonum;
    printf("원하는 환자의 번호를 입력해주세요 : ");
    scanf("%d", &infonum);
    getchar();
    if((infonum <= 0) || (infonum > count) || OnereadInfo(*p[infonum-1], infonum)==0) {
        printf("해당 환자의 데이터가 없습니다.\n");
    }
    printf("\n");
}

// [메뉴 1번] 환자 정보 조회
void readInfo(Patient p){
    int len = stringLength(p.department);
    if (len < 12) printf("%s\t%s\t%d\t%d\t%s\t\t%s\n", p.name, p.sex, p.age, p.birthday, p.department, p.symptom);
    if (len > 11) printf("%s\t%s\t%d\t%d\t%s\t%s\n", p.name, p.sex, p.age, p.birthday, p.department, p.symptom);
}

// [메뉴 1번] 환자 정보 조회 리스트 (최대 20명)
void listInfo(Patient *p[], int count){
    printf("================================ 환자 진료 예약 리스트 =======================================\n");
    printf("%s %s\t%s\t%s\t%s\t%s\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ", "Department", "Symptom");
    printf("==============================================================================================\n");
    for(int i=0; i<count; i++) {
        if(p[i]->birthday == -1) continue;
        printf("%2d ", i+1);
        readInfo(*p[i]);
    } printf("\n");
}

// [메뉴 2번] 환자 정보 추가
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
    scanf(" %[^\n]s", p->address);
    printf("진료과: ");
    scanf("%s", p->department);
    printf("증상: ");
    scanf(" %[^\n]s", p->symptom);
    ch = getchar();
    // strcpy(p->diagcheck, "X");
    strcpy(p->billok, "X");
    p->diagcheck2 = 0;
    

    // 생년월일만 입력 받고 나이는 함수 내에서 따로 계산해 저장만 해 둠. 추후 필요할 때 출력.
    p->age = t->tm_year+1900-(p->birthday/10000)+1;

    printf("=> %s 환자 진료 예약이 추가되었습니다.\n\n", p->name);
    return 1;
}

// [for 메뉴 3번 & 4번] 환자 정보 수정/삭제 메뉴 시 번호 선택
int selectNum() {
    int num;
    printf("=> 환자 번호(취소:0) : ");
    scanf("%d", &num);
    return num;
}

// [메뉴 3번] 환자 정보 수정
int updateInfo(Patient *p){
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
    scanf(" %[^\n]s", p->address);
    printf("진료과: ");
    scanf("%s", p->department);
    printf("증상: ");
    scanf(" %[^\n]s", p->symptom);
    ch = getchar();
    strcpy(p->billok, "X");
    p->diagcheck2 = 0;

    // 생년월일만 입력 받고 나이는 함수 내에서 따로 계산해 저장만 해 둠. 추후 필요할 때 출력.
    p->age = t->tm_year+1900-(p->birthday/10000)+1;

    printf("=> %s 환자 진료 예약이 수정되었습니다.\n\n", p->name);
    return 1;
}

// [메뉴 4번] 환자 정보 삭제
int deleteInfo(Patient *p) {
    p->birthday = -1;
    return 1;
}

// [메뉴 5번] 파일 저장
void saveData(Patient *p[], int count) {
    FILE *fp;
    fp = fopen("patient.txt","wt"); // 텍스트 쓰는 용도로 파일 오픈
    for (int i = 0; i<count; i++) {
        if (p[i]->birthday != -1) {
            fprintf(fp, "%s %s %d %d %s %s %d %s\n", p[i]->name, p[i]->sex, p[i]->age, p[i]->birthday, p[i]->phone, p[i]->department, p[i]->diagcheck2, p[i]->billok);
            fprintf(fp, "%s\n", p[i]->address);
            fprintf(fp, "%s\n", p[i]->symptom);
        }
    } 
    fclose(fp);
    printf("=> 환자 리스트 파일 저장되었습니다.\n");
}

// [메뉴 5번] 진단서 파일 저장
void DiagsaveData(Patient *p[], int count) {
    FILE *fp;
    fp = fopen("diagnosis.txt","wt");

    for (int i = 0; i<count; i++) {
        if(p[i]->diagcheck2 == 1) {
            fprintf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n", p[i]->name, p[i]->diagnosis, p[i]->treatment, p[i]->recommendation, p[i]->medicine, p[i]->needSurgery);
        }
    } 
    fclose(fp);
    printf("=> 진단서 파일 저장되었습니다.\n\n");
}

// 프로그램 실행시 환자  txt 파일 로드
int loadData(Patient *p[]) {
    int i = 0;
    int count = 0;

    FILE *fp;
    fp = fopen("patient.txt", "rt"); // 읽어오는 용도로 파일 오픈
    
    if (fp == NULL) {
        printf("환자 리스트 파일 로드 중\n==> 저장된 환자 리스트 파일이 없습니다.\n");
        return i;
    } 
    for (; i<20; i++) {
        p[i] = malloc(sizeof(Patient));
        fscanf(fp, "%s", p[i]->name);
        if (feof(fp)) break; // 파일 끝을 만났을 때
        fscanf(fp, "%s", p[i]->sex);
        fscanf(fp, "%d", &p[i]->age);
        fscanf(fp, "%d", &p[i]->birthday);
        fscanf(fp, "%s", p[i]->phone);
        fscanf(fp, "%s", p[i]->department);
        fscanf(fp, "%d", &p[i]->diagcheck2);
        fscanf(fp, "%s", p[i]->billok);
        fgetc(fp);
        fgets(p[i]->address, sizeof(p[i]->address), fp);
        p[i]->address[strlen(p[i]->address)-1] = '\0';
        fgets(p[i]->symptom, sizeof(p[i]->symptom), fp);
        p[i]->symptom[strlen(p[i]->symptom)-1] = '\0';

        if(p[i] == NULL) {
            free(p[i]); // 동적할당한 것 해제
            i--;
            continue;
        }
    }
    fclose(fp);
    printf("환자 리스트 파일 로드 중\n=> 로딩 성공!\n");
    return i;
}

// [메뉴 6번] 환자 이름 검색
void searchName(Patient *p[], int count) {
    int pcount = 0;
    char search[20];
    printf("=> 검색할 이름 : ");
    scanf("%s", search);
    printf("===================================== 리스트 검색 조회 결과 =====================================\n");
    printf("%s %s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ", "PhoneNumber  ", "Address", "Department", "Symptom");
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

// [메뉴 7번] 과별 환자 검색
void searchDepartment(Patient *p[], int count) {
    int check = 0;
    char search[20];

    printf("=> 검색할 과 이름(ex: 내과/외과/피부과): ");
    scanf("%s", search);

    printf("\n*** %s 환자 리스트 ***\n", search);
    printf("%s %s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ", "PhoneNumber  ", "Address", "Department", "Symptom");
    printf("==============================================================================================\n");

    for(int i=0; i<count; i++) {
        if(p[i] == NULL)
            continue;
        if(strstr(p[i]->department, search)) {
            printf("%2d ", i+1);
            readInfo(*p[i]);
            check++;
        }
    }
    if(check == 0) {
        printf("=> 검색된 데이터가 없습니다.\n");
    }
}

// [메뉴 8번] 진단서 작성 여부 출력
void checkDiagnosis(Patient *p[], int count) {
    char diag[10];
    printf("%s %s\t%s\n", "No", "Name ", "진단서 작성 여부");
    printf("===================================\n");
    for(int i=0; i<count; i++) {
        if(p[i]->birthday == -1) continue;
        if(p[i]->diagcheck2 == 1) {
            strcpy(diag, "O");
        } else {
            strcpy(diag, "X");
        }
        printf("%2d ", i+1);
        //readInfo(*p[i]);
        printf("%s\t%s\n", p[i]->name, diag);
    } printf("\n");
}



// [메뉴 8번] 진단서 작성
void writeDiagnosis(Patient *p) {
    getchar();
    printf("\n=== %s 환자 진단서 작성 ===\n", p->name);
    printf("진단(병명) : ");
    scanf("%[^\n]s", p->diagnosis);
    getchar();
    printf("치료방법 : ");
    scanf("%[^\n]s", p->treatment);
    getchar();
    printf("예방 및 권고사항 : ");
    scanf("%[^\n]s", p->recommendation);
    getchar();
    printf("약 처방 : ");
    scanf("%[^\n]s", p->medicine);
    getchar();
    printf("수술 필요 여부(O/X) : ");
    scanf("%[^\n]s", p->needSurgery);
    getchar();
    if (strcmp(p->needSurgery, "O")==0) printf("=> 11번 메뉴를 선택해 수술 예약을 잡으세요.\n");
    p->diagcheck2 = 1;
    printf("=> %s 환자의 진단서가 작성되었습니다.\n=> 진단서는 메뉴 9번으로 조회할 수 있습니다.\n", p->name);
    return;
}

// [메뉴 9번] 선택된 환자의 진단서 출력
void DiagnosisPrint(Patient p){
    printf("\n=== %s 환자 진단서 ===\n", p.name);
    printf("진단(병명) : %s\n", p.diagnosis);
    printf("치료방법 : %s\n", p.treatment);
    printf("예방 및 권고사항 : %s\n", p.recommendation);
    printf("약 처방 : %s\n", p.medicine);
    printf("수술 필요 여부(있음/없음) : %s\n", p.needSurgery);
}

// [for 메뉴 9번] 진단서 작성된 환자 조회 및 선택
void Diagnosislist(Patient *p[], int count) {
    int num;
    char check;
    printf("=== 진단서가 작성된 환자 목록 ===\n");
    printf("%s %s\t%s\t%s\t%s\t%s\t\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ","Department", "Symptom");
    printf("=======================================================================================================\n");
    for(int i=0; i<count; i++) {
        if(p[i] == NULL)
            continue;
        if(p[i]->diagcheck2 == 1) {
            printf("%2d ", i+1);
            readInfo(*p[i]);
        }
    }
    
    while(1) {
        printf("\n진단서를 확인하고 싶은 환자의 번호는? : "); // 진단서를 확인하고 싶은 환자 번호 선택
        scanf("%d", &num);
        getchar();
        if(num <= 0 || num > count || p[num-1]->diagcheck2 != 1){
            printf("잘못입력된 번호 입니다.\n");
        } else {
            DiagnosisPrint(*p[num-1]); // 진단서 
            break;
        }
    }
   
}

// 프로그램 실행시 진단서 txt 파일 
int DiagloadData(Patient *p[], int count) {
    int i = 0;
    int countdiag = 0;
    char str[100];
    char namecheck[20];

    FILE *fp;
    fp = fopen("diagnosis.txt", "rt"); // 읽어오는 용도로 파일 오픈
 
    if (fp == NULL) {
		printf("==> 저장된 진단서 파일이 없습니다.\n");
		return i;
	}

    for (i=0; i<count; i++) {
        if (feof(fp)) {
            printf("end\n");
            break; // 파일 끝을 만났을 때
        }

        if(p[i]->diagcheck2 != 1) {
            continue;
        }

        fgets(namecheck, sizeof(namecheck), fp);
        namecheck[strlen(namecheck)-1] = '\0';
    
        if(strcmp(namecheck, p[i]->name) == 0) {
            if(fgets(p[i]->diagnosis, sizeof(p[i]->diagnosis), fp) == NULL) {
                printf("diagnosis NULL\n");
            }
            p[i]->diagnosis[strlen(p[i]->diagnosis)-1] = '\0';

            if(fgets(p[i]->treatment, sizeof(p[i]->treatment), fp) == NULL) {
                printf("treatment NULL\n");
            }
            p[i]->treatment[strlen(p[i]->treatment)-1] = '\0';

            if(fgets(p[i]->recommendation, sizeof(p[i]->recommendation), fp) == NULL) {
                printf("recommendation NULL\n");
            }
            p[i]->recommendation[strlen(p[i]->recommendation)-1] = '\0';

            if(fgets(p[i]->medicine, sizeof(p[i]->medicine), fp) == NULL) {
                printf("recommendation NULL\n");
            }
            p[i]->medicine[strlen(p[i]->medicine)-1] = '\0';

            if(fgets(p[i]->needSurgery, sizeof(p[i]->needSurgery), fp) == NULL) {
                printf("needSurgery NULL\n");
            }
            p[i]->needSurgery[strlen(p[i]->needSurgery)-1] = '\0';

            countdiag++;
        } else {
            continue;
        }

        if(p[i] == NULL) {
            free(p[i]); // 동적할당한 것 해제
            i--;
            continue;
        }
    }
    fclose(fp);
    printf("진단서 파일 파일 로드 중\n=> 로딩 성공!\n\n");
    return countdiag;
}


// [메뉴 10번] 처방전 조회


// [for 메뉴 11번] 수술 예약 추가시 날짜 가능 확인 여부 조회하는 함수
int isAvailableDate(Patient *p[], int count, int date) {
    for (int i=0; i<count; i++) {
        if (p[i]==NULL) continue;
        if (date == p[i]->surgeryDate) return 0;
    }
    return 1; // 겹치는 날짜 없을 때 1 리턴
}

// [메뉴 11번] 수술 예약
int surgeryList(Patient *p[], int count, int num) {
    Patient ok; // 예약 추가하기 전에 잠깐 넣어놓을 용도
    // 잠깐 넣어놓을 곳으로 일단 정보 받음
    printf("\n=== %s 환자의 수술 예약 추가 ===\n", p[num-1]->name);
    printf("수술명 : ");
    scanf("%s", ok.surgeryName);
    while(1) {
    // 수술 가능 날짜 확인
        printf("수술날짜(8자리) : ");
        scanf("%d", &ok.surgeryDate);
        if (count > 0) {
            if (isAvailableDate(p, count, ok.surgeryDate) == 1) {
                p[num-1]->surgeryDate = ok.surgeryDate;
                printf("=> %s 환자의 수술 예약이 추가되었습니다.\n=> 예약 정보는 '메뉴 1번' 환자 조회의 세부 정보 조회로 확인할 수 있습니다.\n\n", p[num-1]->name);
                return 1;
                break;
            } else { // 날짜 겹쳐서 안 되는 경우
                printf("=> 예약 불가능한 날짜입니다.\n\n");
            }
        } else { // 맨 처음 추가인 경우 무조건 추가 가능
            p[num-1]->surgeryDate = ok.surgeryDate;
            printf("=> %s 환자의 수술 예약이 추가되었습니다. 예약 정보는 메뉴 1번 환자 조회의 세부 정보 조회로 확인할 수 있습니다.\n\n", p[num-1]->name);
            return 1;
            break;
        }
    }
}

// [메뉴 12번] 결제
int pay(Patient *p[], int count, int num){
    int way = 0;
    printf("=== %s 환자 결제창 ===\n", p[num-1]->name);
    printf("결제 방법(카드:1/현금:2) : ");
    scanf("%d", &way);
    // 결제 완료 (메뉴1번의 세부조회정보에서 표시)
    if (way == 1 || way == 2) {
        strcpy(p[num-1]->billok, "O");
        printf("=> %s 환자 결제 완료되었습니다.\n\n", p[num-1]->name);
        printf("=> 결제 여부 정보는 메뉴 1번의 환자 세부 정보 조회로 확인할 수 있습니다.\n");
    } else printf("=> 결제 방법을 잘못 입력하였거나, 결제가 되지 않았습니다.\n");
    return 1;
}


// 1~11번 및 종료 메뉴 선택
int selectMenu(){
    int menu;
    printf("\n🏥 병원 환자 관리 시스템 🖥️\n");
    printf("1. 환자 조회\t2. 환자 추가\t3. 환자 정보 수정\t4. 환자 정보 삭제\n");
    printf("5. 파일 저장\t6. 환자 검색\t7. 과별 환자 정보 검색\t8. 진단서 추가\n");
    printf("9. 진단서 조회\t10. 처방전 조회\t11. 수술 예약\t\t12. 결제\t0. 종료\n");
    printf("====> 원하는 메뉴: ");
    scanf("%d", &menu);
    getchar();
    printf("\n");
    return menu;
}

// 메인
int main(void){
    int index, count, menu, diagcount;
    count = 0;
    index = 0;
    diagcount = 0;

    int infocheck;
    Patient *plist[20]; // README.md 파일에 20명이라고 해놔서 100명->20명으로 고쳤어요!
    
    count = loadData(plist);
    index = count;
    diagcount = DiagloadData(plist, index);

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        else if (menu == 1){ // 환자 조회
            if (count > 0) {
                listInfo(plist, index);
                while(1) {
                    printf("특정 환자의 정보를 조회하고 싶으시면 아무 번호나 누르세요. (취소:0) : ");
                    scanf("%d", &infocheck);
                    getchar();
                    if(infocheck == 0) {
                        printf("=> 취소되었습니다.\n");
                        break;
                    } else { 
                        // listInfo(plist, index);
                        OnelistInfo(plist, index);
                        printf("추가로 ");
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
                diagcount++;
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

                if(plist[num-1]->birthday == -1) {
                    printf("삭제할 데이터가 없습니다.\n");
                } else {
                    int deleteok;
                    printf("=> 정말로 삭제하시겠습니까? (삭제:1) : ");
                    scanf("%d", &deleteok);
                    printf("\n");
                    if (deleteok == 1) count -= deleteInfo(plist[num-1]);
                    else continue;
                }
            }
        }
        else if (menu == 5) { // 파일 저장
            if (count == 0) printf("=> 저장할 데이터가 없습니다.\n\n");
            else {
                saveData(plist, index);
                DiagsaveData(plist, index);
            }
        }
        else if (menu == 6) { // 파일에서 이름 검색
            if (count == 0) printf("=> 데이터가 없습니다.\n\n");
            else searchName(plist, index);
        }
        else if (menu == 7) { // 검색한 과의 환자 리스트
            if (count == 0) printf("=> 데이터가 없습니다.\n\n");
            else searchDepartment(plist, index);
        }
        else if (menu == 8) { // 진단서 작성
            if (count < 1) printf("=> 아직 진단서를 작성할 환자가 없습니다.(현재 데이터 0개)\n\n");
            else {
                printf("=> 진단서 작성할 환자\n");
                checkDiagnosis(plist, index);
                int num = selectNum();
                if(num == 0){
                    printf("=> 취소되었습니다.\n");
                    continue;
                }
                writeDiagnosis(plist[num-1]);
                diagcount++;
            }

        } else if (menu == 9) { // 진단서 조회
            if(diagcount < 1) printf("=> 진단서 작성이 완료된 환자가 없습니다.\n\n");
            else{
                Diagnosislist(plist, index);
            }
        } else if (menu == 10) {

        } else if (menu == 11) { // 수술 예약 
            if (count < 1) printf("=> 수술 예약할 환자가 없습니다.(현재 데이터 0개)\n\n");
            else {          
                listInfo(plist, index);
                int num;
                printf("=> 몇 번 환자의 수술 예약을 추가하시겠습니까? ");
                scanf("%d", &num);
                if (surgeryList(plist, index, num) != 1) continue; 
            }
        } else if (menu == 12) { // 결제
            if (count < 1) printf("=> 처리할 결제 정보가 없습니다.(현재 데이터 0개)\n\n");
            else {          
                listInfo(plist, index);
                int num;
                printf("=> 몇 번 환자의 결제 정보를 추가하시겠습니까? ");
                scanf("%d", &num);
                if (pay(plist, index, num) != 1) continue; 
            }
        }
    }
    printf("=> 종료\n");
    return 0;
}
