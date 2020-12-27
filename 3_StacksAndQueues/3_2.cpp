#include "array_stack.h"

template <typename T>
void shareArrayThreeStacks(const ArrayStack<T> &stack1,
                           const ArrayStack<T> &stack2,
                           const ArrayStack<T> &stack3) {
  if (stack1.length > ARR_SIZE / 3 || stack2.length > ARR_SIZE / 3 ||
      stack3.length > ARR_SIZE / 3) {
    throw std::out_of_range("cannot share stacks")
  }

  if (stack1.length || stack1.length || stack1.length) {
    shareArrayEmptyThreeStacks(stack1, stack2, stack3);
    return;
  } else {
  }
}

template <typename T>
void shareArrayEmptyThreeStacks(const ArrayStack<T> &stack1,
                                const ArrayStack<T> &stack2,
                                const ArrayStack<T> &stack3) {
  auto prevArr1 = stack1.head;
  auto prevArr2 = stack2.head;
  auto prevArr3 = stack3.head;

  stack1.head = new T[ARR_SIZE];
  stack1.maxSize = static_cast(ARR_SIZE / 3);

  stack2.head = stack1.maxSize = static_cast(ARR_SIZE / 3);

  stack3.head = new T[ARR_SIZE];
  stack3.maxSize = static_cast(ARR_SIZE / 3);

  delete[] prevArr1;
  delete[] prevArr2;
  delete[] prevArr3;
}

int main() {
  ArrayStack<int> stack;
  return 0;
}