#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
   char name[30];
   int roll_no;

}stud;


typedef struct Queue
{   
    int front;
    int rear;
    stud arr[10];
    
}queue;


void init(queue *q)
{
    q->front=0;
    q->rear=0;
}

void enqueue(queue *q, stud s)
{
    q->arr[q->rear++]= s;
    

}

stud dequeue(queue *q)
{
    return q->arr[q->front++];
}


int isEmpty(queue *q)
{
    return q->front == q->rear;
}





int main ()
{

    stud s[4];

    
    queue *q1 = (queue*)malloc(sizeof(queue));

    init(q1);
    
    
    
    
    
    
    for(int i=0 ; i < 2 ; i++)
    {
        printf("\n\n\nEnter details of Student %d : ",(i+1));

        printf("\n\nEnter name of Student : ");
        gets(s[i].name);

        printf("\nEnter roll no. of Student : ");
        scanf("%d",&s[i]);

        getchar();
    }
    

    for(int i=0 ; i<2 ; i++)
    {

        if((s[i].roll_no%2==0))
        {
            enqueue(q1,s[i]);
            printf("Details of Student %d have been pushed into the queue ",(i+1));

        }

    }

    printf("\n\n");

    



}