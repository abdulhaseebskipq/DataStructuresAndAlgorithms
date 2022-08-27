#include <iostream>
#include <string>
#include<fstream>
using namespace std;
class Node 
{
    private:
    string name;
    Node *next;
    public:
    Node ()
    {
        next=NULL;
    }
    Node (string n)
    {
        name=n;
    }
    void setData(string n)
    {
        name=n;
    }
    string getData()
    {
        return name;
    }
    void setNext(Node *ne)
    {
        next=ne;
    }
    Node* getNext()
    {
        return next;
    }
    void displayNode()
    {
        cout<<name<<endl;
    }
    
};
class LinkedList
{
    private:
    Node* head;
    public:
    LinkedList()
    {
       head=NULL; 
    }
    void addAtStart(string x)
    {
        Node *n=new Node(x);
        n->setNext(head);
        head=n;
    }
    void displayList()
    {
       Node *temp;
       temp=head;
       while(temp!=NULL)
       {
           temp->displayNode();
           temp=temp->getNext();
       }
    }
    int number_of_nodes()
    {
      Node *temp;
       temp=head;
       int count=0;
       while(temp!=NULL)
       {
           count++;
           temp=temp->getNext();
       } 
       return count;
    }
    int search(string k)
    {
    Node *temp;
     temp=head;
      int i=0;
      string l;
      while(temp!=NULL)
       {
           l=temp->getData();
           if(l==k)
            return i;
            i++;
           temp=temp->getNext();
       } 
       return -1;
        
    }
    void addAtEnd(string a)
    {
        Node *c=new Node(a);
        Node *temp;
        temp=head;
        while(temp->getNext() !=NULL)
        {
          temp=temp->getNext();
        }
        temp->setNext(c);
     }
    void add_at_index(string n,int i)
    {
        Node *c=new Node(n);
        Node *temp=head;
        if(i<=0)
        {
            addAtStart(n);
        }
        else
        {
          if(i>number_of_nodes())
        {
            addAtEnd(n);
        }
        else
        {
            for(int j=0;j!=(i-1);j++)
            {
                temp=temp->getNext();
            }
            c->setNext(temp->getNext());
            temp->setNext(c);
        }
        }
        
    }
    void remove_first()
    {
        head=head->getNext();
    }
    void remove_end()
    {
        Node *temp=head;
        while((temp->getNext()->getNext()!=NULL))
        {
            temp=temp->getNext();
        }
        temp->setNext(NULL);
    }
    void remove_string(string a)
    {
        Node* temp=head;
        if (search(a)==-1)
        {
            cout<<"string not present"<<endl;
            return;
        }
        while(temp->getNext()!=NULL)
        {
        
            if(head->getData()==a)
            {
                head=head->getNext();
                return;
            }
            if (temp->getNext()->getData()==a)
            {
                temp->setNext(temp->getNext()->getNext());
                return;
            }
            temp=temp->getNext();
        }
    }
    void removeAt(int j)
    {
       Node* temp=head;
       if(j<0 || j==number_of_nodes())
       {
           cout<<"index out of range"<<endl;
           return;
       }
       if(j==0)
            {
                head=head->getNext();
                return;
            }
        for(int i=0;i<number_of_nodes();i++)
        {
           
            if (i==j-1)
            {
                temp->setNext(temp->getNext()->getNext());
                return;
            }
            temp=temp->getNext();
        }
    }
    void displayReverse(Node *temp)
    {
       if(temp==NULL)
       return;
       else
       {
           displayReverse(temp->getNext());
           cout<<temp->getData();
       }
    }
    void automater()
    {
        ifstream file;
        file.open("text.txt");
        string m,a;
        int i;
        while(!file.eof())
        {
            file>>m;
            if(m=="AAS")
            {
                file>>a;
                addAtStart(a);
            }
            if(m=="AAE")
            {
                file>>a;
                addAtEnd(a);
            }
            if(m=="ADD")
            {
                file>>a;
                file>>i;
                add_at_index(a,i);
            }
            if(m=="REM")
            {
                file>>a;
                remove_string(a);
            }
            if(m=="RAI")
            {
                file>>i;
                removeAt(i);
            }
            if(m=="RAS")
            {
                remove_first();
            }
            if (m=="RAE")
            {
                remove_end();
            }
            if (m=="DIS")
            {
                displayList();
            }
           if (m=="DIR")
            {
                displayReverse(head);
            }
        }
        file.close();
        
    }
    void task()
    {
        string a,t;
        int as,ts,i=0;
        cout<<"enter a string";
        cin>>a;
        as=a.size();
        Node *temp=head;
        if (temp==NULL)
        {
            addAtStart(a);
        }
        else
        {
            while (temp!=NULL)
            {
                t=temp->getData();
                ts=t.size();
                if (ts<as)
                {
                    add_at_index(a,i+1);
                }
                else
                {
                 add_at_index(a,i-1);   
                }
                i++;
                temp=temp->getNext();
            }
        }
    }
    
};
int main()
{
   LinkedList a;
   //a.automater();
   a.task();
   a.task();
   a.task();
   a.displayList();
   //ofstream file;
   //file.open("text.txt");
   //file.close();
  // a.addAtStart("Haseeb");
  // a.addAtStart("Abdul");
   //a.addAtStart("Sheikh");
   //a.addAtEnd(" AoA");
   //a.add_at_index("Mani",2);
   //a.remove_first();
  // a.remove_end();
  //a.removeAt(0);
  //a.displayList();
  //a.displayReverse();
   
   //cout<<a.number_of_nodes();
   //cout<<a.search("Abdul",a);
   
}


