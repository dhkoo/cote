/* 스택 Min:
 * 기본적인 push와 pop 기능이 구현된 스택에서 최솟값을 반환하는 min 함수를
 * 추가하려고 한다. 어떻게 설계할 수 있겠는가? push, pop, min 연산은 모두
 * O(1) 시간에 동작해야 한다.
 */
#include "../stack.h"
#include <vector>

using namespace std;

class StackGetMin : public Stack {
 public:
  StackGetMin() {}
  ~StackGetMin() {}

  void push(int value) override {
    int top = getTop();
    if (!getSize()) {
      min_values_.push_back(value);
    } else {
      min_values_[top + 1] =
        min_values_[top] > value ? value : min_values_[top];
    }

    Stack::push(value);
  }

  int getMinimumValue() {
    return min_values_[getTop()]; 
  }

 private:
  vector<int> min_values_;

};

int main() {
  StackGetMin stack;
  stack.push(5);
  stack.push(8);
  stack.push(2);
  stack.pop();
  cout << stack.getMinimumValue() << endl;
  return 0;
}
