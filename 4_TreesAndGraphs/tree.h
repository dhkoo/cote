#ifndef __GRAPH__
#define __GRAPH__

#include <vector>

struct node {
  node *rNode;
  node *lNode;
  int value;
  node(int val) {
    this->value = val;
    rNode = nullptr;
    lNode = nullptr;
  }
  node(){  
    rNode = nullptr;
    lNode = nullptr;
  };
};

class BinaryTree {
public:
  BinaryTree() : _root(nullptr){};
  ~BinaryTree(){};
  node *getRoot() { return _root; }
  void insert(int val) {
    node *n = new node(val);
    node *tmpRoot = nullptr;
    if (_root == nullptr)
      _root = n;
    else {
      node *ptr = _root;
      while (ptr != nullptr) {
        tmpRoot = ptr;
        if (n->value < ptr->value) {
          ptr = ptr->lNode;
        } else {
          ptr = ptr->rNode;
        }
      } //넣을 위치에 대입
      if (n->value < tmpRoot->value)
        tmpRoot->lNode = n;
      else
        tmpRoot->rNode = n;
    }
  }

private:
  node *_root;
};

class BinarySearchTree {
public:
  BinarySearchTree() : _root(nullptr){};
  ~BinarySearchTree(){};

  void insert(int val) {
    node *n = new node(val);
    node *tmpRoot = nullptr;
    if (_root == nullptr)
      _root = n;
    else {
      node *ptr = _root;
      while (ptr != nullptr) {
        tmpRoot = ptr;
        if (n->value < ptr->value) {
          ptr = ptr->lNode;
        } else {
          ptr = ptr->rNode;
        }
      } //넣을 위치에 대입
      if (n->value < tmpRoot->value)
        tmpRoot->lNode = n;
      else
        tmpRoot->rNode = n;
    }
  }

  node *getRoot() { return _root; }

private:
  node *_root;
};

static void insertLeft(node *n, int val) {
  if (n->lNode != nullptr)
    return;
  node *nn = new node(val);
  n->lNode = nn;
}
static void insertLeft(node *n, node *nn) { n->lNode = nn; }

static void insertRight(node *n, int val) {
  if (n->rNode != nullptr)
    return;
  node *nn = new node(val);
  n->rNode = nn;
}
static void insertRight(node *n, node *nn) { n->rNode = nn; }
#endif