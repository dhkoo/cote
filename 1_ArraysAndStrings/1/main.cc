/* 중복이 없는가:
 * 문자열이 주어졌을 때, 이 문자열에 같은 문자가 중복되어 등장하는지 확인하는
 * 알고리즘을 작성하라.
 * 자료구조를 추가로 사용하지 않고 풀 수 있는 알고리즘 또한 고민하라.
 */
#include <iostream>

using namespace std;

bool isDuplicate(string str) {
  for (int i = 0; i < str.length() - 1; i++) {
    for (int j = i+1; j < str.length(); j++) {
      if (str[i] == str[j]) return true; 
    }
  }
  return false;
}

// ASCII 문자열인 경우를 가정 && 자료구조 이용
// 시간 복잡도 : O(1) 
// 문자 집합의 크기를 미리 정해 놓지 않는 경우 O(min(c,n))
bool isUniqueChars(string str) {
  if (str.length() > 128) {
    return false;
  }
  bool char_set[128] = {false};
  for (int i = 0; i < str.length(); i++) {
    char val = str[i];
    if (char_set[val]) {
      return false;
    }
    char_set[val] = true;
  }

  return true;
}

int main() {
  string str = "abcde";
  if (!isUniqueChars(str)) {
    cout << str << " has unique chars" << endl;
  } else {
    cout << str << " has not unique chars" << endl;
  }
  return 0;
}
