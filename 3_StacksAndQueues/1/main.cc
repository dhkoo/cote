/* 한 개로 세 개:
 * 배열 한 개로 스택 세 개를 어떻게 구현할지 설명하라
 */
#include "../stack.h"

using namespace std;

// 3개의 top_, size_를 구성하여 관리

int main() {
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  return 0;
}
