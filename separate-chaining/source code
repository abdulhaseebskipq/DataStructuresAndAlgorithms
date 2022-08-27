#include <iostream>
using namespace std;
class Node
{
    private:
    int data;
    Node *next;
    public:
    Node ()
    {
        next=NULL;
    }
    Node (int n)
    {
        data=n;
    }
    void setData(int n)
    {
        data=n;
    }
    int getData()
    {
        return data;
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
        cout<<data<<" , ";
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
    Node *getHead()
    {
        return head;
    }
    void addAtStart(int x)
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
    int search(int k)
    {
    Node *temp;
     temp=head;
      int i=0;
      int l;
      while(temp!=NULL)
       {
           l=temp->getData();
           if(l==k)
            return 1;
            i++;
           temp=temp->getNext();
       }
       return -1;

    }
    void addAtEnd(int a)
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
    void add_at_index(int n,int i)
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
    void remove_int(int a)
    {
        Node* temp=head;
        if (search(a)==-1)
        {
            cout<<"int not present"<<endl;
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
};
class SepHash
{
private:
    LinkedList a[10];
public:
    int hashFun(int value)
    {
        return (value%10);
    }
    void add(int value)
    {
        int c= hashFun(value);
        a[c].addAtStart(value);
    }
    void deleteSH(int value)
    {
        int c= hashFun(value);
        a[c].remove_int(value);
    }
    bool searchSH(int value)
    {
        int c= hashFun(value);
        if (a[c].search(value)==1)
            return true;
        else
            return false;

    }
    void display()
     {
         for(int i=0; i<10; i++)
         {
             if (a[i].getHead()!=NULL)
             {
             a[i].displayList();
             cout<<endl;
             }
         }

     }
     bool isFull()
     {
         for (int i=0; i<10 ; i++)
         {
             if (a[i].getHead()==NULL)
                return false;
         }
         return true;
     }
     bool isEmpty()
     {
         return (!isFull());
     }
};
int main()
{
    SepHash b;
    int x;
         for(int i=0; i<9; i++)
         {
             cout<<"enter"<<endl;
             cin>>x;
             b.add(x);
         }
         /*b.deleteSH(2);
         cout<< "searching 2 "<<b.searchSH(2)<<endl;
         cout<<"searching 10 "<<b.searchSH(10)<<endl;*/
         cout<<"is full "<< b.isFull()<<endl;
         cout<<" is empty "<< b.isEmpty()<<endl;
    b.display();
}


