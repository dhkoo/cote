#include "linked_list.h"

#include <iostream>

using namespace std;

LinkedList::LinkedList()
    : head_(nullptr), size_(0) {}

LinkedList::~LinkedList() {
//  Node* target;
//  while (head_) {
//    target = head_;
//    head_ = head_->next;
//    delete(target); 
//  }
}

void LinkedList::pushBack(const int data) {
  Node* node = new Node;
  node->next = nullptr;
  node->data = data;

  if (size_ == 0) {
    head_ = node;
  } else {
    Node* target = head_;
    while (target->next) {
      target = target->next;
    }
    target->next = node;
  }

  ++size_;
}

void LinkedList::remove(const int data) {
  if (!head_) {
    return;
  }

  if (head_->data == data) {
    delete(head_);
    head_ = nullptr;
  } else {
    Node* target = head_;
    while (target->next) {
      if (target->next->data == data) {
        break;
      }
      target = target->next;
    }
    target->next = target->next->next;
    delete(target->next);
  }

  --size_;
}

void LinkedList::showAllData() const {
  if (!head_) {
    cout << "empty" << endl;
  }

  Node* target = head_;
  while (target) {
    cout << target->data << " ";
    target = target->next;
  }
  cout << endl;
}

uint32_t LinkedList::getSize() const {
  return size_;
}

Node* LinkedList::getHead() const {
  return head_;  
}

Node* LinkedList::getNode(const int data) const {
  Node* target = head_;
  while (target) {
    if (target->data == data) {
      return target;
    }
    target = target->next;
  }
  return nullptr;
}
