/* 접시 무더기:
 * 접시 무더기를 생각해 보자. 접시를 너무 높이 쌓으면 무너져 내릴 것이다.
 * 따라서 현실에서는 접시를 쌓다가 무더기 높이가 어느 정도 높아지면 새로운
 * 무더기를 만든다. 이것을 흉내 내는 자료구조 SetOfStacks를 구현해 보라.
 * Setofstacks는 여러 개의 스택으로 구성되어 있으며, 이전 스택이 지정된 용량을
 * 초과하는 경우 새로운 스택을 생성해야 한다. Setofstacks.push()와 
 * setofstacks.pop()은 스택이 하나인 경우와 동일하게 동작해야 한다.
 * (다시 말해, pop()은 정확히 하나의 스택이 있을 때와 동일한 값을 반환해야 함)
 */
#include "../stack.h"
#include <vector>

using namespace std;

constexpr int CAPACITY = 3;

class StackofStacks {
 public:
  StackofStacks()
      : stack_index_(0) {
    Stack* stack = new Stack();
    stacks_.push_back(stack);
  }
  ~StackofStacks() {}

  void push(int value) {
    auto target = stacks_[stack_index_];

    if (target->getSize() == CAPACITY) {
      Stack* stack = new Stack();
      stack->push(value);
      stacks_.push_back(stack);
      ++stack_index_;
    } else {
      target->push(value); 
    }
    cout << "Pushed to stacks" << stack_index_ << endl;
  }

  int pop() {
    auto target = stacks_[stack_index_];
    if (target->getSize() == 1) {
      --stack_index_;
    }
    return target->pop();
  }

 private:
  vector<Stack*> stacks_;
  int stack_index_;
};

int main() {
  StackofStacks stacks;
  stacks.push(1);
  stacks.push(2);
  stacks.push(3);
  stacks.push(4);
  stacks.push(5);
  stacks.push(6);
  cout << stacks.pop() << endl;
  cout << stacks.pop() << endl;
  cout << stacks.pop() << endl;
  cout << stacks.pop() << endl;
  stacks.push(7);
  return 0;
}
