#include<iostream>
using namespace std;
class node
{
    public:
    int val;
    node* next;
    node(int val)
    {
        this->val=val;
        this->next= NULL;
    }
};
class LinkedList{
    public:
    node* head;
    node* tail;
    int size;
    LinkedList()
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
            
            node* temp=head;
            for(int i=1;i<=idx;i++)
            {
                temp=temp->next;

            }
            return temp->val;
            
        }
    }
    void deleteathead()
    {
        if(size==0)cout<<"list is empty";
        if(size>=1)
        {
            head=head->next;
            size--;
        }
    }
    void deleteatend()
    {
        node* temp=head;
        while(temp->next!=tail)temp=temp->next;
        temp->next=NULL;
        tail=temp;
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
            
        }
    }
    


    
    
    

};


int main()
{
   LinkedList ll;
   ll.insertatend(10);
   ll.insertatend(20);
   ll.display();
   ll.insertathead(30);
   ll.display();
   ll.insertatend(40);
   ll.insertatend(50);
   ll.display();
   ll.insertatindex(2,15);
   ll.display();
   cout<<ll.getelement(2)<<endl;
   ll.deleteathead();
   ll.display();
   ll.deleteatend();
   ll.display();
   ll.deleteatindex(2);
   ll.display();
   



   
   

}