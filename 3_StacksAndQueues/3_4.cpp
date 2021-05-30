/* 스택으로 큐
* 스택 두개로 큐 하나를 구현한 클래스를 구현하라.
*/

#include "stack.h"

class Queue{
public:
  Queue(){
    this->length = 0;
  };
  ~Queue(){

  };
  void push(int val){
    this->fStack.push(val);
  };

  int pop(){
    if(this->fStack.getLength()!=0){
      return this->fStack.pop();
    }
    else{
      while(this->pStack.getLength()!=1){
        this->fStack.push(this->pStack.pop());
      }
      return this->pStack.pop();
    }
  };
private:
  Stack<int> pStack; 
  Stack<int> fStack;
  int length;
};

int main(){
  Queue queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  
  queue.pop();
  return 0;
}