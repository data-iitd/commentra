#include<stdio.h> // Include standard input-output library for basic I/O operations
#include<iostream> // Include iostream for input and output operations
#include<vector> // Include vector for dynamic array functionality
#include<math.h> // Include math library for mathematical functions
#include<queue> // Include queue for queue and priority queue functionality
#include<map> // Include map for key-value pair functionality
#include<algorithm> // Include algorithm for various algorithms including sort
#include<string.h> // Include string library for string operations
#include<functional> // Include functional for functional programming features
#include<limits.h> // Include limits for system-specific limits
#include<stdlib.h> // Include standard library for general utilities
#include<cmath> // Include cmath for mathematical functions
#include<cstring> // Include cstring for string operations
#include<set> // Include set for set data structure
#include<climits> // Include climits for system-specific limits
using namespace std; // Use the standard namespace

#define intmax INT_MAX // Define a macro for the maximum integer value
#define lmax LONG_MAX // Define a macro for the maximum long value
#define uintmax UINT_MAX // Define a macro for the maximum unsigned int value
#define ulmax ULONG_MAX // Define a macro for the maximum unsigned long value
#define llmax LLONG_MAX // Define a macro for the maximum long long value
#define ll long long // Define a macro for long long type
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++) // Define a macro for a loop
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--) // Define a macro for a reverse loop
#define llfor ll i,j // Define a macro for a loop with long long variables
#define sc(a) scanf("%s",a) // Define a macro for input
#define pr(a) printf("%s\n",a) // Define a macro for output
#define pY puts("YES") // Define a macro for outputting "YES"
#define pN puts("NO") // Define a macro for outputting "NO"
#define py puts("Yes") // Define a macro for outputting "Yes"
#define pn puts("No") // Define a macro for outputting "No"
#define pnn printf("\n") // Define a macro for printing a newline
#define all(a) a.begin(),a.end() // Define a macro for getting all elements of a container
#define push(a,b) (a).push_back(b) // Define a macro for pushing an element into a container
#define llvec vector<vector<ll>> // Define a type alias for a vector of vector of long long
#define charvec vector<vector<char>> // Define a type alias for a vector of vector of char
#define size(a,b) (a,vector<ll>(b)) // Define a macro for creating a vector of long long of size a*b
#define llpvec vector<pair<ll,ll>> // Define a type alias for a vector of pairs of long long
/*pi*/double pi=acos(-1); // Define a constant for pi
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;} // Define a function for ceiling division
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;} // Define a function for greatest common divisor
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;} // Define a function for least common multiple
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;} // Define a function for power
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;} // Define a function for factorial
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);} // Define a function for nCr
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);} // Define a function for nPr
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;} // Define a function for prime check
/*Fibonacci数列*/ll fib(ll x){ll i,fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];} // Define a function for Fibonacci sequence
/*桁数*/ll dig(ll n){ll d=0,i=0;while(n/10>0){i++;d++;}return d;} // Define a function for digit count
llfor;ll ans=0;////////////////////////////////////////////////////////////
int main(){
 ll h,w;
 scanf("%lld%lld", &h, &w); // Read the dimensions of the grid
 char t[10],s[10]="snuke";
 rep(i,0,h){ // Loop over each row
  rep(j,0,w){ // Loop over each column
   scanf("%s",t); // Read a character array
   if(!strcmp(s,t)){ // Compare the character array with the pattern
    char c='A'+j; // Calculate the column letter
    printf("%c%lld\n",c,i+1); // Output the position in the grid
    return 0; // Terminate the program
   }
  }
 }

return 0;} // End of main function

