#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Student
{
    string name;
    int id;
    int roll_no;

    int *marks = new int[5];
    float cgpa;

    public:

    //default constructor
    Student()
    {
        name = '\0';
        id = 0;
        roll_no = 0;
        cgpa = 0;
        cout<<"\n\n Default Constructor called"<<endl;
    }

    //parameterized constructor
    Student(string n , int rno , int idn)
    {
        name = n;
        id = idn;
        roll_no = rno;
        cgpa = 9;
        cout<<"\n\n Parameterized constructor called"<<endl;

    }

    //function to get data from user
    void getdata()      
    {
        cout<<"\n\nEnter name of student : ";
        cin>>name;
        cout<<"Enter ID of student : ";
        cin>>id;
        cout<<"Enter roll no. of student : ";
        cin>>roll_no;

        for(int i = 0 ; i<5 ; i++)
        {
            cout<<"Enter marks of subject "<<i+1<<" : ";
            cin>>marks[i];

        }
    }

    //function to display the data
    void showdata()
    {
        cout<<"\n\nName of Student : "<< name << endl;
        cout<<"ID of Student : "<< id << endl;
        cout<<"Roll no. of Student : "<< roll_no << endl;

        for (int i =0 ; i<5 ; i++)
        {
            cout<<"Marks of subject "<< (i+1) <<" : "<< marks[i]<< endl;
        }

        cout<<"CGPA of student is : "<<calculate();


    }

    //function to calculate total marks
    int sum()
    {   int total = 0;
        for (int i = 0 ; i<5 ; i++)
        {
            total = total + marks[i];
        }

        return total;

    }



    //function to calculate cgpa
    float calculate()
    {
        float avg;

        avg = float(sum()/5);
        cgpa = avg/10;

        return cgpa;

        

    }

    //Deallocating Dynamically Allocated Memory
    void free_memory()
    {
        free(marks);
        cout<<"\n\n\nMarks of Student have been cleared and memory has been freed";
    }

   
};


//function overloading

void showRank(int rnk)
{
        cout<<"\n\nRank : "<<rnk<< endl;
}

void showRank( Student s)
{
    s.showdata();
    cout<<"\nNo Rank"<<endl;

}

void showRank( Student s , int rnk)
{
    s.showdata();
    cout<<"\nRank : "<<rnk<< endl;
}





int main ()
{
    
    Student s1;
    Student s2("Ridzz",28,1001);

    s1.getdata();
    //s1.showdata();


    cout<<"\nFunc 1 : ";
    showRank(5);
    
    cout<<"\nFunc 2 : ";
    showRank(s1);

    cout<<"\nFunc 3 : ";
    showRank(s1,5);

    s1.free_memory();


}