
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }

const ll N=200010;
ll a[N],q[N],n,tot;
int main(){
    // Step 7: Main function
    n=read(); // Read the size of the array.
    For(i,1,n)    a[i]=read(); // Read the elements of the array.
    sort(a+1,a+n+1); // Sort the array.
    For(i,1,n)    if (a[i]==a[i+1])    q[++tot]=a[i],i++; // Remove duplicates from the array.
    writeln(q[tot]*q[tot-1]); // Print the product of the two largest distinct elements.
}
