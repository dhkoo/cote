/*
 * 이진 트리가 있을때 linked list로 표현하라
 */

#include "../tree.h"
#include <vector>

using namespace std;
vector<int> *toVector(BinarySearchTree &tree);
void toVector(node *n, vector<int> *vec);

vector<int> *toVector(BinarySearchTree &tree) {
  vector<int> *vec = new vector<int>();
  toVector(tree.getRoot(), vec);
  return vec;
}
void toVector(node *n, vector<int> *vec) {
  if (n == nullptr) {
    return;
  }

  vec->push_back(n->value);

  toVector(n->lNode, vec);
  toVector(n->rNode, vec);
}

int main() {
  BinarySearchTree tree;
  tree.insert(3);
  tree.insert(1);
  tree.insert(5);

  tree.insert(7);
  tree.insert(4);

  auto res = toVector(tree);

  return 0;
}