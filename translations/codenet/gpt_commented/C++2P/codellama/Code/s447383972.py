#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)  // Macro for a for loop from x to y
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)  // Macro for a for loop from x to y in reverse
using namespace std;

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)  // Macro for a for loop from x to y
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)  // Macro for a for loop from x to y in reverse
using namespace std;

// Function to read a long long integer from input
inline ll read(){   
    ll x=0, f=1; 
    char ch=getchar();   
    // Read characters until a digit or '-' is found
    while(ch<'0'||ch>'9'){ 
        if(ch=='-') f=-1; // Check for negative sign
        ch=getchar();
    }  
    // Convert the digits to a long long integer
    while(ch>='0'&&ch<='9'){ 
        x=x*10+ch-'0'; 
        ch=getchar();
    }  
    return x*f; // Return the final value with sign
} 

// Function to write a long long integer to output
inline void write(ll x){    
    if (x<0) putchar('-'), x=-x; // Print negative sign if needed
    if (x>=10) write(x/10);   // Recursively write the digits
    putchar(x%10+'0');  // Print the last digit
} 

// Function to write a long long integer followed by a newline
inline void writeln(ll x){ 
    write(x);   
    puts("");   // Print a newline
}

const ll N=200010; // Define a constant for the maximum size of the array
ll a[N], q[N], n, tot; // Declare arrays and variables

int main(){
    n=read(); // Read the number of elements
    For(i,1,n) a[i]=read(); // Read the elements into the array a
    sort(a+1,a+n+1); // Sort the array in non-decreasing order

    // Identify duplicates and store them in array q
    For(i,1,n) 
        if (a[i]==a[i+1]) 
            q[++tot]=a[i], i++; // Store the duplicate and skip the next element

    // Output the product of the last two duplicates found
    writeln(q[tot]*q[tot-1]);
}

