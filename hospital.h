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
    int surgerycheck; //수술 진행 여부
    int longstay; // 입원 기간
    int room; // 몇인실
    int longstaycheck; // 입원 여부

    // 결제 정보
    int medicalfee; // 진료비
    int surgeryfee; // 수술비
    int totalfee; // 전체 결제비
    char billok[2]; // 결제 여부
} Patient;

// [for 메뉴 1번] 글자수 세는 함수 (department 글자수 계산 위해)
int stringLength(const char* str);

// [메뉴 1번 세부] 특정환자 세부정보 조회
int OnereadInfo(Patient p, int infonum);

// [for 메뉴 1번 세부] 세부정보 조회할 특정환자 선택
void OnelistInfo(Patient *p[], int count);

// [메뉴 1번] 환자 정보 조회
void readInfo(Patient p);

// [메뉴 1번] 환자 정보 조회 리스트 (최대 20명)
void listInfo(Patient *p[], int count);

// [메뉴 2번] 환자 정보 추가
int addInfo(Patient *p);

// [for 메뉴 3번 & 4번] 환자 정보 수정/삭제 메뉴 시 번호 선택
int selectNum();

// [메뉴 3번] 환자 정보 수정
int updateInfo(Patient *p);

// [메뉴 4번] 환자 정보 삭제
int deleteInfo(Patient *p);

// [메뉴 5번] 파일 저장
void saveData(Patient *p[], int count);

// [메뉴 5번] 진단서 파일 저장
void DiagsaveData(Patient *p[], int count);

// 프로그램 실행시 환자  txt 파일 로드
int loadData(Patient *p[]);

// 프로그램 실행시 진단서 txt 파일 
int DiagloadData(Patient *p[], int count);

// [메뉴 6번] 환자 이름 검색
void searchName(Patient *p[], int count);

// [메뉴 7번] 과별 환자 검색
void searchDepartment(Patient *p[], int count);

// [메뉴 8번] 진단서 작성 여부 출력
void checkDiagnosis(Patient *p[], int count);

// [메뉴 8번] 진단서 작성
void writeDiagnosis(Patient *p);

// [메뉴 9번] 선택된 환자의 진단서 출력
void DiagnosisPrint(Patient p);

// [for 메뉴 9번] 진단서 작성된 환자 조회 및 선택
void Diagnosislist(Patient *p[], int count);

// [for 메뉴 10번] 수술 예약 추가시 입원 수속 
int Longstay(Patient *p[], int num);

// [for 메뉴 10번] 수술 예약 추가시 날짜 가능 확인 여부 조회하는 함수
int isAvailableDate(Patient *p[], int count, int date);

// [메뉴 10번] 수술 예약
int surgeryList(Patient *p[], int count, int num);

// [메뉴 11번] 결제 청구
int createbill(Patient *p[], int count);

// [메뉴 12번] 결제
int pay(Patient *p[], int num);

// 1~11번 및 종료 메뉴 선택
int selectMenu();
