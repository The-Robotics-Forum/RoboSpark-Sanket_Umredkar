#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node
{
    int data;
    node *next;


}node;

//creates new nodes
node *newNode(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;

}

//The data stored in the link list is in ascending order.
//Suitable position of the link to be inserted is determined using this function.

void insertNode(node *n , node* head)
{
    node *temp = head;
    node *prev;
    //cout<<"\nInsert function";
    while (temp->data < n->data)
    {
        prev = temp;
        temp = temp->next;
        //cout<<"\nWhile loop";
    }

    n->next = prev->next;
    prev->next = n;


}

//function to delete a node
void deleteNode(node *n , node *head)
{
   node *temp = head;
   node *prev;

   while(temp!=n)
   {
       prev = temp;
       temp = temp->next;
   }

    prev->next = temp->next;
    temp->next = NULL;
    free(temp);

}






int main ()
{
    
    node *head = newNode(10);
    node *second_link = newNode(20);
    node *third_link = newNode(30);
    node *fourth_link = newNode(50);
    node *user_link = newNode(40);

    head->next = second_link;
    second_link->next = third_link;
    third_link->next = fourth_link;

    node *temp = head;
    
    cout<<"\nOriginal linked list : "<<endl;
    while(temp!=NULL)
    {
        
        cout<<temp->data<<"->";
        temp=temp->next;
    }


    //a node is inserted 
    insertNode(user_link , head);


    cout<<"\nLinked list after insertion of element : "<<endl;
    temp = head;
    while(temp!=NULL)
    {
        
        cout<<temp->data<<"->";
        temp=temp->next;
   
    }

    //a node is deleted  
    deleteNode(second_link , head);

    cout<<"\nLinked list after deletion of element : "<<endl;
    temp = head;
    while(temp!=NULL)
    {
        
        cout<<temp->data<<"->";
        temp=temp->next;
   
    }


}