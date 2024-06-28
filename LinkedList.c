#include <stdio.h>
#include <stdlib.h>


struct lnode 
{
    int data;
    struct lnode *next;
    
};

typedef struct lnode node;

node *head=NULL;  


 void InsertAtBeginning(int val)
 {
    node *newNode=(node *) malloc (sizeof(node));
    if(newNode==NULL)
    {
        printf("Out of memory");
        return ;
    }
    
    newNode -> data=val;
    if(head==NULL)
    {
        //(*newNode).data=val;
        newNode -> next=NULL;
        head=newNode;
    }
    else
    {
        
        newNode -> next=head;
        head=newNode; // newNode is a pointer
    }
    
    printf(" data %d was entered\n",val);
 }
 
 void Display()
 {
    node *temp=head;
    if(head==NULL)
    {
        printf("----List is empty----\n");
        return ;
    }
    
    printf("Elements in the list are: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
 }
 
 void InsertAtPosition(int pos,int val)
 {
    node *newNode=(node*)malloc(sizeof(node));// it actually return void poiter we change it
    if(newNode==NULL)
    {
        printf("Out of memory\n");
        return;
    }
    
    node *temp=head;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }
    newNode->data=val;
    newNode->next=temp->next;
    temp->next=newNode;
 }
 
 void DeleteFromFirst(int pos)
 {
    node *temp=head;
    if(head==NULL)
    {
        printf("----List is empty----\n");
        return;
    }
    
    head=temp->next;
    temp->next=NULL;
 }
 void DeleteFromPosition(int pos)
 {
    node *temp=head;
    node *curr;
    for(int  i=0;i<pos-1;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Invalid position");
            return;
        }
        
    }
    curr=temp->next;
    temp->next=curr->next;
    curr->next=NULL;
    
    
 }
 
void DeleteFromLast()
{
    node *temp=head;
    node *prev;
    if(head==NULL)
    {
        printf("----List is empty----\n");
        return;
    }
    
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    temp->next=NULL;
    
    //printf("--Element deleted at last--\n");
    
}
 
 
void ReverseList()
{
    node *curr=head;
    node *prev=NULL;
    node *next=head->next;
    
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
       // printf("%d ",curr->data);
        
    }
    head=prev;
    
}
 
int main()
{
    int choice,val=0,pos;
    while(1)
    {
        printf("-----Linked List----\n");
        printf("1.Insert at beginning \n");
        printf("2.display thelist\n");
        printf("3.Insert at position \n");
        printf("4.delete from the position \n");
        printf("5.delete from last\n");
        printf("6.Reverse the link list\n");
        printf("7.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter the data:");
                    scanf("%d",&val);
                    InsertAtBeginning(val);
                    break;
            case 2:
                    Display();
                    break;
            case 3:
                    printf("Enter the position: ");
                    scanf("%d",&pos);
                    printf("Enter the data:");
                    scanf("%d",&val);
                    InsertAtPosition(pos,val);
                    break;
            case 4:
                    
                    printf("Enter the position: ");
                    scanf("%d",&pos);
                    if(pos==0)
                    {
                        DeleteFromFirst(pos);
                        break;
                    }
                    DeleteFromPosition(pos);
                    break;
            case 5:
                    DeleteFromLast();
                    break;
            case 6:
                    ReverseList();
                    Display();
                    break;
            
            case 7:
                    printf("Thank You\n");
                    exit(0);
                    
            default:
                    printf("Enter Valid Choice\n");
                    
        }
        
    }
}



