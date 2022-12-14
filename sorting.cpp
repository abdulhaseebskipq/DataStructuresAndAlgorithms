#include <iostream>
using namespace std;
class Sorting
{
public:
    void insertA(int *a,int n) //n is the length of our array
    {
        if(n<=1)
            return;
        else
        {
            int k=a[n-1];
            for (int i=0;i!=(n-1);i++)
            {
                if(a[i]>=k)
                {
                    shiftR(a,i,n);
                    a[i]=k;
                    return;
                }
            }
        }
    }
    int min_index(int *a,int start,int n)
    {
        int j=start,m=a[start],i=start;
        for (i;i!=n;i++)
        {
          if (m>a[i])
          {
              m=a[i];
              j=i;
          }
        }
        return j;
    }
    void swap_index(int *a,int i,int j)
    {
        int k=a[i];
        a[i]=a[j];
        a[j]=k;
    }
    void moveMin(int *a,int start,int n)
    {
        int c=min_index(a,start,n);
        swap_index(a,start,c);
    }
    void shiftR(int *a, int i,int n)
    {
        for(int j=n-1;j!=i;j--)
        {
            a[j]=a[j-1];
        }
    }
    void insertionSort(int *a,int n)
    {
        int i=2;
        while(i!=(n+1))
        {
            insertA(a,i);
            i++;
        }
    }
    void selctionSort(int *a,int n)
    {
         int i=0;
        while(i!=n)
        {
            moveMin(a,i,n);
            i++;
        }
    }
    void display(int *a,int n)
    {
        for (int i=0;i<=(n-1);i++)
            cout<<a[i]<<endl;
    }
 void mergeA(int *a,int *b,int *f,int n)
 {
   //copyA(f,a,n);
    mergeAssist(f,a,b,0,0,0,n,n);
 }
 void mergeAssist(int *f,int *a,int *b,int fi,int ai,int bi,int as,int bs)
 {
   while(ai!=as && bi!=bs)
   {
       if(a[ai]>b[bi])
       {
           f[fi]=b[bi];fi++; bi++;
       }
       else
       {
           f[fi]=a[ai];fi++;ai++;
        }
   }
   if (fi==(as+bs))
   {
       return;
   }
   else
   {
       if(ai!=as)
       {
           for(fi;fi!=(as+bs);fi++)
           {
               f[fi]=a[ai];
               ai++;
           }
       }
       else
       {
           for(fi;fi!=(as+bs);fi++)
           {
               f[fi]=b[bi];
               bi++;
           }
       }
   }
 }
 void copyA(int *f,int *t,int n)
 {
   for(int i=0;i!=n;i++)
   {
       f[i]=t[i];
   }
 }
 void mergeSort(int *a,int n)
 {
     quicksort(a,n);
 }
 void quicksort(int *a,int n)
 {
     for (int i=0;i!=n;i++)
     {
         place_pivot(a,i,n);
     }
 }
 void input(int *a,int n)
 {
     int x;
     for(int i=0;i!=n;i++)
     {
         cout<<"enter a number"<<endl;
         cin>>x;
         a[i]=x;
     }
 }
 void place_pivot(int *a,int j,int n)
 {
     int c=j,k;
     for(k=0;k!=j;k++)
     {
         if (a[k]>a[c])
         {
             swap_index(a,k,c);
             c=k;
         }
     }
    for(k;k!=n;k++)
     {
         if (a[k]<a[c])
         {
             swap_index(a,k,c);
             c=k;
         }
     }

 }
};
int main()
{
    Sorting b;
    int i;
    int a[4],k[4],f[8];

            /*cout<<"enter elements in sorted order but last misplaced"<<endl;
            b.input(a,4);
            cout<<"Array is "<<endl;
            b.display(a,4);
            b.insertA(a,4);
            cout<<"Output is"<<endl;
            b.display(a,4);*/
/*
            int d[4]={1,2,3,-1};
            cout<<"Array is"<<endl;
            b.display(d,4);
            b.moveMin(d,0,4);
            cout<<"After moving min array is"<<endl;
            b.display(d,4);
*/


          /*  cout<<"Enter an unsorted array of size 4";
            b.input(a,4);
            cout<<"Array after insertion sort is"<<endl;
            b.insertionSort(a,4);
            b.display(a,4);*/

           /* cout<<"Enter an unsorted array of size 4";
            b.input(a,4);
            cout<<"Array after selection sort is"<<endl;
            b.selctionSort(a,4);
            b.display(a,4);*/
/*
            cout<<"enter an sorted array of size 4"<<endl;
            b.input(a,4);
            cout<<"enter an sorted array of size 4"<<endl;
            b.input(k,4);
            cout<<"Merging them"<<endl;
            b.mergeA(a,k,f,4);
            b.display(f,8);
*/
/*
            cout<<"Enter an unsorted array of size 4";
            b.input(a,4);
            cout<<"Array after merge sort is"<<endl;
            b.mergeSort(a,4);
            b.display(a,4);
            */
/*
            cout<<"Enter an unsorted array of size 4";
            b.input(a,4);
            cout<<"Array after quick sort is"<<endl;
            b.quicksort(a,4);
            b.display(a,4);
*/

}
