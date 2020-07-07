#include<bits/stdc++.h>
using namespace std;

class String
{
    
    char *str;
    int size;

    public:

    //default constructor
    String()
    {
        str = new char [1];
        //str = '\0';

    }
    
    //parameterized constructor
    String(int size)
    {
        this->size = size;
        str = new char [size];
        //str = '\0';
    }
    
    
    String operator +(String s);
    void operator *(int x);
    friend void operator *(int x , String s);
    friend ostream& operator << (ostream &cout,String s);
    friend istream& operator >> (istream &cin , String &s);

    
    //Extra Operator Overloading
    void operator %(String s);    //checks if strings are same
    void operator -();            //reverses the string
    void operator !();            //shows length of string
    

    



};





// + operator overloading
String String :: operator+(String s)
{
    String temp = *this;
    
    strcat(str , s.str);
    
    return temp;

}





// * operator overloading case I (string*integer)
void String :: operator*(int x)
{   
    
    cout<<"\n\nMultiplication operator overloading [String * Integer]: ";
    for(int i = 0; i < x ; i++)
    {   
        
        cout<<str;
        
    }

    
}




// * operator overloading case II (integer*string)
void operator *(int x , String s)
{
    cout<<"\n\nMultiplication operator overloading [Integer * String]: ";
    for(int i = 0; i < x ; i++)
    {   
        
        cout<<s.str;
        
    }

}




//output operator overloading
ostream& operator << (ostream &cout , String s)
{

    cout << s.str;
    return cout;

} 





//input operator overloading
istream& operator >> (istream &cin , String &s)
{


    cout<<"\nEnter String : ";
    cin >> s.str;

    return cin;


}


// % operator overloading
// checks if the strings are same or not
void String :: operator% (String s)
{
    if(!strcmp(str , s.str))
    {
        cout<<"\n\nStrings are same";
    }

    else
    {
        cout<<"\n\nStrings are not same";
    }
    

}





// reverses the given string 
// Syntax : -string 
void String :: operator-()
{
    cout<<"\n\nReversed String is : "<<strrev(str);

}

//shows length of given string
void String :: operator!()
{
    cout<<"\n\nLength of string is : "<<strlen(str);
}







int main ()
{
    String s1(30);
   
    cin>>s1;

    String s2(30);
    
    cin>>s2;

    

    s1 % s2; // checks if strings are same or not
    
    3*s1;

    s2*3;  

    cout<<"\n\n";
    
    String s3(30);
    String s4(50);

    cin>>s3;
    
    
    cout<<"\n\nAddition operator overloading with cascading : ";
    s4 = s1+s2+s3;

    

    cout<<s4;

    -s4;  // reverses the string 
    !s4;  // shows length of string
    

}