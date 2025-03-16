#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define intmax INT_MAX // Macro for maximum integer value
#define lmax LONG_MAX // Macro for maximum long integer value
#define uintmax UINT_MAX // Macro for maximum unsigned integer value
#define ulmax ULONG_MAX // Macro for maximum unsigned long integer value
#define llmax LLONG_MAX // Macro for maximum long long integer value
#define ll long long // Define long long integer type
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++) // Macro for repetition of a loop
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--) // Macro for reverse repetition of a loop
#define llfor ll i,j // Macro for loop variables declaration
#define sc(a) scanf("%d",&a) // Macro for reading an integer value from standard input
#define pr(a) printf("%d\n",a) // Macro for printing a value to standard output
#define pY puts("YES") // Macro for printing "YES" to standard output
#define pN puts("NO") // Macro for printing "NO" to standard output
#define py puts("Yes") // Macro for printing "Yes" to standard output
#define pn puts("No") // Macro for printing "No" to standard output
#define pnn printf("\n") // Macro for printing a newline character
#define all(a) a.begin(),a.end() // Macro for getting the iterator range of a container
#define push(a,b) (a).push_back(b) // Macro for adding an element to a container
#define llvec vector<vector<ll>> // Define a 2D vector of long long integers
#define charvec vector<vector<char>> // Define a 2D vector of characters
#define size(a,b) (a,vector<ll>(b)) // Macro for creating a vector of size 'b' with default value 'a'
#define llpvec vector<pair<ll,ll>> // Define a vector of pairs of long long integers
/*pi*/double pi=acos(-1); // Assign value of pi constant
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;} // Function for ceiling division
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;} // Function for finding greatest common divisor
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;} // Function for finding least common multiple
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;} // Function for exponentiation
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;} // Function for factorial calculation
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);} // Function for calculating nCr
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);} // Function for calculating nPr
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;} // Function for prime number check
/*Fibonacci数列*/ll fib(ll x){ll i,fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];} // Function for generating Fibonacci sequence
/*桁数*/ll dig(ll n){ll d=0,i=0;while(n/10>0){i++;d++;}return d;} // Function for finding number of digits
llfor;ll ans=0; // Variable declaration

int main(){
 // Main function declaration

 ll h,w; // Variables for height and width of the grid
 scanf("%lld%lld",&h,&w); // Read height and width from standard input
 char t[10],s[10]="snuke"; // Initialize character arrays 't' and 's'
 rep(i,0,h){ // Iterate through each row of the grid
  rep(j,0,w){ // Iterate through each column of the grid
   scanf("%s",t); // Read a character from standard input
   if(!strcmp(s,t)){ // Check if current character matches the pattern 'snuke'
    char c='A'+j; // Calculate the column index 'j' of the matching character and convert it to ASCII character
    printf("%c%lld\n",c,i+1); // Print the character and its row number to standard output
    return 0; // Exit the program if a match is found
   }
  }
 }

 return 0; // Return 0 if no match is found
}

