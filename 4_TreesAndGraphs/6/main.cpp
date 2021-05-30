#include "../tree.h"
#include <algorithm>
#include <vector>

using namespace std;
void inorderTraversal(node *n, vector<int> &record);

int findSuccessor(node *n) {
  vector<int> record;
  inorderTraversal(n, record);
  auto iter = find(record.begin(), record.end(), n->value);

  return *(++iter);
}

void inorderTraversal(node *n, vector<int> &record) {
  if (n == nullptr)
    return;
  inorderTraversal(n->lNode, record);
  record.push_back(n->value);
  inorderTraversal(n->rNode, record);
}

int main() {
  BinaryTree *tree = new BinaryTree();
  tree->insert(8);
  tree->insert(4);
  tree->insert(2);
  tree->insert(10);
  tree->insert(20);

  insertRight(tree->getRoot()->lNode, 12);

  auto res = findSuccessor(tree->getRoot());

  return 0;
}