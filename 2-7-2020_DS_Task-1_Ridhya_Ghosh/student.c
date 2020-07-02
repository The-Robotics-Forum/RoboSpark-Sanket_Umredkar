#include<stdio.h>

struct Student
{
    int ID;
    char name[30];
    int year;
    float CGPA;
     

};






int main ()
{
    int choice;

    struct Student s[4];

    for(int i = 0 ; i < 4 ; i++)
    {
        printf("\n\n\nEnter Details of Student %d  :  ",(i+1));

       
        printf("\n\nEnter Name of Student : ");
        gets(s[i].name);

        printf("\nEnter ID of Student : ");
        scanf("%d",&s[i].ID);

        printf("\nEnter Year of Student : ");
        scanf("%d",&s[i].year);

        printf("\nEnter CGPA of Student : ");
        scanf("%f",&s[i].CGPA);

        getchar();



    }



printf("\n\n\n DO YOU WANT TO DISPLAY THE DETAILS OF STUDENTS ? [Y:1 , N:0]");
scanf("%d",&choice);

if(choice==1)
{
    for(int i=0 ; i < 4 ; i++)
{
    printf("\n\n\nDisplaying the results of Student %d : ",(i+1));

    printf("\n\nName of Student : %s",s[i].name);
    printf("\nID of Student is : %d",s[i].ID);
    printf("\nYear of Student is : %d",s[i].year);
    printf("\nCGPA of Student is : %f",s[i].CGPA);

}


}



}