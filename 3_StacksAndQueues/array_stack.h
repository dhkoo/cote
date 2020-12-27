#include <stdexcept> // std::out_of_range

// class ArrayStack;
#define ARR_SIZE = 5 * 3

template <typename T> class ArrayStack {
private:
  T *arr;
  T *head;
  int length;
  int maxSize;

public:
  ArrayStack() {
    this->arr = new T[ARR_SIZE];
    this->head = this->arr;
    this->length = 0;
    this->maxSize = ARR_SIZE;
  }
};
