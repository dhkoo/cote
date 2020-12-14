/* 순열 확인:
 * 문자열 두 개가 주어졌을 때 이 둘이 서로 순열 관계에
 * 있는지 확인하는 메서드를 작성하라
 */
#include <iostream>
#include <algorithm>

using namespace std;

bool isPermutation(string s, string t) {
  if (s.length() != t.length()) {
    return false;
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  for (int i = 0 ; i < s.length(); i++) {
    if (s[i] != t[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string s("abc"), t("cba");
  if (isPermutation(s,t)) {
    cout << "perpumated" << endl;
  } else {
    cout << "not perpumated" << endl;
  }
  return 0;
}
