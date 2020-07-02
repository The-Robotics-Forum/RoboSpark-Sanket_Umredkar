#include<stdio.h>


int push(char x , char *arr , int top)
{
    arr[++top] = x ;
    return top;
}


int pop(int top, char *arr)
{
    if(top!=-1)
    {
        
         top = top - 1;
         return top;

    }

    else
    {
        
        return -2;
    }
   


}













int main()
{

    char arr[10];
    int top = -1;

    char expression[10];

    printf("\nEnter the Parenthesis Expression : ");
    scanf("%s",expression);

    for(int i = 0 ; expression[i]!='\0' ; i++)
    {
        if( expression[i]=='(' )
        {   
            top=push(expression[i],arr,top);
        }

        
        else if ( expression[i]==')' )
        {
            top=pop(top,arr);
            if(top==-2)
            {
                break;
            }

        }
        



    }


    if(top==-1)
    {
        printf("\n\nExpression is balanced");

    }

    else
    {
        printf("\n\nExpression is not Balanced");
    }
    
}
