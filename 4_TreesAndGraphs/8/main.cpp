/* 
* 첫번째 공통 조상
* 이진 트리에서 노드 두 개가 주어졌을 때 이 두 노드의 첫번쨰 공통 조상을 찾는 알고리즘 설계 작성
* 자료 구조 내에 추가로 노드를 저장해주면 안된다. 
* 반드시 이진 탐색 트리일 필요는 없다
*/ 
#include "../tree.h"
#include <vector>

using namespace std;

void preorderTraversal(node *n, vector<int> &record) {
  if (n == nullptr)
    return;
  record.push_back(n->value);
  preorderTraversal(n->lNode, record);
  preorderTraversal(n->rNode, record);
}

node& searchYoungestCommonAncestor(BinaryTree &tree, node &n1, node &n2){

  node* ancestor;
  vector<int> record;
  preorderTraversal(tree.getRoot(), record);

  

  return 

}