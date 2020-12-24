#include "./stack.h"

Stack::Stack() 
    : top_(-1), size_(0), values_(new int[STACK_SIZE]) {}

Stack::~Stack() {}

void Stack::push(int value) {
  values_[++top_] = value;
  ++size_;
}

int Stack::pop() {
  if (!size_) {
    return NULL;
  }
  --size_;
  return values_[top_--];
}

int Stack::peek() {
  return values_[top_];
}

int Stack::getTop() const {
  return top_;
}

bool Stack::isEmpty() const {
  if (!size_) {
    return true;
  }
  return false;
}

size_t Stack::getSize() const {
  return size_;
}
