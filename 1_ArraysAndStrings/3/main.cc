/* URLify:
 * 문자열에 들어 있는 모든 공백을 '%20'으로 바꾸는 메서드를 작성하라.
 * 최종적으로 모든 문자를 다 담을 수 있을 만큼 충분한 공간이 이미 확보되어
 * 있으며 문자열의 최종 길이가 함께 주어진다고 가정해도 된다.
 */
#include <iostream>

using namespace std;

void URLify(string str) {
  string uri;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      uri += "%20";
    } else {
      uri += str[i];
    }
  }
  cout << str << " => " << uri << endl;
}

int main() {
  string str("abcd e f");
  URLify(str);
  return 0;
}
