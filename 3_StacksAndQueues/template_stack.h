#ifndef TEMPLATE_STACK_H_
#define TEMPLATE_STACK_H_

#include <cstdint>
#include <sys/types.h>
#include <iostream>

using namespace std;
constexpr size_t STACK_SIZE = 10;

template<typename T>
class TemplateStack {
 public:
  TemplateStack();
  ~TemplateStack();

  void push(T value);
  T pop();
  
  T top() const;
  bool isEmpty() const;
  size_t size() const;

 private:
  int top_;
  size_t size_;

  T* values;

};// class TemplateStack

template<typename T>
TemplateStack<T>::TemplateStack()
    : top_(-1), size_(0), values(new T(STACK_SIZE)) {}

template<typename T>
TemplateStack<T>::~TemplateStack() {
  delete values;
}

template<typename T>
void TemplateStack<T>::push(T value) {
  ++top_;
  ++size_;
  values[top_] = value;
}

template<typename T>
T TemplateStack<T>::pop() {
  --size_; 
  return values[top_--];
}

template<typename T>
T TemplateStack<T>::top() const {
  return values[top_];
}

template<typename T>
bool TemplateStack<T>::isEmpty() const {
  if (!size_) {
    return true;
  }
  return false;
}

template<typename T>
size_t TemplateStack<T>::size() const {
  return size_;
}

#endif  // TemplateStack_H_
