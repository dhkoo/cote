/* 리스트의 합:
 * 연결리스트로 숫자를 표현할 때 각 노드가 자릿수 하나를 가리키는 방식으로
 * 표현할 수 있다.각 숫자는 역순으로 배열되어 있는데, 즉, 첫번째 자릿수가
 * 리스트의 맨 앞에 위치하도록 배열된다는 뜻이다. 이와 같은 방식으로 표현된
 * 숫자 두 개가 있을 때, 이 두 수를 더하여 그 합을 연결리스트로 반환하는
 * 함수를 작성하라.
 * e.g. input : (7->1->6) + (5->9->2) = 617 + 295
 *      output: 2->1->9 = 912
 */
#include "../linked_list.h"
#include <iostream>
#include <cmath>

using namespace std;

int convertListToNum(const LinkedList& list) {
  int num = 0, count = 0;
  Node* target = list.getHead();
  while (target) {
    num += target->data * pow(10, count);
    ++count;
    target = target->next;
  }
  return num;
}

LinkedList sumList(const LinkedList& list1, const LinkedList& list2) {
  LinkedList list;
  int sum = 0;
  sum = convertListToNum(list1) + convertListToNum(list2);

  while (sum) {
    list.pushBack(sum % 10);
    sum /= 10;
  }
  return list;
}

int main() {
  LinkedList list1, list2;
  list1.pushBack(7);
  list1.pushBack(1);
  list1.pushBack(6);

  list2.pushBack(5);
  list2.pushBack(9);
  list2.pushBack(2);

  list1.showAllData();
  list2.showAllData();

  LinkedList result = sumList(list1, list2);
  cout << "output : ";
  result.showAllData();

  return 0;
}
