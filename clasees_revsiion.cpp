#include <iostream>
#include<string>
using namespace std;
class Contact
{
private:
    int id;
    string name;
    long long int number;
    string email;
public:
      void set_id(int uid)
    {
        id=uid;
    }
    void set_number(long long int unumber)
    {
        number=unumber;
    }
    void set_name(string uname)
    {
        name=uname;
    }
    void set_email(string uemail)
    {
        email=uemail;
    }
    int getdata_id()
    {
       return id;
    }
    string getdata_name()
    {
        return name;
    }
    string getdata_email()
    {
        return email;
    }
    long long int getdata_number()
    {
        return number;
    }
    Contact()
    {
     id=0;
     name='\0';
     email='\0';
     number=0;
    }
    Contact(int uid,string uname, long long int unumber,string uemail)
    {
       //set_id(uid);
       set_email(uemail);
       set_name(uname);
       set_number(unumber);
    }
    Contact(int uid,string uname, long long int unumber)
    {
        //set_id(uid);
       set_name(uname);
       set_number(unumber);
    }
    void display()
    {
        cout<<"Name   :: "<<getdata_name()<<endl;
        cout<<"Number :: "<<getdata_number()<<endl;
        cout<<"Email  :: "<<getdata_email()<<endl;
    }
};
class Contacts
{
private:
    Contact contacts[20];
    int lastID;
public:
    Contacts ()
    {
        lastID=0;
    }
    void add_contact()
    {
    int id;
    long long int number;
    string name,email;
    cout<<"enter name";
    cin>>name;
    cout<<"enter number";
    cin>>number;
    cout<<"enter email";
    cin>>email;
        Contact p(lastID,name,number,email);
        contacts[lastID]=p;
        lastID++;
    }
    void searchByNumber()
    {
        long long int z;
        cout<<"enter number to search for";
        cin>>z;
        for(int i=0;i!=20;i++)
        {
            if(contacts[i].getdata_number() == z)
                contacts[i].display();
        }
    }
    void searchByName()
    {
      string  y;
        cout<<"enter name to search for";
        cin>>y;
        for(int i=0;i!=20;i++)
        {
            if(contacts[i].getdata_name() == y)
                contacts[i].display();
        }  
    }
    void delete_contact()
    {
        long long int n;
        cout<<"Enter number to delete";
        cin>>n;
        for(int i=0;i!=20;i++)
        {
            if(contacts[i].getdata_number() == n)
                {
                    contacts[i].set_number(0);
                    contacts[i].set_name('\0');
                    contacts[i].set_email('\0');
                    
                }
        }
    }
    void diplayAll()
    {
      for(int i=0;i!=20;i++)
      {
          contacts[i].display();
      }
    }
    

};

int main()
{
    
    Contacts p;
    p.add_contact();
    //p.add_contact();
    p.delete_contact();
    p.diplayAll();

}