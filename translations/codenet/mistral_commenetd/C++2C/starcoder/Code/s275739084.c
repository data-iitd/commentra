
#include<stdio.h>

int main()
{
  int A, B;

  scanf("%d %d", &A, &B);

  int C = A + B;

  if(A%3!= 0 && B%3!= 0)
  {
    if(C%3!= 0)
    {
      printf("Impossible\n");
    }
    else
    {
      printf("Possible\n");
    }
  }

  return 0;
}

