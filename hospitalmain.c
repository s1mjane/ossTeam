#include <stdio.h>
#include <stdlib.h> // 동적할당
#include <string.h> // strstr
#include <time.h>
#include "hospital.h"

int main(void){
    int index, count, menu, diagcount;
    count = 0;
    index = 0;
    diagcount = 0;

    int infocheck;
    Patient *plist[20]; // README.md 파일에 20명이라고 해놔서 100명->20명으로 고쳤어요!
    
    count = loadData(plist); // 환자 리스트 로드
    index = count;
    diagcount = DiagloadData(plist, index); // 

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
            if (count < 1) printf("=> 수정할 데이터가 없습니다.(현재 데이터 0개)\n\n");
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
            if (count < 1) printf("=> 삭제할 데이터가 없습니다.(현재 데이터 0개)\n\n");
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
                    getchar();
                    printf("\n");
                    if (deleteok == 1) count -= deleteInfo(plist[num-1]);
                    else {
                        printf("취소되었습니다.\n");
                        continue;
                    }
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
        //printf("%d\n",diagcount);
            if(diagcount < 1) printf("=> 진단서 작성이 완료된 환자가 없습니다.\n\n");
            else{
                Diagnosislist(plist, index);
            }

        } else if (menu == 10) { // 수술 예약 
            if (count < 1) printf("=> 수술 예약할 환자가 없습니다.(현재 데이터 0개)\n\n");
            else {          
                listInfo(plist, index);
                int num;
                printf("=> 몇 번 환자의 수술 예약을 추가하시겠습니까?(취소:0) ");
                scanf("%d", &num);
                getchar();
                if (num == 0) {
                    printf("취소되었습니다.\n");
                    continue;
                }
                if (surgeryList(plist, index, num) != 1) continue; 
                Longstay(plist, num); // 입원 수속
            }
        } else if (menu == 11) { // 결제 청구
            if (count < 1) printf("=> 결제 청구할 화자가 없습니다.(현재 데이터 0개)\n");
            else {
                listInfo(plist, index);
                createbill(plist);
            }

        } else if (menu == 12) { // 결제
            if (count < 1) printf("=> 처리할 결제 정보가 없습니다.(현재 데이터 0개)\n\n");
            else {          
                listInfo(plist, index);
                int num;
                printf("=> 몇 번 환자의 결제 정보를 추가하시겠습니까?(취소:0) ");
                scanf("%d", &num);
                if(num == 0) {
                    printf("취소되었습니다.\n");
                    continue;
                } else if(num > count || plist[num-1]->birthday == -1) {
                    printf("해당 환자의 데이터가 없습니다.\n");
                    continue;
                } else if(pay(plist, num) != 1) continue; 
            }
        }
    }
    printf("=> 종료\n");
    return 0;
}
