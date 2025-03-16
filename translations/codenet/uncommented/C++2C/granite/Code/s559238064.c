
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#define re register
#define ll long long
#define inf 0x3f3f3f3f
#define mod (1? 1e9 + 7 : 998244353)
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T> inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T> inline void pr1(T x){write(x);putchar(' ');}
template<typename T> inline void pr2(T x){write(x);putchar('\n');}
char s[100010];
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(re int i=1;i<n;++i)
		if(s[i]==s[i+1]){puts("Bad");return 0;}
	puts("Good");
	return 0;
}
