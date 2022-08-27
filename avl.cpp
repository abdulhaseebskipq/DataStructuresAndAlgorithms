#include <iostream>
using namespace std;
class Node
{
private:
int data;
Node * right;
Node *left;
Node *parent;
public:
Node()
{
data=0;
right=NULL;
left=NULL;
parent=NULL;
}
Node (int x)
{
data=x;
right=NULL;
left=NULL;
parent=NULL;
}
void setRight(Node *x)
{
right=x;
}
void setLeft(Node *x)
{
left=x;
}
void setData(int x)
{
data=x;
}
void setParent(Node *x)
{
    parent=x;
}
int getData()
{
return data;
}
Node* getRight()
{
return right;
}
Node *getLeft()
{
return left;
}
Node *getParent()
{
    return parent;
}
};
class AVL
{
private:
Node *root;
public:
AVL()
{
root=NULL;
}
Node *getroot()
{
return root;
}
void AVL_add(Node *t,Node *n)
{
    if (n==NULL)
        return;
    if (t==NULL && t==root)
{
root=n;
cout<<"added data at the root"<<endl;
n->setParent(NULL);
return;
}
else
{
if (t->getData() < n->getData())
{
if (t->getRight() == NULL)
{
t->setRight(n);
}
else
{
AVL_add(t->getRight(),n);
}
}
else
{
if (t->getLeft()== NULL)
{
t->setLeft(n);
}
else
{
AVL_add(t->getLeft(),n);
}
}
}
n->setParent(t);
//check balance factor
Node *e= check_bf(n);
if (e==NULL)
    return;
else
{
    Node *t1=give_pointer(e,n);
    Node *t2=give_pointer(t1,n);
    Node *m;Node *h;Node *k;Node *mr;Node *ml;
    if (t1->getData()<=e->getData())
    {
        if (t2->getData()>t1->getData())
        {
            m=t1;
            h=t2;
            k=e;
        }
        else
        {
            m=t2;
            h=t1;
            k=e;
        }
    }
    else
    {
        if (t2->getData()>t1->getData())
        {
         m=t1;
         h=t2;
         k=e;
        }
        else
        {
         m=t2;
         h=t1;
         k=e;
        }
    }
    mr=m->getRight();
    ml=m->getLeft();
    if (h->getData()<=m->getData())
    {
        m->setLeft(h);
        h->setParent(m);
        m->setRight(k);
        k->setRight(m);
    }
    else
    {
      m->setLeft(k);
      h->setParent(m);
      m->setRight(h);
      k->setRight(m);
    }
    m->setParent(e->getParent());
    if (e==root)
    {
        root=m;
    }
    else
    {
        if ((e->getParent()->getData())>=(m->getData()));
        {
          e->getParent()->setLeft(m);  
        }
        else
            e->getParent()->setRight(m);
    }
    AVL_add(m,mr);
    AVL_add(m,ml);
}
}
Node *check_bf(Node *t)
{
    int a,b,c;
    Node *temp=t;
    while(temp!=NULL)
    {
        a=height(t->getRight());
        b=height(t->getLeft());
        c=a-b;
        if (c==1 || c==-1 || c==0)
        {
            temp=temp->getParent();
        }
        else
        {

          break;
        }
    }
    return temp;
}
Node *give_pointer(Node *e, Node *n)
{
    if (n->getData()<=e->getData())
    {
        return e->getLeft();
    }
    else
        return e->getRight();
}
void preOrder(Node *t)
{
    if(t==NULL)
    {
        return;
    }
    else
    {
        cout<<t->getData()<<",";
        preOrder(t->getLeft());
        preOrder(t->getRight());
    }
}
int height(Node *r)
{
    if (r==NULL)
    {
        return -1;
    }
    else
    {
        int a=height(r->getRight());
        int b=height(r->getLeft());
          if (a>b)
            {
                return (a+1);
            }
        else
        {
            return (b+1);
        }
    }
}
void postOrder(Node *t)
{
    if(t==NULL)
    {
        return;
    }
    else
    {

        postOrder(t->getLeft());
        postOrder(t->getRight());
        cout<<t->getData()<<",";
    }
}
/*bool searchBST(Node *t,int x)
{
if (t==root && t->getData() == x)
{
cout<<"data found at the root"<<endl;
return true;
}
else
{
if (t->getData() < x )
{
if (t->getRight()->getData() == x)
{
cout<<"Data find"<<" at the right of "<<t->getData()<<endl;
}
else
{
searchBST(t->getRight(),x);
}
}
else
{
if (t->getLeft()->getData()== x)
{
cout<<"found data "<<"at the left of "<<t->getData()<<endl;
return true;
}
else
{
searchBST(t->getLeft(),x);
}
}
}
}*/
};
int main()
{
AVL a;
int x;
for(int i=0;i<3;i++)
{
    cout<<"enter";
    cin>>x;
    a.AVL_add(a.getroot(),new Node(x));
}
a.preOrder(a.getroot());
}





