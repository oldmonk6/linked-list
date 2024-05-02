#include<iostream>
using namespace std;
class node
{
    public:
    int val;
    node* next;
    node* prev;
    node(int val)
    {
        this->val=val;
        this->next= NULL;
        this->prev=NULL;
    }
};
class dll{
    public:
    node* head;
    node* tail;
    int size;
    dll()
    {
        head=tail=NULL;
        size=0;

    }
    void insertatend(int val)
    {
        node* temp=new node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
            
        }
        size++;
    }
    void insertathead(int val)
    {
        node* temp=new node(val);
        if(size==0) head=tail=temp;
        else{
           temp->next=head;
           head->prev=temp;
           head=temp;
        }
        size++;
    }
    void insertatindex(int idx,int val)
    {
        if(idx==0) insertathead(val);
        else if(idx==size)insertatend(val);
        else if(idx<0 || idx>=size) cout<<"invalid linked list"<<" ";
        else
        {
            node* temp=new node(val);
            node* t=head;
            for(int i=1;i<=idx-1;i++)
            {
                t=t->next;

            }
            temp->next=t->next;
            t->next=temp;
            temp->prev=t;
            temp->next->prev=temp;
            size++;
            
        }
    }
    

    void display()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int getelement(int idx)
    {
        if(idx==0) return head->val;
        else if(idx==size-1)return tail->val;
        else if(idx<0 || idx>=size) 
        {
          cout<<"invalid";
          return -1;
        }
         else
        {
            if(idx<=size/2)

            {
            node* temp=head;
            for(int i=1;i<=idx;i++)
            {
                temp=temp->next;

            }
            return temp->val;
            }else{
                node*  temp=tail;
                for(int i=size;i>idx;i--)
                {
                    temp=temp->prev;

                }
                return temp->val;
            }
            
        }
    }
    void deleteathead()
    {
        if(size==0)cout<<"list is empty";
        if(size>=1)
        {
            head=head->next;
            if(head!=NULL)head->prev=NULL;
            if(head==NULL)tail=NULL;
            size--;
        }
    }
    void deleteatend()
    {
        if(size==0)
        {
            cout<<"list is empty";
        }
        else if(size==1)
        {
            deleteathead();
            return;
        }
        node* temp=tail->prev;
        temp->next=NULL;
        tail=temp;
        size--;
    }
    void deleteatindex(int idx)
    {
        if(idx==0) deleteathead();
        else if(idx==size-1) deleteatend();
        else if(idx<0 || idx>=size) cout<<"invalid index"<<" ";
        else
        {
            node* temp=head;
            for(int i=1;i<=idx-1;i++)
            {
                temp=temp->next;

            }
            temp->next=temp->next->next;
            temp->next->prev=temp;
            size--;

            
        }
    }
};
int main()
{
    dll list;
    list.insertatend(10);
    list.insertatend(20);
    list.insertatend(30);
    list.display();
    list.insertathead(50);
    list.insertatindex(2,40);
    list.display();
    cout<<list.getelement(0);


}
    


    
    
    


