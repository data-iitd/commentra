#include<stdio.h> // Include standard input-output header for basic I/O functions
#include<stdlib.h> // Include standard library header for general utilities
#include<iostream> // Include iostream header for C++ style I/O operations
#include<string> // Include string header for string manipulation
#include<algorithm> // Include algorithm header for using the sort function
#include<vector> // Include vector header for using dynamic arrays
#include<limits> // Include limits header for numeric limits
#include<numeric> // Include numeric header for numeric operations
#include<type_traits> // Include type_traits header for type traits
#include<math.h> // Include math header for mathematical functions
using namespace std; // Use the standard namespace to avoid prefixing standard library components with'std::'
typedef long long ll; // Define a type alias 'll' for long long integers

#define rep(i, n) for(int i = 0; i < (int)(n); i++) // Define a macro for loop iteration
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++) // Define a macro for loop iteration with start and end values
#define in(x) cin >> x // Define a macro to read input into variable 'x'
#define out(str) cout << str << endl // Define a macro to output a string followed by a newline

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; } // Define a template function to check and set maximum value
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; } // Define a template function to check and set minimum value

int L,N; // Declare global variables for the length of strings and the number of strings

int main(){
    scanf("%d %d",&N,&L); // Read the number of strings and the length of each string
    string S[N]; // Declare an array to store the strings
    rep(i,N)scanf("%s",S[i]); // Read each string and store it in the array
    sort(S,S+N); // Sort the array of strings alphabetically
    rep(i,N)printf("%s",S[i]); // Output each sorted string
    printf("\n"); // Output a newline character
}

