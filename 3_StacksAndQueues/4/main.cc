/* 스택으로 큐:
 * 스택 두 개로 큐 하나를 구현한 MyQueue 클래스를 구현하라.
 */
#include "../stack.h"
#include <vector>

using namespace std;

class MyQueue {
 public:
  MyQueue() {}
  ~MyQueue() {}

  void push(int value) {
    in_.push(value);
  }

  void pop() {
    if (!out_.getSize()) {
      if (!in_.getSize()) {
        cout << "Empty queue" << endl;
        return;
      }
      int count = in_.getSize();
      for (int i = 0; i < count; ++i) {
        out_.push(in_.pop());
      }
    }
    out_.pop();
  }

  int front() {
    if (!out_.getSize()) {
      if (!in_.getSize()) {
        cout << "Empty queue" << endl;
        return NULL;
      }
      int count = in_.getSize();
      for (int i = 0; i < count; ++i) {
        out_.push(in_.pop());
      }
    }
    auto values = out_.getValues();
    return values[out_.getTop()];
  }

 private:
  Stack in_, out_;
};

int main() {
  MyQueue queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);
  queue.pop();
  queue.pop();
  cout << queue.front() << endl;
  return 0;
}
