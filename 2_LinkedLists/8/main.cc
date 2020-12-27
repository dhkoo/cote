/* 루프 발견:
 * 순환 연결리스트가 주어졌을 때, 순환되는 부분의 첫번째 노드를 반환하는
 * 알고리즘을 작성하라. 순환 연결리스트란 노드의 next 포인터가 앞선 노드들
 * 가운데 어느 하나를 가리키도록 설정되어 있는, 엄밀히 말해서 변질된 방식의
 * 연결리스트를 의미한다.
 * e.g. input : A->B->C->D->E->C (앞에 나온 C와 같음)
 *      output: C
 */
#include "../linked_list.h"
#include <iostream>
#include <set>

using namespace std;

Node* getCircularNode(LinkedList& list) {
  set<Node*> node_addrs;
  Node* target = list.getHead();
  while (target) {
    if (node_addrs.find(target) != node_addrs.end()) {
      return target;
    }
    node_addrs.insert(target);
    target = target->next;
  }
  return nullptr;
}

int main() {
  LinkedList list;
  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);
  list.pushBack(4);
  list.pushBack(5);

  Node* target = list.getHead();
  Node* loop;
  while (target->next) {
    if (target->data == 3) {
      loop = target; 
    }
    target = target->next;
  }
  target->next = loop;

  auto node = getCircularNode(list);
  if (node) {
    cout << "found circular node! " << node << " " << node->data << endl;
  } else {
    cout << "Not found" << endl;
  }

  return 0;
}
