/* 회문순열:
 * 주어진 문자열이 회문(palindrome)의 순열인지 아닌지 확인하는 함수를 작성하라.
 * 회문이란 앞으로 읽으나 뒤로 읽으나 같은 단어 혹은 구절을 의미하며,
 * 순열리안 문자열을 재배치하는 것을 뜻한다.
 */
#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
  sort(str.begin(), str.end());
  str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());

  int unique_char_count = str.length() % 2 == 0 ? 0 : 1;
  int i = 0;
  while (str.length() > i) {
    if (str[i] == str[i+1]) {
      i += 2;
    }
    else {
      if (!unique_char_count) {
        return false;
      }
      else {
        unique_char_count--;
        i++;
      }
    }
  }
  return true;
}

int main() {
  string str("tactcoapapa");
  if (isPalindrome(str)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
