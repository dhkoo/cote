#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }
    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = nullptr;

        if(head == nullptr)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    const node& getKthNode(const int k){
      const int size = (tail-head+2)/2; // 수정 보완 필요
      const node* ptr = head;
      for(int i=0; i<size-k ; i++){
        ptr = ptr->next;
      }
      return *ptr;
    }

    void deleteCenterNode(){
      const int middleIndex = ((tail-head+2)/2)/2;
      node* beforeDeleteNode = head;
      for(int i=1 ; i<middleIndex-1 ; i++){
        beforeDeleteNode = beforeDeleteNode->next;
      }
      node* deleteNode = beforeDeleteNode->next;
      beforeDeleteNode->next = (deleteNode->next);
      deleteNode->next = nullptr;
      deleteNode = nullptr;
    }

    void partition(int threshold){
      node* cursor = head;
      node* current = cursor;
      node* next = nullptr;
      
      if(current->data>=threshold){
          head = current->next;
          tail->next = current;
          tail = tail->next; 
      }
      node* end = tail;  
      for(; cursor != end ;){
        current = cursor;
        next = cursor->next;
        if(next->data>=threshold){ 
          // 맨 뒤로 보내기 
          current->next = next->next;
          tail->next = next;
          tail = tail->next;
          tail->next = nullptr;
          cursor=current;
        }
        else
          cursor=current->next;

      }

    }
};

int main()
{
    linked_list a;
    a.add_node(3);
    a.add_node(5);
    a.add_node(8);
    a.add_node(5);
    a.add_node(10);
    a.add_node(2);
    a.add_node(1);

    a.partition(5);
    return 0;
}