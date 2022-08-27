#include <iostream>
using namespace std;
const int size =10;
class HashTable
{
private:
    int e_index[size];
    int counter=-1;
    int a[size];
public:
    void add_e_index (int i)
    {
        e_index[counter]=i;
    }
    bool is_prime(int a)
    {
        int i=a-1;
        for(i;i!=1;i--)
        {
            if(a%i==0)
                return false;
        }
        return true;
    }
    int Lhash(int value,int i)
    {
        return ((hashFun(value)+i)%size);
    }
    int Qhash(int value, int i)
    {
        return ((hashFun(value)+(i*i))%size);
    }
    int Dhash (int value, int i)
    {
        int p = cal_prime();
       return ((hashFun(value)+(i*(p-(value%p))))%size);
    }
    int cal_prime()
    {
        for(int i=size;i>=0;i--)
        {
            if (is_prime(i))
                return i;
        }
    }
    bool is_collosion(int c)
    {
        for(int j=0;j<=counter;j++)
        {
            if (e_index[j]==c)
                return true;
        }
        return false;

    }
    int hashFun(int value)
    {
        return (value%size);
    }
    int LinearProbing(int value)
    {
        return LinearAssist(value,1);
    }
    int LinearAssist(int value,int i)
    {
       int c = ((hashFun(value)+i)%size);
       if (is_collosion(c)==false)
       {
            return c;
       }
        else
        {i=i+1;
            LinearAssist(value,i);
        }

    }
    //////
    int QuadProbing(int value)
    {
        return QuadAssist(value,1);
    }
    int QuadAssist(int value,int i)
    {
       int c = ((hashFun(value)+(i*i))%size);
       if (!(is_collosion(c)))
       {
            return c;
       }
    else
        {
            i=i+1;
         QuadAssist(value,i);
        }

    }
    ///////
    int DoubleHashing(int value)
    {
        int p=cal_prime();
        return DHAssist(value,1,p);
    }
    int DHAssist(int value,int i,int p)
    {
       int c = ((hashFun(value)+(i*(p-(value%p))))%size);
       if (!(is_collosion(c)))
       {
            return c;
       }
        else
        {
            i=i+1;
         DHAssist(value,i,p);
        }
    }
    ///////
    void add(int value)
    {
        int x;
        int c= hashFun(value);
        if(!(is_collosion(c)))
        {
            a[c]=value;
            counter++;
            add_e_index(c);
        }
        else
        {
            cout<<"There has been a collision, Press 1 for LinearProbing, 2 for QuadProbing and 3 for double hashing"<<endl;
            cin >> x;
            if (x==1)
            {
                cout<<"prob"<<LinearProbing(value)<<endl;
                a[LinearProbing(value)]=value;
                counter++;
                add_e_index(LinearProbing(value));
                return ;
            }
            if (x==2)
            {
                a[QuadProbing(value)]=value;
                counter++;
                add_e_index(QuadProbing(value));
                return;
            }
            if (x==3)
            {cout<<"hello"<<endl;
                a[DoubleHashing(value)]=value;
                counter++;
                add_e_index(DoubleHashing(value));
                return;
            }
        }
        }
    int searchTable(int value)
    {
        int x;
        cout<<"How have you constructed your table? 1- Linear, 2- Quad, 3- DoubleHash"<<endl;
        cin>>x;
        return searchAssist(value,x);
    }
    int searchAssist(int value,int type)
    {
        int c=hashFun(value),i=1;
        if(a[c]==value)
            return c;
        else
        {
                if(type==1)
                {
                    c = Lhash(value,1);
                    while (c!=hashFun(value))
                    {
                     if (a[c]==value)
                            return c;
                     else
                     {
                         i=i+1;
                         c=Lhash(value,i);
                     }
                    }
                    return -1;
                }
                if (type==2)
                {
                    c = Qhash(value,1);
                    while (c!=hashFun(value))
                    {
                     if (a[c]==value)
                            return c;
                     else
                     {
                         i=i+1;
                         c=Qhash(value,i);
                     }
                    }
                    return -1;
                }
                if (type==3)
                {
                    c = Dhash(value,1);
                    while (c!=hashFun(value))
                    {
                     if (a[c]==value)
                            return c;
                     else
                     {
                         i=i+1;
                         c=Dhash(value,i);
                     }
                    }
                return -1;
                }
        }
    }
    void deleteHash(int value)
    {
        int k = searchTable(value);
        if(k != -1)
        {
          deleteAssist(k);
        }
    }
    void deleteAssist(int i)
    {
        for (int j=0;j<=counter;j++)
        {
            if (e_index[j]==i)
            {
                shift(j);
            }
        }
        counter--;
    }
    void shift(int i)
    {
       for(i;i<counter;i++)
       {
           e_index[i]=e_index[i];
       }
    }
    void edisplay()
    {
        for (int i=0;i<=counter;i++)
        {
          cout<<e_index[i]<<endl;
        }
    }
    void display()
    {
        for (int i=0;i<=counter;i++)
        {
                cout<<"Value at "<< e_index[i]<<"is "<< a[e_index[i]]<<endl;

        }
        cout<<"counter is "<<counter<<endl;
    }
    bool is_full()
    {
        if (counter>=size-1)
            return true;
        else
            return false;
    }
    void is_emptyy()
    {
        cout<<"Size of table is "<<size<<"and "<<counter<<" indexes are occupied"<<endl;
    }

};
int main()
{
    HashTable b;
    int m;
    for (int i=0;i!=10;i++)
    {
        cout<<"enter a number";
        cin>>m;
        b.add(m);
    }
    b.display();
    b.deleteHash(12);
   // cout<<b.searchTable(10)<<endl;
 // cout<<b.searchTable(99)<<endl;
  //cout<<b.searchTable(9)<<endl;
  //cout<<b.searchTable(1234)<<endl;
    cout<<"full "<<b.is_full()<<endl; //this will return true or false.
    b.is_emptyy();//this will tell how much indexes have been occupied
    b.display();
}

