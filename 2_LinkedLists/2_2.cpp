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
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.add_node(5);
    node kth = a.getKthNode(3);
    cout << kth.data << endl;
    return 0;
}