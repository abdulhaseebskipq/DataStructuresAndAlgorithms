#include <iostream>
using namespace std;
class Heap
{
private:
    int a[20];
    int point=0;
    int length=0;
public:
    int getLength()
    {
        return length;
    }
    int getLeft(int i)
    {
        return (2*i+1);
    }
    int getRight(int i)
    {
        return (2*i+2);
    }
    int getParent(int i)
    {
        return ((i-1)/2);
    }
    int getTop()
    {
        return a[0];
    }
    bool isheap ()
    {
    int  i;
    int  s  = length;
    for (i =0; i < s/2 ; i++ )
    {
        if (!(getLeft(i) >= length))
        {
            if (a[i] < a[getLeft(i)])
                return false;
        }
        if(!(getRight(i) >= length))
        {
            if (a[i] < a[getRight(i)])
                return false;
        }
    }
    return true;
    }
    void swap_nodes(int i, int j)
    {
        int b = a[i];
        a[i]=a[j];
        a[j]=b;
        return ;
    }
    int getMax(int i, int j)
    {
        if(j >= length)
        {
            if (!(i >= length))
                return i;
        }
        else
        {
        if(i >= length)
        {
            return j;
        }
        else
        {
            if (a[i]>a[j])
                return i;
            else
                return j;
        }
        }
    }
    void heapifydown()
    {
        int i=0,k;
        while (!(isheap()))
        {
            k=getMax(getLeft(i),getRight(i));
           if (a[i] < a[k])
                swap_nodes(i,k);
           i=k;
        }
    }

    void heapifyup()
    {
        int j=point;
        while (j!= 0)
        {
                if (a[j] > a[getParent(j)])
                  swap_nodes(j,getParent(j));
            j=getParent(j);
        }
    }
    void addHeap(int x)
    {
        a[point]=x;
        length++;
        if (!(isheap()) )
            heapifyup();
        point++;
    }
    void delHeap()
    {
        cout<<a[0]<<" has been deleted"<<endl;
        a[0]=a[point-1];
        length--;
        point--;
        if (!(isheap()))
            heapifydown();
    }
    void display()
    {
        for (int i=0;i<point;i++)
        {
            cout<<a[i]<<endl;
        }
    }

};
int main()
{
  Heap b;
  int x;
  int j=1;
  while (j==1)
  {
      cout<<"enter a number";
      cin>>x;
  b.addHeap(x);
  cout<<" press 1 for continue ";
  cin>>j;
  cout<< "is heap "<<b.isheap()<<endl;
  cout << " length "<< b.getLength()<<endl;

  b.display();
  cout<<endl;
  }
  j=1;
  while (j==1)
  {
  b.delHeap();
  cout<<b.isheap()<<endl;
  b.display();
  cout<<endl;
  cout<<"press 1 to delete more ";
  cin>>j;
  }
  cout<<"final is heap "<<b.isheap()<<endl;
  cout<<"top is = "<<b.getTop();
  b.display();
}
