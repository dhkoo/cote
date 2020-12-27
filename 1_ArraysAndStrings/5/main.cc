/* 하나 빼기:
 * 문자열을 편집하는 방법에는 세 가지 종류가 있다.
 * 문자 삽입, 문자 삭제, 문자 교체. 문자열 두 개가 주어졌을 때, 문자열을 
 * 같게 만들기 위해 편집 횟수가 1회 이내인지 확인하는 함수를 작성하라.
 * e.g. pale, ple -> true
 * e.g. pales, pale -> true
 */
#include <iostream>
#include <string>

using namespace std;

bool tryReplace(string& s, string& t) {
  bool can_edit = true;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != t[i]) {
      if (!can_edit) return false;
      else can_edit = false;
    }
  }
  return true;
}

bool tryInsert(string& s, string& t) {
  for (int i = 0; i < t.length(); i++) {
    if (s[i] != t[i]) {
      t.insert(i, &s[i], 1);
      if (s != t) {
        return false;
      } else {
        return true;
      }
    }
  }
  return true;
}

bool canMakeSameInOnce(string s, string t) {
  if (s.length() == t.length()) {
    return tryReplace(s,t);
  } else if (s.length() == t.length() + 1) {
    return tryInsert(s,t);
  } else if (s.length() == t.length() - 1) {
    return tryInsert(t,s);
  }
  return false;
}

int main() {
  string s("pale"), t("bake");
  if (canMakeSameInOnce(s,t)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
