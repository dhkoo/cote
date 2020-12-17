#include "list.h"

void addLists(const linked_list& li1, const linked_list& li2, linked_list& res){
  bool isOneLong = li1.length() >= li2.length() ? true : false;
  const linked_list* longList = nullptr;
  const linked_list* shortList = nullptr;
  if(isOneLong){
    longList = &li1;
    shortList = &li2;
  }
  else{
    longList = &li2;
    shortList = &li1;
  }

  auto iterLong = longList->head;
  auto iterShort = shortList->head;
  int dividen = 0;
  while(iterLong!=nullptr){
    if(iterShort->next==nullptr) delete iterShort; 
    const int add = iterLong->data + iterShort->data + dividen;
    dividen = add/10;
    const int reminder = add%10;

    res.add_node(reminder);

    iterLong = iterLong->next;
    if(iterShort != shortList->tail){
       iterShort = iterShort->next;
    }
    else iterShort = new node(0,nullptr); // free 시켜야 하는데..
  }
};

int main()
{
    linked_list a,b,c;
    a.add_node(3);
    a.add_node(5);
    a.add_node(8);
    a.add_node(5);
    b.add_node(9);
    b.add_node(6);
    b.add_node(1);

    addLists(a,b,c); // add 5853 + 169 = 6022 

    return 0;
}