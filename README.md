# 2023OSSL Team Project

## Mini Project 주제
> 병원 환자 정보 관리 시스템

## Mini Project 에 대한 소개
<img src = "https://cdn.pixabay.com/photo/2021/02/19/23/17/reception-6031806_1280.png">
> 병원에 등록한 환자들의 정보를 보여준다. **20명의 환자 정보를 관리**하며, **메뉴는 약 11개**이다.

<br>

## Project 에 포함시킬 기능
#### 1. 환자 정보 등록 (추가)
  : 환자에 대한 정보를 추가하는 함수
    a. 이름, 생일, 나이, 처음내원 여부, 성별, 전화번호, 주소, 과, 증상
#### 2. 환자 정보 수정 (수정)
  : 환자 정보를 수정하는 함수
#### 3. 환자 정보 삭제 (삭제)
  : 환자 정보를 삭제하는 함수
#### 4. 환자 정보 조회 (조회)
  : 환자 정보를 볼수있는 조회 함수  
    1. 전체 리스트(최대 20명) - 환자 개개인의 간단한 정보 조회  
    2. 개인 리스트 - 특정 환자에 대한 자세한 정보 조회 (ex. 수술 예약 정보, 수납 상태 정보 등)  
    - 전체 리스트를 조회한 후 개인 리스트로 **검색**을 통해 조회함 (검색)
#### 5. 파일 저장
  : 전체 환자 정보 리스트 (전체 리스트)
#### 6. 파일 로드
  : 프로그램 실행과 동시에 실행되는 기능
#### 7. 진단서 조회
  : 메뉴 1번 환자 정보를 등록할 때 진단서를 작성하는 함수를 실행할 예정
#### 8.진단서 수정
#### 9. 약 처방
  - 진단명에 매칭되는 약 정보가 있는 리스트 필요
  step1. 전체 리스트 조회 후 특정 환자 선택
  stpe2. 환자 이름, 진단명, 약 이름, 약 설명, 약값에 대한 정보 출력
#### 10. 수술 예약
  step1. 수술 날짜 가능한지 확인 (가능한 날짜가 나올 때까지 while문)
  step2. 환자 선택 -> 수술명, 수술방, 날짜 정보 추가
#### 11. 환자 결제 정보 조회
  step1. 전체 리스트 조회 후 특정 환자 선택
  stpe2. 수술비, 진료비, 약 처방비, 입원비 등 리스트 조회
  
  
## 개발환경 및 언어
> 개발환경 : vscode <br>
> 언어 : C언어
  
  
## 팀소개 및 팀원이 맡은 역할
> `21900201 김채은` : 환자 정보 CRUD + 검색기능 구현 <br>
> `21900412 심재인` : 파일 관리, 진단서 조회 및 수정, 약/수술/결제 메뉴 구현

<img src = "https://cdn.pixabay.com/photo/2016/06/24/02/35/ehr-1476525_1280.png" width="400px">

