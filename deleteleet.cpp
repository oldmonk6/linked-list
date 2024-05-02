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
void display(node *head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}
void deletenode(node* head,node *target){
    if(head==target){
        node* t= head;
        t->next=NULL;


        head=head->next;
        
    }
    else
    {
    
   
     node* temp=head;
     while(temp->next!=target)
     {
        temp=temp->next;


     }
     temp->next=target->next;
    }


}

int main()
{
   node *a= new node(10);
   node *b= new node(20);
   node *c= new node(30);
   node *d= new node(40);
   node *e= new node(50);
   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;
   display(a);
   deletenode(a,a);
   display(a);






}