
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<map>
#include<set>
#define re register
#define ll long long
#define inf 0x3f3f3f3f
#define mod 100000007
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define rep(i,a,b) for(re int i=(a);i<=(b);++i)
#define per(i,a,b) for(re int i=(a);i>=(b);--i)
using namespace std;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
  // Read the number of elements
  int N;
  scanf("%d", &N);

  // Initialize an array to store the elements
  int A[N];

  // Input the elements into the array
  for(int i = 0; i < N; ++i) scanf("%d", &A[i]);

  // Sort the array in descending order
  sort(A, A + N, greater<int>());

  // Initialize variables to track the minimum difference and the corresponding index
  int index;
  int max = inf;

  // Find the element in the array that minimizes the difference with twice the second largest element
  for(int i = 1; i < N; ++i) {
    // Calculate the absolute difference and update if it's smaller than the current max
    if(max > abs(A[0] - 2 * A[i])) {
      max = abs(A[0] - 2 * A[i]);
      index = i; // Store the index of the element that gives the minimum difference
    }
  }

  // Output the largest element and the element that minimizes the difference
  printf("%d %d\n", A[0], A[index]);
}


