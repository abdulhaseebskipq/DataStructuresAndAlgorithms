#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int size =200;
int words_in_file();
int lines_in_file();
int find_in_file(string a);
void append_file();
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

       set_email(uemail);
       set_name(uname);
       set_number(unumber);
    }
    Contact(int uid,string uname, long long int unumber)
    {

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
    void add_contact(string name,long long int number,string email)
    {
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
                    contacts[i].set_name(NULL);
                    contacts[i].set_email(NULL);
                }
        }
    }
    void diplayAll()
    {
      for(int i=0;i!=20;i++)
      {
          if( contacts[i].getdata_number() != 0 )
            contacts[i].display();

      }
    }
    int list_size()
    {
        int s=0;
        for(int i=0;i!=20;i++)
      {
          if( contacts[i].getdata_number() != 0 )
            s++;

      }
      return s;

    }
    void export_file(char *arr)
    {
        cout<<"executing";
        ofstream file;
        file.open(arr,ios::app);
    for(int i=0;contacts[i].getdata_number() != 0;i++)
      {
          file<<contacts[i].getdata_name();
          file<<",";
          file<<contacts[i].getdata_number();
          file<<",";
          file<<contacts[i].getdata_email();
          file<<",";
          file<<endl;
      }
      file.close();
      
    }
    void import_file(char *arr)
    {
        int l;
        int na=0;
        long long int nmbr; string nam;string emai;
        l=lines_in_file();
        ifstream file;
        file.open(arr);
    for(int i=0;i<l;i++)
      {
          string a;
          file>>a;
         if(a!=",")
         {
             while(!file.eof())
             {
                 if(na==0)
                 {
                     file>>nam;
                     na++;
                     continue;
                 }
                    if(na==1)
                 {
                     file>>nmbr;
                     na++;
                     continue;
                 }
                    if(na==2)
                 {
                     file>>emai;
                     na=0;
                     add_contact(nam,nmbr,emai);
                     continue;
                 }
                 
             }
         }
      }
      file.close();
      
    }
    
};
int main()
{
    //cout<<"lines in file are "<<lines_in_file();
    //string a="haseeb";
    //cout<<find_in_file(a);
    //append_file();
    //////////
   Contacts p;
    /*p.add_contact();
    cout<<endl;
    cout<<"other "<<endl;
    p.add_contact();
    cout<<endl;
    cout<<"other "<<endl;
    p.add_contact();
    cout<<endl;
    cout<<"other "<<endl;
    p.add_contact();
    cout<<endl;
    cout<<"other "<<endl;
    char arr[200];
    cout<<"enter name of file";
    cin>>arr;
    p.export_file(arr);*/
    p.import_file("text.txt");
    p.diplayAll();
    
    ///////////
}
int words_in_file()
{
    int count=0;
    fstream file;
    string m;
    file.open("text.txt");
    while(!file.eof())
    {
        file>>m;
        count++;
    }
    file.close();
    return count;
}
int lines_in_file()
{
    int count=0;
    fstream file;
    string m;
    file.open("text.txt");
    while(!file.eof())
    {
        getline(file,m);
        count++;
    }
    file.close();
    return count;
}
int find_in_file(string a)
{
  int count=0;
    fstream file;
    string m;
    int k=lines_in_file();
    file.open("text.txt");
    for(int i=0;i<k;i++)
    {
           while(!file.eof())
    {
        file>>m;
        if(m==a)
            count++;
    } 
    }
    file.close();
    return count;  
}
void append_file()
{
    string a;
    cout<<"Enter data to enter ";
    getline(cin,a);
    fstream file;
    file.open("text.txt",ios::app);
    int k=lines_in_file();
    file<<endl;
    file<<a;
    file.close();
}



