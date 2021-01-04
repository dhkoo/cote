/* 깊이의 리스트:
 * 이진 트리가 주어졌을 때 같은 깊이에 있는 노드를 연결리스트로 연결해주는
 * 알고리즘을 설계하라.
 * 즉, 트리의 깊이가 D라면 D개의 연결리스트를 만들어야 한다.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef struct Node_ {
  int data;
  struct Node_* left;
  struct Node_* right;
} Node;

void makeGroupAtSameDepth(Node* tree, unordered_map<int, vector<int>>& map, int depth) {
  if (!tree) {
    return;
  }
  Node* current = tree;
  if (map.find(depth) != map.end()) {
    
  }
  vector<int> list;
  list.push_back(tree->data);
  map[depth++] = 
  if (current != nullptr) {
     
  }
}

int main() {
  Node root, node1, node2, node3, node4;
  root.data = 0;
  root.left = &node1;
  root.right = &node2;

  node1.data = 1;
  node1.left = &node3;
  node1.right = &node4;

  node2.data = 2;
  node2.left = nullptr;
  node2.right = nullptr;

  unordered_map<int, vector<int>> map; 
  makeGroupAtSameDepth(&root, map, 0);

  return 0;
}
