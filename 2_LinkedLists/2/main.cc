/* 뒤에서 k번째 원소 구하기:
 * 단방향 연결리스트가 주어졌을 때 뒤에서 k번째 원소를 찾는 알고리즘을 구현하라
 */
#include "../linked_list.h"
#include <iostream>

using namespace std;

void findKthElementFromLast(LinkedList& list, int k) {
  Node* front_pointer = list.getHead();
  Node* back_pointer = list.getHead();
  for (int i = 1; i < k; ++i) {
    if (!front_pointer) {
      cout << "out of bounds" << endl;
      return;
    }
    front_pointer = front_pointer->next;
  }

  while (front_pointer->next) {
    front_pointer = front_pointer->next;
    back_pointer = back_pointer->next;
  }
  cout << back_pointer->data << endl;
}

int main() {
  LinkedList list;
  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);
  list.pushBack(4);
  list.pushBack(5);
  list.pushBack(6);
  list.pushBack(7);

  int k = 3;
  list.showAllData();
  cout << k << "th element from last : ";
  findKthElementFromLast(list, k);

  return 0;
}
