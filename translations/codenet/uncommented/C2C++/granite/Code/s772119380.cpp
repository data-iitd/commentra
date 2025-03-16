
#include <iostream>

int main()
{
 int a[1000],n,i,j,d=0;
 std::cin>>n;
 for(i=0;i<n;i++)
  std::cin>>a[i];
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
  for(i=0;i<n;i++)
  {
   std::cout<<a[i]<<" ";
  }
 std::cout<<"\n"<<d<<"\n";
 return 0;
}
