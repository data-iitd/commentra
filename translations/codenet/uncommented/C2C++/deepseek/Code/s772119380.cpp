#include <iostream>
using namespace std;

int main()
{
 int a[1000],n,i,j,d=0;
 cin >> n;
 for(i=0;i<n;i++)
  cin >> a[i];
 for (i = 0;i<n;i++)
 {   
     for (j = n-1;j>= i+1;j--)
     {
        if (a[j] < a[j-1])
        {
          int temp=a[j];
          a[j]=a[j-1];
          a[j-1]=temp;
          d++;
        }
     }
 }
  cout << a[0];
  for(i=1;i<n;i++)
  {
   cout << " " << a[i];
  }
 cout << endl << d << endl;
 return 0;
}
