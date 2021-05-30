#include "list.h"


bool naiveCheckPalindrome(const linked_list &list){
  bool res = true;
  auto outIter = list.head;
  for(int curIdx=0; curIdx<list.length()/2 -1 ; curIdx++){
    auto inIter = list.head;
    for(int i = 0;  i < list.length() - curIdx - 1 ; i++){
      inIter = inIter->next;
    }
    if(outIter->data != inIter->data){
      res = false;
      break;
    }
    outIter = outIter->next;
  }
  return res;
}

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(3);
    a.add_node(2);
    a.add_node(1);

    auto res = naiveCheckPalindrome(a); // add 5853 + 169 = 6022 

    return 0;
}