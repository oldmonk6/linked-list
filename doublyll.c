#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node_t
{
    int data;
    struct  node_t *prev;
    struct node_t *next;
}node;

typedef struct linked_list
{
    node *head;
    int length;
}ll;
ll global;



void insertatfront( node*nn)
{
    
    node* temp=nn;
    temp->next=global.head;
    (global.head)->prev=temp;
    global.head=temp;
    (global.length)++;
    free(temp);
}
void insertatback(node *nn)
{
    node*temp=global.head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=nn;
    nn->prev=temp;
    (global.length)++;
    free(temp);

    
}
void insertatpos(node* nn,int pos)

{
    if(pos==0)insertatfront(nn);
    else if(pos==(global.length)-1)insertatback(nn);
    else
    {
        node*temp=global.head;
        
        for(int i=0;i<pos;i++)
        {
            temp=temp->next;

        }
        node* ptr=temp->next;
        nn->next=ptr;
        ptr->prev=nn;
        temp->next=nn;
        nn->prev=temp;
        (global.length)++;
        free(temp);
        free(ptr);


    }

}

