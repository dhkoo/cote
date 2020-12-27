/* 교집합:
 * 단방향 연결리스트 두 개가 주어졌을 때 이 두 리스트의 교집합 노드를 찾은 뒤
 * 반환하는 코드를 작성하라. 여기서 교집합이란 노드의 값이 아니라 노드의 주소가
 * 완전히 같은 경우를 말한다. 즉, 첫 번째 리스트에 있는 k번째 노드와 두 번째
 * 리스트에 있는 j번째 노드가 주소까지 완전히 같다면 이 노드는 교집합의
 * 원소가 된다.
 */
#include "../linked_list.h"
#include <iostream>
#include <set>

using namespace std;

Node* getIntersectionNode(LinkedList& list1, LinkedList& list2) {
  set<Node*> node_addr;
  Node* target = list1.getHead();
  while (target) {
    node_addr.insert(target);
    target = target->next;
  }

  target = list2.getHead();
  while(target) {
    if (node_addr.find(target) != node_addr.end()) {
      return target;
    }
    target = target->next;
  }
  return nullptr;
}

void combineList(Node* src_head, Node* tar_head) {
  Node* target = src_head;
  while (target->next) {
    target = target->next;
  }
  target->next = tar_head;
}

int main() {
  LinkedList list1, list2, common;
  list1.pushBack(3);
  list1.pushBack(1);
  list1.pushBack(5);
  list1.pushBack(9);

  list2.pushBack(4);
  list2.pushBack(6);

  common.pushBack(7);
  common.pushBack(2);
  common.pushBack(1);

  combineList(list1.getHead(), common.getHead());
  combineList(list2.getHead(), common.getHead());
  list1.showAllData();
  list2.showAllData();

  auto intersection_node = getIntersectionNode(list1, list2);
  if (intersection_node) {
    cout << "intersection node addr : " << intersection_node << endl;
    cout << "intersection node data: " << intersection_node->data << endl;
  } else {
    cout << "No intersection node" << endl;
  }

  return 0;
}
