/* 스택 정렬
 * 스택하나만 사용하여 오름차순 정렬
 * 잘 모르겠어서 답지를 보고 짬
 */

#include "stack.h"

void sort(Stack<int>& stack){
  Stack<int> temp;

  while(!stack.isEmpty()) {
    int value = stack.pop();
    while(!temp.isEmpty() && temp.peek() > value) {
      stack.push(temp.pop());
    }
    temp.push(value);
  }

  while(!temp.isEmpty()) {
    stack.push(temp.pop());
  }
}

int main(){
  Stack<int> stack;
  stack.push(4);
  stack.push(2);
  stack.push(1);
  stack.push(2);
  stack.push(6);

  sort(stack);
  
  return 0;
}