/*
 * 주어진 트리가 균형인지 판단
 */

#include "../tree.h"

int getHeightDiff(node *n);
bool isBalanced(node *n);
bool isBalanced(BinarySearchTree &tree) { isBalanced(tree.getRoot()); }

bool isBalanced(node *n) {
  if (n == nullptr)
    return true;

  if (getHeightDiff(n) > 1)
    return false;

  return isBalanced(n->lNode) && isBalanced(n->rNode);
}

int getHeightDiff(node *n) {
  int leftHeight = 0;
  int rightHeight = 0;

  // left
  node *cur = n;
  while (cur == nullptr) {
    ++leftHeight;
    cur = cur->lNode;
  }

  // right
  cur = n;
  while (cur == nullptr) {
    ++rightHeight;
    cur = cur->rNode;
  }

  return leftHeight - rightHeight;
}

int main() {
  BinarySearchTree tree;
  tree.insert(3);
  tree.insert(1);
  tree.insert(5);

  tree.insert(7);
  tree.insert(4);

  return 0;
}