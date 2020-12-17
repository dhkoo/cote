
struct node
{
    int data;
    node *next;
    node(){};
    node(int d, node* n){
      data = d;
      next = n;
    };
};

class linked_list
{
private:
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
    int length() const{
      int res = 0;
      auto iter = head;
      for(; iter != tail ; iter=iter->next){
        res++;
      }
      return res;
    }
    
    node *head,*tail;
};