#include <iostream>
using namespace std;
class Node
{
private:
    int Data;
    Node* left;
    Node* right;
    int height;
public:
    Node(int value)
    {
        Data=value;
        left=NULL;
        right=NULL;
    }

    void setHeight(int h)
    {
        height=h;
    }
    int getHeight()
    {
        return height;
    }
    void setLeft(Node* temp)
    {
        left=temp;
    }
    void setRight(Node* temp)
    {
        right=temp;
    }
    Node* getLeft()
    {
        return left;
    }
    Node* getRight()
    {
        return right;
    }
    void setData(int value)
    {
        Data=value;
    }
    int getData()
    {
        return Data;
    }
};

class AVL
{
private:
    Node* root;
public:
    AVL()
    {
        root=NULL;
    }


    int max(int a, int b)
    {
        return a>b?a:b;
    }
    Node * getRoot()
    {
        return root;
    }

    int getHeight(Node* node)
    {

        if(node==NULL)
        {

            return -1;
        }
        else
            return node->getHeight();
    }

    int getBalanceFactor(Node* node)
    {

        int bf=getHeight(node->getRight()) - getHeight(node->getLeft());
    }

    Node* rightRotate(Node* current)
    {

        cout<<"Rotating "<<current->getData()<<endl;
        Node* n2=current->getLeft();
        current->setLeft(n2->getRight());
        n2->setRight(current);

        int height=max(getHeight(current->getRight()), getHeight(current->getLeft()))+1;
        current->setHeight(height);

        height=max(getHeight(n2->getRight()), getHeight(n2->getLeft()))+1;

        n2->setHeight(height);
        cout<<"Returning "<<n2->getData()<<" as new parent\n";
        return n2;

    }
    Node* leftRotate(Node* current)
    {

        cout<<"Rotating "<<current->getData()<<endl;
        Node* n2=current->getRight();
        current->setRight(n2->getLeft());
        n2->setLeft(current);

        int height=max(getHeight(current->getRight()), getHeight(current->getLeft()))+1;
        current->setHeight(height);

        height=max(getHeight(n2->getRight()), getHeight(n2->getLeft()))+1;

        n2->setHeight(height);
        cout<<"Returning "<<n2->getData()<<" as new parent\n";
        return n2;

    }
    /*
    following will deal the error
    8
      10
    9
    */
    Node *leftright(Node *current)
    {
        current->setRight(rightRotate(current->getRight()));
        return leftRotate(current);
    }
    /*
    following will deal the error
    10
    8
    9
    */
    Node *rightleft(Node * current)
    {
        current->setLeft(leftRotate(current->getLeft()));
        return rightRotate(current);
    }
    void add(int value)
    {
        Node* newNode=new Node(value);
        root=addR(root,newNode);
    }
    Node* addR(Node* start,Node* newNode)
    {
        if(start==NULL)
        {
            start=newNode;
        }
        else if(start->getData() < newNode->getData())
        {
            start->setRight(addR(start->getRight(),newNode));
            int bf=getBalanceFactor(start);

            if(bf==2 || bf==-2)
            {

                if(newNode->getData() > start->getRight()->getData())
                {
                    start= leftRotate(start);

                }
                else
                {
                    start= leftright(start);
                }
            }
        }
        else if(start->getData() > newNode->getData())
        {
            start->setLeft(addR(start->getLeft(),newNode));
            int bf=getBalanceFactor(start);

            if(bf==2 || bf==-2)
            {

                if(newNode->getData() < start->getLeft()->getData())
                {
                    start= rightRotate(start);

                }
                else
                    start= rightleft(start);
            }
        }
        int height=max(getHeight(start->getRight()), getHeight(start->getLeft()))+1;
        start->setHeight(height);
        return start;
    }
    void printbfs(Node *t)
    {
        if (t== NULL)
            return;
        else
        {
            cout<<" Bf of "<< t->getData()<<"is = "<<getBalanceFactor(t)<<endl;
            printbfs(t->getLeft());
            printbfs(t->getRight());
        }
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
    void InOrder(Node *t)
    {
        if(t==NULL)
        {
            return;
        }
        else
        {

            InOrder(t->getLeft());
            cout<<t->getData()<<",";
            InOrder(t->getRight());

        }
    }
    int  deleteC(Node *t)
    {
        Node* temp= t->getLeft();
        while (temp->getRight()->getRight()!=NULL)
        {
            temp=t->getRight();
        }
        Node* n=temp->getRight();
        temp->setRight(temp->getRight()->getLeft());
        return n->getData();
    }
    Node *deleteA(Node *t)
    {
        if (t->getRight()==NULL)
            return t->getLeft();
        else
            t->getRight();
    }
    Node *deleteB(Node *t)
    {
        if (t->getRight()->getRight() == NULL && t->getRight()->getLeft() == NULL)
        {
            t->getRight()->setLeft(t->getLeft());
            return t->getRight();
        }
        else
        {
            if (t->getLeft()->getRight() == NULL && t->getLeft()->getLeft() == NULL)
            {
                t->getLeft()->setRight(t->getRight());
                return t->getLeft();
            }

            else
                return NULL;
        }

    }
    void deleteAVL(Node *r, int key)
    {
        if (key==r->getData())
        {
            if (r->getLeft()==NULL || r->getRight()==NULL)
            {
                root= deleteA(r);
            }
            else
            {
                Node *e= deleteB(r);
                if (e != NULL)
                    root = e;
                else
                    root->setData(deleteC(r));
            }
            int bf=getBalanceFactor(r);
            if (bf==2)
            {
                root=leftRotate(r);
            }
            else
            {
                if (bf==-2)
                    root=rightRotate(r);
            }
        }
        else
        {
            if (r->getData() >= key)
            {
                if (r->getLeft()->getData()==key)
                {
                    if (r->getLeft()->getRight()==NULL || r->getLeft()->getLeft()==NULL)
                    {
                        r->setLeft(deleteA(r->getLeft()));
                    }
                    else
                    {
                        Node *e= deleteB(r->getLeft());
                        if (e != NULL)
                        {
                            r->setLeft(e);
                        }
                        else
                            r->getLeft()->setData(deleteC(r->getLeft()));
                    }
            int bf=getBalanceFactor(r);
            if(bf==2 || bf==-2)
            {

                if(key < r->getLeft()->getData())
                {
                    r->setLeft(rightRotate(r->getLeft()));

                }
                else
                    r->setLeft(r->getLeft());
            }
                }

                else
                    deleteAVL(r->getLeft(),key);
            }
            else
            {
                if (r->getRight()->getData()== key)
                {
                    if (r->getRight()->getRight()==NULL || r->getRight()->getLeft()==NULL)
                        r->setRight(deleteA(r->getRight()));
                    else
                    {
                        if (deleteB(r->getLeft()) != NULL)
                        {
                            Node *e = deleteB(r->getRight());
                            r->setRight(e);
                        }
                        else
                            r->getRight()->setData(deleteC(r->getRight()));
                    }
            int bf=getBalanceFactor(r);
            if(bf==2 || bf==-2)
            {

                if(key > r->getRight()->getData())
                {
                    r->setRight(leftRotate(r->getRight()));

                }
                else
                {
                    r->setRight(leftright(r->getRight()));
                }
            }
                }
                else
                    deleteAVL(r->getRight(),key);
            }
        }
        int height=max(getHeight(r->getRight()), getHeight(r->getLeft()))+1;
        r->setHeight(height);
    }
};
int main()
{
    AVL a;
    a.add(25);
    a.add(9);
    a.add(8);
    a.add(15);
    a.add(65);
    a.add(55);

    cout<<"\n";
    int i=1,c;
    while (i==1)
    {
        cout<<"which one to delete"<<endl;
        cin>>c;
          a.deleteAVL(a.getRoot(),c);
          a.postOrder(a.getRoot());
          cout<<"\n";
          a.printbfs(a.getRoot());
          cout<<"to continue enter "1" "<<endl;
          cin>>i;
    }


    return 1;
}
