#include<stdio.h>
#include<stdlib.h>
int check(int n,int wei,int *book)
{
  int tmp=wei;
  n--;
  for(int i=0;i<n;i++)
    {
      if(tmp<book[i])
	{
	  if(n>0)
	    {
	      n--;
	      tmp=wei;
	      if(tmp<book[i])
		return 0;
	    }
	  else
	    return 0;
	}
      //  printf("%d %d %d\n",n,tmp,book[i]); 
      tmp-=book[i];
    }
  return 1;
}
int main()
{
  int m,n;
  while(scanf("%d%d",&m,&n)==2)
    {
      int *book=(int *)malloc(sizeof(int)*n);
      for(int i=0;i<n;i++)
	scanf("%d",book+i);
      int l=0;
      int r=1500000;
      int ans;
      while(l<r)
	{
	  //	  printf("%d %d\n",l,r);
	  // printf("%d\n",(l+r)/2);
	  if(check(m,(l+r)/2,book))
	    {
	      ans=(l+r)/2;
	      if(r==(l+r)/2)
		break;
	      r=(l+r)/2;

	    }
	  else
	    {
	      if(l==(l+r)/2)
		break;
	      l=(l+r)/2;
	    }
	}
      printf("%d\n",ans);
      free(book);
    }
}
