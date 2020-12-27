/* 스택 정렬:
 * 가장 작은 값이 위로 오도록 스택을 정렬하는 프로그램을 작성하라.
 * 추가적으로 하나 정도의 스택은 사용해도 괜찮지만, 스택에 보관된 요소를
 * 배열 등의 다른 자료구조로 복사할 수 없다. 스택은 push, pop, peek, isEmpty의
 * 네 가지 연산을 제공해야 한다.
 */
#include "../stack.h"
#include <vector>

using namespace std;

void sortStack(Stack& stack) {
  Stack tmp_stack;

  while(!stack.isEmpty()) {
    int value = stack.pop();
    while(!tmp_stack.isEmpty() && tmp_stack.peek() > value) {
      stack.push(tmp_stack.pop());
    }
    tmp_stack.push(value);
  }

  while(!tmp_stack.isEmpty()) {
    stack.push(tmp_stack.pop());
  }
}

int main() {
  Stack s;
  s.push(3);
  s.push(1);
  s.push(2);
  s.push(5);

  sortStack(s);

  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;

  return 0;
}
