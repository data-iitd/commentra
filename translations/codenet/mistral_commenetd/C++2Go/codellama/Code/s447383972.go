// Including necessary header files
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

// Macros for iteration
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)

// Function prototypes and necessary definitions
inline ll read();
inline void write(ll x);
inline void writeln(ll x);
const ll N=200010;
ll a[N],q[N],n,tot;

// Main function
int main(){

	// Reading input
	n=read();

	// Reading array 'a'
	For(i,1,n)	a[i]=read();

	// Sorting array 'a' in ascending order
	sort(a+1,a+n+1);

	// Finding duplicate elements and storing them in 'q'
	For(i,1,n)	// Iterating through array 'a'
		if (a[i]==a[i+1])	// Checking if current element is same as next element
			q[++tot]=a[i],	// If yes, storing it in 'q'
			i++;		// Incrementing index 'i'

	// Outputting the result
	writeln(q[tot]*q[tot-1]);

	// End of main function
	return 0;
}

// Function definitions
inline ll read(){
	ll x=0;
	char c=getchar();
	while(c<'0'||c>'9')	c=getchar();
	while(c>='0'&&c<='9')	x=x*10+c-'0',c=getchar();
	return x;
}
inline void write(ll x){
	if(x==0)	putchar('0');
	if(x<0)		putchar('-'),x=-x;
	while(x>0)	putchar(x%10+'0'),x/=10;
}
inline void writeln(ll x){
	write(x),putchar('\n');
}

// End of code
