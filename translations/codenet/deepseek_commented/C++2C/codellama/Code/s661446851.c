/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <stdio.h> // Include the Standard Input/Output library
#include <stdlib.h> // Include the Standard Library for using malloc, calloc, etc.
#include <math.h> // Include the Math library for mathematical functions
#include <string.h> // Include the String library for C-style strings
#include <stdbool.h> // Include the Boolean library for using true, false, etc.
#define   mod  998244353 // Define a constant for modulo arithmetic
#define   int  long long // Define a macro for long long integers
#define   ld   long double // Define a macro for long double precision floating-point numbers
#define   pb   push_back // Define a macro for vector push_back
#define   vi   vector<int> // Define a macro for vector of integers
#define   co(x)  printf("%d\n",x) // Define a macro for outputting a line with x
#define   dbg(x)  printf("%s = %d\n",#x,x) // Define a macro for debugging output
#define   bitcount(x)  (int)__builtin_popcount(x) // Define a macro for counting the number of set bits in x
#define   sz(x)  (int)x.size() // Define a macro for getting the size of x
#define   all(a) a.begin(),a.end() // Define a macro for getting iterators to the beginning and end of a container a
#define   ff   first // Define a macro for accessing the first element of a pair
#define   ss   second // Define a macro for accessing the second element of a pair
#define   pii  pair<int,int> // Define a macro for a pair of integers
#define   lcm(a,b) (a*b)/__gcd(a,b) // Define a macro for calculating the least common multiple
typedef   long long ll; // Define a type alias for long long integers
typedef   long double ld; // Define a type alias for long double precision floating-point numbers
typedef   pair<int,int> pii; // Define a type alias for a pair of integers
typedef   vector<int> vi; // Define a type alias for vector of integers
typedef   vector<pii> vpii; // Define a type alias for vector of pairs of integers
typedef   vector<vi> vvi; // Define a type alias for vector of vectors of integers
typedef   vector<vpii> vvpii; // Define a type alias for vector of vectors of pairs of integers
typedef   vector<vvi> vvvi; // Define a type alias for vector of vectors of vectors of integers
typedef   vector<vvpii> vvvpii; // Define a type alias for vector of vectors of vectors of pairs of integers
typedef   vector<vvvi> vvvvi; // Define a type alias for vector of vectors of vectors of vectors of integers
typedef   vector<vvvpii> vvvvpii; // Define a type alias for vector of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvi> vvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvpii> vvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvi> vvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvpii> vvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvi> vvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvpii> vvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvi> vvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvpii> vvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvi> vvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvpii> vvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvi> vvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvpii> vvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvi> vvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvpii> vvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvi> vvvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvvpii> vvvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvvi> vvvvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvvvpii> vvvvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvvvi> vvvvvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvvvvpii> vvvvvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvvvvvpii> vvvvvvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvvvvvvpii> vvvvvvvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvvvvvvvpii> vvvvvvvvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvvvvvvvvpii> vvvvvvvvvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvvvvvvvvvpii> vvvvvvvvvvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvvvvvvi; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of integers
typedef   vector<vvvvvvvvvvvvvvvvvvvpii> vvvvvvvvvvvvvvvvvvvvpii; // Define a type alias for vector of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of vectors of pairs of integers
typedef   vector<vvvvvvvvvvvvvvvvvvvvi> vvvvvvvvvvvvvvvvvvvvvi; // Define a