#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node *newnode(int data)
{

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;

}


struct node *insert(struct node *root , int x)
{
    if(root==NULL)
    {   printf("\nNew node has been inserted");
        return newnode(x);
    }

    else if( x > root->data )
    {
        root->right = insert(root->right,x);
    }

    else if( x < root->data )
    {
        root->left = insert( root->left,x);
    }


    return root;
}


void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

}



void search(struct node *root , int x)
{
    if(root == NULL)
    {
        printf("It is not in the tree");
        //return root;
    }

    if( x > root->data )
    {
        search(root->right , x);
    }

    if( x < root->data )
    {
        search(root->left , x);
    }

    if( x == root->data)
    {   printf("\nIt is in the tree");
        //return root;
    }






}

int main ()
{
    int sear;
    int new;

    struct node *n1 = newnode(1);
    struct node *n3 = newnode(3);
    struct node *n4 = newnode(4);
    struct node *n5 = newnode(5);
    struct node *n6 = newnode(6);
    struct node *n7 = newnode(7);
    struct node *n10 = newnode(10);
    struct node *n11 = newnode(11);
    struct node *n12 = newnode(12);


    n10->left = n6;
    n10->right = n12;

    n6->right = n7;
    n6->left = n3;

    n3->left = n1;
    n3->right = n4;

    n4->right = n5;


    
    printf("\nPostOrder ------>   ");
    postorder(n10);

    printf("\n\nEnter the number you want to search for in the tree : ");
    scanf("%d",&sear);

    search(n10,sear);


    printf("\n\nEnter a new node : ");
    scanf("%d",&new);

    insert(n10,new);

   

    
    



}