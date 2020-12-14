# Arrays and Strings
## From 1
## From 2
* 순열 관계의 정의는?
** 두 문자열의 종류와 숫자가 같으면서 배열된 순서가 다른 것
* 순열 관계를 파악에 필요한 세부사항
** 공백 처리, 소문자 대문자의 구분 여부

## From 3
* 공백 비교는 single quote를 사용해야됨 (e.g. str[i] == ' ')
* string, char[] 비교
** 동적배열, 정적배열
** length(), strlen(const char*)

## From 4
* 문자열 공백 제거
** str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
*** algoritm의 remove, remove_if는 삭제를 수행하지 않고 뒤쪽의 요소를 앞쪽으로 덮었 과정을 거치고 무효 영역 시작위치를 return (크기 줄어들지 않음)
*** erase를 통해서 삭제할 영역인 newend ~ end를 제거함

* 어떤 숫자에서 1을 뺀 뒤 AND 연산을 수행했을 때 결과가 0이라면 해당 숫자는 정확히 한 비트만 1로 세팅되었다는 의
* ascii 문자열을 int로 변환 in C++
** int num = static_cast<int>(letter);

## From 5
* In C and in C++ single quotes identify a single character, while double quotes create a string literal. 'a' is a single a character literal, while "a" is a string literal containing an 'a' and a null terminator (that is a 2 char array). 
* string에 char를 insert 하는 방법
** string& insert(size_t pos, const char* s, size_t n)
*** 넣을 char에 대한 주소를 넣어줘야하며 n을 1로 설정하여 해당 주소의 첫번째 char를 넣게한다.

## From 6
* int to string : to_string(int)
* std::string은 str[i+1]에 대해서 범위 고민을 할 필요 없음 (동적 배열)

## From 7
* rotate 알고리즘은 O(n^2)
* n/2가 layer의 수가 됨
* index별로 수행하는 것이 효과적

## From 9
* string의 rotate여부는 기존 string을 두번 반복하여 해당 string에 포함되어 있는지 확인하면됨
* string의 find는 리턴값으로 찾은 문자열을 index를 반환
** 찾는 문자열이 없을땐 string::npos를 반환함
*** if (str.find("abc") == string::npos) return false;
