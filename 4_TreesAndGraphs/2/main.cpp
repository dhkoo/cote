#include <../tree.h>

node *createMinimalBST(int array[]) {}
node *createMinimalBST(int array[], int start, int end) {
  if (end < start)
    return;

  int mid = (start + end) / 2;
  node *n = new node(array[mid]);
  n->lNode = createMinimalBST(array, start, mid - 1);

  n->rNode = createMinimalBST(array, mid, end);

  return n;
}

int main() { return 0; }