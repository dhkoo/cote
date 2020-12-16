/* 중간 노드 삭제:
 * 단방향 연결리스트가 주어졌을 때 중간에 있는 노드 하나를 삭제하는 
 * 알고리즘을 구현하라. 단, 삭제할 노드에만 접근할 수 있다.
 */
#include <iostream>
#include <list>

using namespace std;

void removeElement(list<int>& list, int element) {
  for (auto iter = list.begin(); iter != list.end(); ++iter) {
    if (*iter == element) {
      list.erase(iter);
      break;
    }
  }
  for (auto elem : list) {
    cout << elem << " ";
  }
  cout << endl;
}

//// Right approach
typedef struct Node_ {
  Node_* next;
  int data;
} Node;

Node head = {nullptr, 0};

void deleteNode(Node* target) {
  if (!target) {
    return;
  }

  Node* next_node = target->next;

  target->data = next_node->data;
  target->next = next_node->next;

  if (next_node) {
    delete(next_node);
  }
}
//////////////////

int main() {
  list<int> list {1,2,3,4,5,6,7};
  int element = 3;

  removeElement(list, element);

  return 0;
}
