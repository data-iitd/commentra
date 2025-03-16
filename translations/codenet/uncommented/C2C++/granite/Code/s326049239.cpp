
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int a,c,k,b;
    while(~scanf("%d",&a))
    {
        c=0,k=0;
        if(a<3)
          printf("0\n");
        else
        {
            b=a;
            while(a--)
           {
             b--;
             c++;
            if(c==3)
            {
              k++;c=0;
            }
          }
            printf("%d\n",k);
        }

    }

}
