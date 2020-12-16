#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <cstdint>

typedef struct Node_ {
  Node_* next;
  int data;
} Node;

class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  void pushBack(const int data);
  void remove(const int data);
  void showAllData() const;
  uint32_t getSize() const;

  Node* getHead() const;
  Node* getNode(const int data) const;

 private:
  Node* head_;
  uint32_t size_;
};

#endif  // LINKED_LIST_H_
