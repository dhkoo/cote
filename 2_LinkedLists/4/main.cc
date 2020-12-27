/* 분할:
 * 값 x가 주어졌을 때 x보다 작은 노드들을 x보다 크거나 같은 노드들보다
 * 앞에 오도록 하는 코드를 작성하라. 만약 x가 리스트에 있다면 x는 그보다
 * 작은 원소들보다 뒤에 나오기만 하면 된다. 즉, 원소 x는 '오른쪽 그룹'
 * 어딘가에만 존재하면 된다. 왼쪽과 오른쪽 그룹 사이에 있을 필요는 없다.
 * e.g. input : 3->5->8->5->10->2->1 [분할값 x = 5]
 *      output: 3->1->2->10->5->5->8
 */
#include "../linked_list.h"
#include <iostream>

using namespace std;

void divideList(LinkedList* list, int division_value) {
  LinkedList left, right;

  Node* target = list->getHead();
  while (target) {
    if (target->data < division_value) {
      left.pushBack(target->data);
    } else {
      right.pushBack(target->data);
    }
    target = target->next;
  }
  left.showAllData();
  right.showAllData();
}

int main() {
  LinkedList list;
  list.pushBack(3);
  list.pushBack(5);
  list.pushBack(8);
  list.pushBack(5);
  list.pushBack(10);
  list.pushBack(2);
  list.pushBack(1);
  
  list.showAllData();

  int division_value = 5;
  divideList(&list, division_value);

  return 0;
}
