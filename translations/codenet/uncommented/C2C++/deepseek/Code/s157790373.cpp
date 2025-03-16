#include<iostream>
#define LEN 300
#define TRUE 1
#define FALSE -1

using namespace std;

int solve(int, int);
int n, A[LEN];
int flag;

int main()
{
  int q, M;
  int i, j, k;

  cin >> n;
  for(i=0; i<n; i++)cin >> A[i];

  cin >> q;
  for(i=0; i<q; i++)
    {
      cin >> M;
      flag=FALSE;

      solve(-1, M);
      if(flag==TRUE)cout << "yes" << endl;
      else cout << "no" << endl;
    }


  return 0;
}

int solve(int i, int m)
{
  if(i>n)return FALSE;
  else if(m<0)return FALSE;
  else if(m==0 || m-A[i+1]==0)
    {
      flag=TRUE;
      return TRUE;
    }
  else
    {
      //not use A[i]
      solve(i+1, m);
      //use A[i]
      solve(i+1, m-A[i]);
    }
}

