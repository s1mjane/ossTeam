#include "hospital.h"

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
        strcpy(diag, "O");
    } else {
        strcpy(diag, "X");
    }

    if(p.surgerycheck == 1) {
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
    } else {
        if (len <= 16) {
            if (p.surgeryDate == 0) printf("%s\t%s\t%s\t\t\t\t\t%s\t\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
            else printf("%s\t%s\t%s\t\t\t\t\t%s\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
        } else if (len <= 32) {
            if (p.surgeryDate == 0) printf("%s\t%s\t%s\t\t\t\t%s\t\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
            else printf("%s\t%s\t%s\t\t\t\t\t%s\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
        } else if (len <= 48) {
            if (p.surgeryDate == 0) printf("%s\t%s\t%s\t\t\t%s\t\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
            else printf("%s\t%s\t%s\t\t\t\t\t%s\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
        } else if (len <= 64) {
            if (p.surgeryDate == 0) printf("%s\t%s\t%s\t\t%s\t\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
            else printf("%s\t%s\t%s\t\t\t\t\t%s\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
        } else if (len <= 96) {
            if (p.surgeryDate == 0) printf("%s\t%s\t%s\t%s\t\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
            else printf("%s\t%s\t%s\t\t\t\t\t%s\t%s\t\t%s\n", p.name, p.phone, p.address, diag, "X", p.billok);
        }
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
    struct tm *t;
    time_t now = time(NULL);
    t = localtime(&now);

    printf("환자 이름: ");
    scanf("%s", p->name);
    getchar();
    printf("성별(M or F): ");
    scanf("%s", p->sex);
    getchar();
    printf("생년월일은(8자리): ");
    scanf("%d", &p->birthday);
    getchar();
    printf("핸드폰 번호(숫자만): ");
    scanf("%s", p->phone);
    getchar();
    printf("주소: ");
    scanf(" %[^\n]s", p->address);
    getchar();
    printf("진료과: ");
    scanf("%s", p->department);
    getchar();
    printf("증상: ");
    scanf(" %[^\n]s", p->symptom);
    getchar();
    strcpy(p->billok, "X");
    p->diagcheck2 = 0;
    p->longstaycheck = 0;

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
    struct tm *t;
    time_t now = time(NULL);
    t = localtime(&now);

    printf("환자 이름: ");
    scanf("%s", p->name);
    getchar();
    printf("성별(M or F): ");
    scanf("%s", p->sex);
    getchar();
    printf("생년월일은(8자리): ");
    scanf("%d", &p->birthday);
    getchar();
    printf("핸드폰 번호(숫자만): ");
    scanf("%s", p->phone);
    getchar();
    printf("주소: ");
    scanf(" %[^\n]s", p->address);
    getchar();
    printf("진료과: ");
    scanf("%s", p->department);
    getchar();
    printf("증상: ");
    scanf(" %[^\n]s", p->symptom);
    getchar();
    strcpy(p->billok, "X");
    p->diagcheck2 = 0;
    p->longstaycheck = 0;

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
            fprintf(fp, "%s %s %d %d %s %s %d %s %d %d\n", p[i]->name, p[i]->sex, p[i]->age, p[i]->birthday, p[i]->phone, p[i]->department, p[i]->diagcheck2, p[i]->billok, p[i]->longstaycheck, p[i]->surgeryDate);
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
            fprintf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%d\n", p[i]->name, p[i]->diagnosis, p[i]->treatment, p[i]->recommendation, p[i]->medicine, p[i]->needSurgery, p[i]->surgerycheck);
        }
    } 
    fclose(fp);
    printf("=> 진단서 파일 저장되었습니다.\n\n");
}

// 프로그램 실행시 환자  txt 파일 로드
int loadData(Patient *p[]) {
    int i = 0;

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
        fscanf(fp, "%d", &p[i]->longstaycheck);
        fscanf(fp, "%d", &p[i]->surgeryDate);
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

// 프로그램 실행시 진단서 txt 파일 
int DiagloadData(Patient *p[], int count) {
    int i = 0;
    int countdiag = 0;
    char namecheck[20];

    FILE *fp;
    fp = fopen("diagnosis.txt", "rt"); // 읽어오는 용도로 파일 오픈
 
    if (fp == NULL) {
		printf("진단서 파일 로드 중\n==> 저장된 진단서 파일이 없습니다.\n");
		return i;
	}

    for (i=0; i<count; i++) {
        if (feof(fp)) {
            printf("end\n");
            break; // 파일 끝을 만났을 때
        }

        if(p[i]->diagcheck2 != 1) { // 진단서 작성되지 않은 경우
            continue;
        }

        fgets(namecheck, sizeof(namecheck), fp);
        namecheck[strlen(namecheck)-1] = '\0';
    
        if(strcmp(namecheck, p[i]->name) == 0) { // 같은 이름이 있을 때
            fgets(p[i]->diagnosis, sizeof(p[i]->diagnosis), fp);
            p[i]->diagnosis[strlen(p[i]->diagnosis)-1] = '\0';

            fgets(p[i]->treatment, sizeof(p[i]->treatment), fp);
            p[i]->treatment[strlen(p[i]->treatment)-1] = '\0';

            fgets(p[i]->recommendation, sizeof(p[i]->recommendation), fp);
            p[i]->recommendation[strlen(p[i]->recommendation)-1] = '\0';

            fgets(p[i]->medicine, sizeof(p[i]->medicine), fp);
            p[i]->medicine[strlen(p[i]->medicine)-1] = '\0';

            fgets(p[i]->needSurgery, sizeof(p[i]->needSurgery), fp);
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
    printf("진단서 파일 로드 중\n=> 로딩 성공!\n\n");
    return countdiag;
}

// [메뉴 6번] 환자 이름 검색
void searchName(Patient *p[], int count) {
    int pcount = 0;
    char search[20];
    printf("=> 검색할 이름 : ");
    scanf("%s", search);
    getchar();
    printf("============================= 환자 이름 검색 조회 결과 ====================================\n");
    printf("%s %s\t%s\t%s\t%s\t%s\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ", "Department", "Symptom");
    printf("===========================================================================================\n");
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
    if (pcount == 0) printf("\n=> 검색된 데이터가 없습니다.\n");
    printf("\n");
}

// [메뉴 7번] 과별 환자 검색
void searchDepartment(Patient *p[], int count) {
    int check = 0;
    char search[20];

    printf("=> 검색할 과 이름(ex: 내과/외과/피부과): ");
    scanf("%s", search);
    getchar();

    printf("\n*** %s 환자 리스트 ***\n", search);
    printf("=======================================================================================\n");
    printf("%s %s\t%s\t%s\t%s\t%s\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ", "Department", "Symptom");
    printf("=======================================================================================\n");

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
        printf("\n=> 검색된 데이터가 없습니다.\n");
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
    if (strcmp(p->needSurgery, "O")==0) printf("=> 10번 메뉴를 선택해 수술 예약을 잡으세요.\n");
    p->diagcheck2 = 1;
    printf("=> %s 환자의 진단서가 작성되었습니다.\n=> 진단서는 메뉴 9번으로 조회할 수 있습니다.\n", p->name);
    return;
}

// [메뉴 9번] 선택된 환자의 진단서 출력
void DiagnosisPrint(Patient p){
    time_t t = time(NULL);  // 현재 시간을 가져옴
    struct tm *now = localtime(&t);  // 지역 시간으로 변환
    printf("\n===== ♡ %s 환자 진단서 ♡ =====\n", p.name);
    printf("| 환자명 : %s\n", p.name);
    printf("| 성별 : %s\n", p.sex);
    printf("| 나이 : %d\n", p.age);
    printf("| 진단(병명) : %s\n", p.diagnosis);
    printf("| 치료방법 : %s\n", p.treatment);
    printf("| 예방 및 권고사항 : %s\n", p.recommendation);
    printf("| 약 처방 : %s\n", p.medicine);
    printf("| 수술 필요 여부 : %s\n", p.needSurgery);
    printf("| \n");
    printf("| OSS 병원 %s %d.%d.%d\n", p.department, now->tm_year+1900, now->tm_mon+1, now->tm_mday);
    printf("==================================\n");
}

// [for 메뉴 9번] 진단서 작성된 환자 조회 및 선택
void Diagnosislist(Patient *p[], int count) {
    int num;
    printf("=== 진단서가 작성된 환자 목록 ===\n");
    printf("%s %s\t%s\t%s\t%s\t%s\t\t%s\n", "No", "Name ", "Sex", "Age", "Birthday   ","Department", "Symptom");
    printf("=======================================================================================================\n");
    for(int i=0; i<count; i++) {
        if(p[i] == NULL || p[i]->birthday == -1)
            continue;
        if(p[i]->diagcheck2 == 1) {
            printf("%2d ", i+1);
            readInfo(*p[i]);
        }
    }
    
    while(1) {
        printf("\n진단서를 확인하고 싶은 환자의 번호는?(취소:0) : "); // 진단서를 확인하고 싶은 환자 번호 선택
        scanf("%d", &num);
        getchar();
        if(num == 0) {
            printf("=> 취소되었습니다.\n");
            break;
        }else if(num < 0 || num > count || p[num-1]->diagcheck2 != 1){
            printf("잘못입력된 번호 입니다.\n");
        } else {
            DiagnosisPrint(*p[num-1]); // 진단서 
            break;
        }
    }
}

// [for 메뉴 10번] 수술 예약 추가시 입원 수속 
int Longstay(Patient *p[], int num) {
    printf("\n=== 입원 수속 ===\n");
    printf("며칠동안 입원하실 예정입니까? : ");
    scanf("%d", &p[num-1]->longstay);
    getchar();
    if(p[num-1]->longstay == 0) {
        p[num-1]->longstaycheck = 0;
        return -1;
    }
    printf("\n[1인실 : 10만원 / 2인실 : 2만원 / 4인실 : 5000원]\n");
    printf("몇인실을 원하십니까? (숫자만) : ");
    scanf("%d", &p[num-1]->room);
    getchar();
    p[num-1]->longstaycheck = 1;
    return 1;
}

// [for 메뉴 10번] 수술 예약 추가시 날짜 가능 확인 여부 조회하는 함수
int isAvailableDate(Patient *p[], int count, int date) {
    struct tm *t;
    time_t now = time(NULL);
    t = localtime(&now);
    int nowdate;

    for (int i=0; i<count; i++) {
        if (p[i]==NULL) continue;
        if (date == p[i]->surgeryDate) return 0;
    }

    nowdate = (t->tm_year+1900)*10000+(t->tm_mon+1)*100+t->tm_mday;

    if((nowdate - date) > 0) {
        return -1;
    }
    return 1; // 겹치는 날짜 없을 때 1 리턴
}

// [메뉴 10번] 수술 예약
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
        getchar();
        if (count > 0) {
            if (isAvailableDate(p, count, ok.surgeryDate) == 1) {
                p[num-1]->surgeryDate = ok.surgeryDate;
                printf("=> %s 환자의 수술 예약이 추가되었습니다.\n=> 예약 정보는 '메뉴 1번' 환자 조회의 세부 정보 조회로 확인할 수 있습니다.\n\n", p[num-1]->name);
                p[num-1]->surgerycheck = 1;
                return 1;
                break;
            } else { // 날짜 겹쳐서 안 되는 경우
                printf("=> 예약 불가능한 날짜입니다.\n\n");
            }
        } else { // 맨 처음 추가인 경우 무조건 추가 가능
            p[num-1]->surgeryDate = ok.surgeryDate;
            p[num-1]->surgerycheck = 1;
            printf("=> %s 환자의 수술 예약이 추가되었습니다. 예약 정보는 메뉴 1번 환자 조회의 세부 정보 조회로 확인할 수 있습니다.\n\n", p[num-1]->name);
            return 1;
            break;
        }
    }
}

// [메뉴 11번] 결제 청구
int createbill(Patient *p[]) {
    int num;
    int billofroom = 0;

    printf("=> 결제 정보를 입력할 환자 번호(취소:0) : ");
    scanf("%d", &num);
    getchar();

    if(num == 0) {
        printf("=> 취소되었습니다.\n");
        return 0;
    }

    printf("\n항목에 따른 결제 금액을 입력해주세요.\n");
    printf("진료비 : ");
    scanf("%d", &p[num-1]->medicalfee);
    getchar();

    if(p[num-1]->surgerycheck == 1) {
        printf("수술비 : ");
        scanf("%d", &p[num-1]->surgeryfee);
        getchar();
    } else {
        printf("수술비 : 0\n");
    }

    if(p[num-1]->longstaycheck == 1) {
        if(p[num-1]->room == 1) {
            billofroom = 100000 * p[num-1]->longstay;
        } else if(p[num-1]->room == 2) {
            billofroom = 20000 * p[num-1]->longstay;
        } else if(p[num-1]->room == 4) {
            billofroom = 5000 * p[num-1]->longstay;
        }
    }
    
    printf("입원비 : %d\n", billofroom);
    p[num-1]->totalfee = p[num-1]->medicalfee + p[num-1]->surgeryfee + billofroom;
    printf("\n[총 진료비 : %d원]\n",p[num-1]->totalfee);
    return 1;
}

// [메뉴 12번] 결제
int pay(Patient *p[], int num){
    int way = 0;
    printf("=== %s 환자 결제창 ===\n", p[num-1]->name);
    printf("결제 금액 : %d\n", p[num-1]->totalfee);
    printf("결제 방법(카드:1/현금:2) : ");
    scanf("%d", &way);
    getchar();
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
    printf("9. 진단서 조회\t10. 수술 예약\t11. 결제 청구\t\t12. 결제\t0. 종료\n");
    printf("====> 원하는 메뉴: ");
    scanf("%d", &menu);
    getchar();
    printf("\n");
    return menu;
}
