#include<bits/stdc++.h>
using namespace std;

class Personal
{
    protected:
    string first_name , last_name;
    string address;
    string mob_no;
    string dob;


    public:

    //default constructor
    Personal()
    {
        first_name = '\0';
        last_name = '\0';
        address = '\0';
        dob = '\0';
        mob_no = '\0';

    }

    //parameterized constructor
    Personal ( string first_name , string last_name , string address , string dob , string mob_no)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->address = address;
        this->dob = dob;
        this->mob_no = mob_no;
    }


    void getPersonalData();
    void showPersonalData();

};

void Personal :: getPersonalData()
{
    cout<<"\n\nEnter first name : ";
    cin>>first_name;

    cout<<"\nEnter last name : ";
    cin>>last_name;

    cout<<"\nEnter address : ";
    cin>>address;

    cout<<"\nEnter DOB : ";
    cin>>dob;

    cout<<"\nEnter mobile no. : ";
    cin>>mob_no;
}

void Personal :: showPersonalData()
{
    cout<<"\n\nPersonal Details : "<<endl;
    cout<<"First Name : "<<first_name<<" Last Name : "<<last_name<<endl;
    cout<<"Address : "<<address<<endl;
    cout<<"DOB : "<<dob<<endl;
    cout<<"Mobile Number : "<<mob_no<<endl;

}








class Professional
{
    protected :
    string name_of_org;
    string job;
    string project;

    public:

    //default constructor
    Professional()
    {
        name_of_org = '\0';
        job = '\0';
        project = '\0';
    }

    //parameterized constructor
    Professional(string name_of_org , string job , string project)
    {
        this->name_of_org = name_of_org;
        this->job = job;
        this->project = project;
    }

    void getProfessionalData();
    void showProfessionalData();


};


void Professional :: getProfessionalData()
{
    cout<<"\n\nEnter Name of organization : ";
    cin>>name_of_org;

    cout<<"\nEnter Job Profile : ";
    cin>>job;

    cout<<"\nEnter Project Name : ";
    cin>>project;
}


void Professional :: showProfessionalData()
{
    cout<<"\n\nProfessional Details : "<<endl;
    cout<<"Organization : "<<name_of_org<<endl;
    cout<<"Job Profile : "<<job<<endl;
    cout<<"Project : "<<project<<endl;   


}







class Academic
{
    protected :
    string college_name;
    int pass_year;
    float cgpa;
    string branch;

    public:
    
    //default constructor
    Academic()
    {
        college_name = '\0';
        branch = '\0';
        pass_year = 0;
        cgpa = 0;

    }

    //parameterized constructor
    Academic(string college_name , string branch , int pass_year , float cgpa)
    {
        this->college_name = college_name;
        this->branch = branch;
        this->pass_year = pass_year;
        this->cgpa = cgpa;
    }


    void getAcademicData();
    void showAcademicData();
};


void Academic :: getAcademicData()
{
    cout<<"\n\nEnter name of college : ";
    cin>>college_name;

    cout<<"\nEnter branch : ";
    cin>>branch;

    cout<<"Enter passing year : ";
    cin>>pass_year;

    cout<<"\nEnter CGPA : ";
    cin>>cgpa;
}

void Academic :: showAcademicData()
{
    cout<<"\n\nAcademic Details : "<<endl;
    cout<<"College : "<<college_name<<endl;
    cout<<"Branch : "<<branch<<endl;
    cout<<"Passing Year : "<<pass_year<<endl;
    cout<<"CGPA : "<<cgpa<<endl;


}





class Biodata : public Personal , public Professional , public Academic
{

    public:
    
    Biodata()
    {
        cout<<"\n\nEnter Personal Data : ";
        getPersonalData();

        cout<<"\n\nEnter Professional Data : ";
        getProfessionalData();

        cout<<"\n\nEnter Academic Data : ";
        getAcademicData();

    }

   
    void showData();


};


void Biodata :: showData()
{

showPersonalData();
showProfessionalData();
showAcademicData();


}










int main()
{


Biodata b;
b.showData();




}