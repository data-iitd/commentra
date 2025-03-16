
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
bool check(int n,int wei,vector<int> book)
{
  int tmp=wei;
  n--;
  for(int i=0;i<book.size();i++)
    {
      if(tmp<book[i])
	{
	  if(n>0)
	    {
	      n--;
	      tmp=wei;
	      if(tmp<book[i])
		return false;
	    }
	  else
	    return false;
	}
      //  cout<<n<<" "<<tmp<<" "<<book[i]<<endl; 
      tmp-=book[i];
    }
  return true;
}
int main()
{
  int m,n;
  for(;scanf("%d %d",&m,&n),m;)
    {
      vector<int> book;
      for(int i=0;i<n;i++)
	{
	  int tmp;
	  scanf("%d",&tmp);
	  book.push_back(tmp);
	}
      /*
      while(true)
	{
	  int tmp;
	  scanf("%d",&tmp);
	  if(check(m,tmp,book))
	      printf("YES\n");
	  else
	      printf("NO\n");
	}
      */

      int l=0;
      int r=1500000;
      int ans;
      while(l<r)
	{
	  //	  cout<<l<<" "<<r<<endl;
	  // cout<<(l+r)/2<<endl;
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

    }
}
