/* 접시 무더기
 * SetOfStacks는 여러 개의 스택으로 구성되어 있으며,
 * 이전 스택이 지정된 용량을 초과하는 경우 새로운 스택을 생성해야 한다.
 * push와 pop은 스택이 하나만 있는 경우와 동일하게 동작해야 한다.

*/

#include "stack.h"
#include <vector>

class SetOfStacks {
private:
  std::vector<Stack<int>*> Stacks;
  int numStack;

public:
  SetOfStacks(){
    Stack<int>* stack = new Stack<int>();
    this->Stacks.push_back(stack);
    this->numStack = 1;
  };
  ~SetOfStacks() {}

  void push(int value) {
    int idxStack = 0;
    for (auto stack : this->Stacks) {
      if (stack->isFull()){
        if(idxStack++ == this->numStack){
          Stack<int>* stack = new Stack<int>();
          this->Stacks.push_back(stack);
          ++this->numStack;
        };
        continue;
      }

      else {
        stack->push(value);
      }
    }
  };
  int pop() {
    for (auto stack : this->Stacks) {
      if (stack->isFull())
        continue;

      else {
        int res = stack->pop();
        if(stack->getLength() == 0){
          this->Stacks.pop_back();
          --this->numStack;
        }
        return res;
      }
    }
  };
};

int main(){
  SetOfStacks stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(6);
  stack.push(7);
  stack.push(8);
  return 0;
}