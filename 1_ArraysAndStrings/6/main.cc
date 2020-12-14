/* 문자열 압축:
 * 반복되는 문자의 개수를 세는 방식의 기본적인 문자열압축 메서드를 작성하라.
 * 예를 들어 문자열 aabccccaaa를 압축하면 a2b1c5a3이 된다.
 * 만약 압축된 문자열의 길이가 기존 문자열의 길이보다 길다면 기존 문자열을
 * 반환해야 한다. 문자열은 대소문자 알파벳으로만 이루어져있다.
 */
#include <iostream>
#include <string>

using namespace std;

void compressString(string& str) {
  string compressed_string = "";
  int cumluated_count = 0;
  for (int i = 0; i < str.length(); i++) {
    cumluated_count++;
    if (str[i] != str[i+1] || i+1 == str.length()) {
      compressed_string += str[i] + to_string(cumluated_count);
      cumluated_count = 0;
    }
  }
  string result =
    compressed_string.length() > str.length() ? str : compressed_string;
  cout << result << endl;
}

int main() {
  string str("aaabbbccd");
  //string str("abc");
  compressString(str);
  return 0;
}
