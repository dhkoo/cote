#include "../tree.h"
bool isBST(node *node, int min, int max);
bool isBST(BinaryTree *tree) { return isBST(tree->getRoot(), -1, -1); };
bool isBST(node *node, int min, int max) {
  if (node == nullptr)
    return true;

  if (((min != -1) && (node->value <= min)) ||
      ((max != -1) && (node->value >= max)))
    return false;

  if (!(isBST(node->lNode, min, node->value) &&
        isBST(node->rNode, node->value, max)))
    return false;

  return true;
};

int main() {
  BinaryTree *tree = new BinaryTree();
  tree->insert(8);
  tree->insert(4);
  tree->insert(2);
  tree->insert(10);
  tree->insert(20);

  insertRight(tree->getRoot()->lNode, 12);

  bool res = isBST(tree);

  return 0;
}