#ifndef STACK_H_
#define STACK_H_

#include <cstdint>
#include <sys/types.h>
#include <iostream>

using namespace std;

constexpr size_t STACK_SIZE = 100;

class Stack {
 public:
  Stack();
  ~Stack();

  virtual void push(int value);
  virtual int pop();
  int peek();
  
  int getTop() const;
  bool isEmpty() const;
  size_t getSize() const;
  int* getValues() { return values_; }

 private:
  int top_;
  size_t size_;

  int* values_;
};// class Stack

#endif  // Stack_H_
