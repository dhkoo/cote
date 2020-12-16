/* 회문:
 * 주어진 연결리스트가 회문(palindrome)인지 검사하는 함수를 작성하라.
 */
#include "../linked_list.h"
#include <iostream>
#include <vector>

using namespace std;

bool isListPalindrome(const LinkedList& list) {
  vector<int> vec;

  Node* target = list.getHead();
  while (target) {
    vec.push_back(target->data);
    target = target->next;
  }
  auto iter = vec.begin();
  auto riter = vec.rbegin();

  for (int i = 0; i < list.getSize()/2; ++i) {
    if (*iter != *riter) {
      return false;
    }
    ++iter;
    ++riter;
  }
  return true;
}

int main() {
  LinkedList list;
  list.pushBack(0);
  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(1);
  list.pushBack(0);

  if (isListPalindrome(list)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
