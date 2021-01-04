/* 최소 트리:
 * 오름차순으로 정렬된 배열이 있다. 이 배열 안에 들어 있는 원소는 정수이며
 * 중복된 값이 없다고 했을 때 높이가 최소가 되는 이진 탐색 트리를 만드는
 * 알고리즘을 작성하라.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct Node_ {
  int value;
  struct Node_* left;
  struct Node_* right;
} Node;

Node* makeBinarySearchTree(vector<int>& v, int start, int end) {
  if (end < start) {
    return nullptr;
  }
  int mid = (start + end) / 2;
  Node* node = new Node();
  node->value = v[mid];
  node->left = makeBinarySearchTree(v, start, mid - 1);
  node->right = makeBinarySearchTree(v, mid + 1, end);
  return node;
}

void inorder(Node* current) {
	if (current != nullptr) {
		inorder(current->left);
		cout << current->value << " ";
		inorder(current->right);
	}
}

int main() {
  vector<int> v {1,2,3,4,5,6,7,8,9,10};
  Node* tree = makeBinarySearchTree(v, 0, 9);
	inorder(tree);
	cout << endl;
  return 0;
}
