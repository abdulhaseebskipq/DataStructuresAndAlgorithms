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
        if(temp==NULL)
        {
            addAtStart(a);
        }
        else
        {
        while(temp->getNext() !=NULL)
        {
          temp=temp->getNext();
        }
        temp->setNext(c);
        }
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
    void clearAll()
    {
        head=NULL;
    }
    string listpeek()
    {
        return head->getData();
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

};
class LStack
{
 private:
    LinkedList s;
public:
    void push(string a)
    {
        s.addAtStart(a);
    }
    void pop()
    {
      s.remove_first();
    }
    void sdisplay()
    {
        s.displayList();
    }
    void clearlist()
    {
        s.clearAll();
    }
    string top()
    {
        return s.listpeek();
    }
};
class LQueue
{
private:
    LinkedList q;
public:
    void enqueue(string a)
    {
        q.addAtEnd(a);
    }
    void dequeue()
    {
      q.remove_first();
    }
    void qdisplay()
    {
        q.displayList();
    }
    void clearlist()
    {
        q.clearAll();
    }
    string peek()
    {
        return q.listpeek();
    }
};
class AStack
{
private:
    int arr[20];
    int tail=0;
public:
    void push(int x)
    {
      if(tail==20)
      {
          cout<<"it is full"<<endl;
      }
      else
      {
          arr[tail]=x;
          tail++;
      }
    }
    void pop()
    {
        if (tail==0 || tail<0)
            cout<<"nothing to pop"<<endl;
        else
            tail--;
    }
    int top()
    {
       return arr[tail-1];
    }
    bool isfull()
    {
      if (tail<=19)
            return true;
      else
        return false;
    }
    void clear_list()
    {
        tail=0;
    }
    void display_sarray()
    {
        int i=0;
        for(i;i<tail;i++)
        {
          cout<<arr[i]<<endl;
        }
    }

};
class AQueue
{
   private:
       int arr[20];
       int head=0;
       int tail=0;
   public:
    void enqueue(int x)
    {
        arr[tail]=x;
        tail++;
    }
    void dequeue()
    {
        if (head<tail)
         head++;
        else
        cout<<"nothing to pop"<<endl;

    }
    void clear_list()
    {
        head=0;
        tail=0;
    }
    int peek()
    {
        return arr[tail-1];
    }
    bool isfull()
    {
      if (tail<=19)
            return true;
      else
        return false;
    }
    void display_sarray()
    {
        int i=head;
        for(i;i<tail;i++)
        {
          cout<<arr[i]<<endl;
        }
    }

};
class CQueue
{
   private:
       int start=0;
       int endd=0;
       int arr[5];
   public:
       void enqueue(int x)
       {
           arr[endd]=x;
          if(endd==5 && start!=0)
          {
           endd=0;
          }
          else
          {
                endd++;
          }
       }
       void dequeue()
       {
           if (start==4)
            start=0;
            else
                start++;
       }
    int peek()
    {
        return arr[endd-1];
    }
    bool isfull()
    {
        if (start==0 && endd<=5)
            return true;
        else
            false;
    }
    void clear_list()
    {
        start=0;
        endd=0;
    }
     void display_list()
     {
         int i=0;
        for(i;i<5;i++)
        {
          cout<<arr[i]<<endl;
        }
     }


};
int main()
{
    CQueue c;
    c.enqueue(1);
    c.enqueue(2);
    c.enqueue(3);
    c.enqueue(4);
    c.enqueue(5);
    //c.enqueue(6);
    c.dequeue();
    c.dequeue();
    c.enqueue(19);
    //c.enqueue(19);
    c.display_list();
}



