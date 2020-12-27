# Stacks and Queues
## size_t 란?
* sizt_t는 unsigned int 이며, 문자열이나 메모리 사이즈를 나타낼 때 사용
* sizt_t는 32bit, 64bit os에서 각각 부호없는 32,64bit 정수
  * But, ₩unsigned int 또는 int는 64bit os라해서 꼭 64bit 정수가 아님. 32bit 일 수도 있음₩
  * 메모리나 문자열 등의 길이를 구할 때는 size_t 타입으로 반환됨
  * 따라서 size_t가 아닌 unsigned int 타입을 캐스팅 없이 문자열에 대입하면 ₩conversion from size_t to unsigned int, possible loss of data 라는 경고가 나옴
    * unsigned int가 32bit일 수 도 있기 때문

## static과 extern 키워드를 이용한 내부/외부 링크
* 변수는 scope와 duration 외에도 linkage라는 속성이 있다.
* 링크가 없는 변수는 제한된 범위에서만 참조할 수 있다.
* static 변수 : 내부 링크가 있는 변수
  * static 변수는 변수가 정의된 소스 파일 내에서 어디서나 접근할 수 있지만, 소스 파일 외부에서는 참조할 수 없음
  * => 하나의 파일 내에서만 접근할 수 있는 전역 변수 생성은 static
* extern 변수 : 외부 링크가 있는 변수
  * extern 변수는 정의된 소스 파일과 다른 소스 파일 모두에서 접근할 수 있음
  * => 외부에서도 접근할 수 있는 전역 변수 생성은 extern
  * 변수 전방 선언 : 외부 소스파일에서 전역 변수를 사용하기 위한 작업

## static 정적 변수
* auto duration(자동 주기): 정의되는 시점에서 생성 및 초기화되며, 정의된 블록이 끝나느 지점에서 소멸하는 것
* static duration(정적 주기): 생성된 스코프가 종료한 이후에도 해당 값을 유지하는 변수로 정적 변수는 한 번만 초기화되며 프로그램 수명 내내 지속
  * 지역 변수에 static 키워드를 사용하면 변수는 static duration 특성을 가져 static variable이 됨
```
   void func() {
     static int value = 1; // 이 줄은 한번만 실행됨
     ++value;
     cout << value << endl;
   }
```

