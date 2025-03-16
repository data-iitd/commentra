#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define maximum values for different data types
#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long

// Macros for loop iterations
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)

// Define common types for loops
#define llfor ll i,j

// Input and output macros
#define sc(a) scanf("%lld",&a)
#define pr(a) printf("%lld\n",a)
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define all(a) a.begin(),a.end()
#define push(a,b) (a).push_back(b)

// Define vector types for convenience
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>

// Mathematical constants and utility functions
/*pi*/ double pi=acos(-1);
/* Ceiling division */ ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/* Greatest common divisor */ ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/* Least common multiple */ ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/* Power function */ ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/* Factorial function */ ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/* n choose r (combinations) */ ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/* n permute r (permutations) */ ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/* Prime number check */ bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
/* Fibonacci sequence generator */ ll fib(ll x){ll i,fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];}
/* Digit count function */ ll dig(ll n){ll d=0,i=0;while(n/10>0){i++;d++;}return d;}

// Variable declarations
llfor; 
ll ans=0;////////////////////////////////////////////////////////////

int main(){
    // Read height and width of the grid
    ll h,w;
    scanf("%lld%lld",&h,&w);

    // Initialize a temporary character array and the target string
    char t[10],s[10]="snuke";

    // Iterate through the grid to find the target string
    rep(i,0,h){
        rep(j,0,w){
            // Read the current string from input
            scanf("%s",t);
            // Check if the current string matches the target string
            if(!strcmp(s,t)){
                // If found, calculate the position and print it
                char c='A'+j; // Convert column index to character
                printf("%c%lld\n",c,i+1); // Output the position in the required format
                return 0; // Exit the program after finding the target
            }
        }
    }

    // Return 0 to indicate successful execution
    return 0;
}
