#include <stdexcept> // std::out_of_range

template <typename T> class Node {
public:
  T data;
  Node<T> *prev;
  Node(T data) {
    this->data = data;
    this->prev = nullptr;
  }
};

template <typename T> class Stack {
private:
  Node<T> *top;
  int length;
  int maxSize;

public:
  Stack() {
    this->top = nullptr;
    this->length = 0;
    this->maxSize = 5;
  }
  void push(T item) {
    Node<T> *node = new Node<T>(item);

    if (this->top == nullptr) {
      this->top = node;
    } else {
      node->prev = top;
      this->top = node;
    }
    this->length++;
    return;
  }
  T pop() {
    if (top == nullptr)
      throw std::out_of_range("empty");
    else {
      Node<T> *rItem = this->top;
      T rData = rItem->data;
      this->top = rItem->prev;
      delete rItem;
      --this->length;
      return rData;
    }

  }
  bool isEmpty(){
    if(this->length==0) 
      return 1; 
    return 0;
  }
  T peek(){
    return this->top->data;
  }
  int getLength() { return this->length; }
  bool isFull() { return this->length == maxSize ? true : false; }
};
