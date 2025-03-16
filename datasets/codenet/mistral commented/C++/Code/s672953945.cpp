//#include<bits/stdc++.h> // This line is an include guard for standard C++ libraries
#include<iostream>      // Input/Output stream library
#include<algorithm>     // Standard template library for algorithms
#include<cmath>         // Mathematical functions library
#include<vector>         // Vector container library
#include<queue>          // Queue container adapter library
#include<set>            // Set container adapter library

/*
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/
// Uncomment this block if you want to use Boost Multiprecision Library for large numbers

using namespace std; // Using the std namespace for simplicity

#define int long long // Define int as long long for larger input handling
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++) // A macro for repetition of a loop
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--) // A macro for repetition of a loop in reverse
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++) // A macro for iteration through a container
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--) // A macro for iteration through a container in reverse
#define MOD 1000000007 // Define MOD for modular arithmetic

// The main function begins here
signed main(){

    // Initialize an empty vector 'v' of strings
    vector<string> v;

    // Read the number of strings 'N' and their lengths 'L' from the standard input
    cin>>N>>L;

    // Allocate memory for 'N' strings in the vector 'v'
    for(int i=0;i<N;i++){
        // Read a string 's' from the standard input and push it back into the vector 'v'
        string s;
        cin>>s;
        v.push_back(s);
    }

    // Sort the strings in the vector 'v' in ascending order using the 'sort' function
    sort(v.begin(),v.end());

    // Iterate through the sorted strings in the vector 'v' and print each string to the standard output
    for(int i=0;i<v.size();i++){
        // Print the current string from the vector 'v' to the standard output
        cout<<v[i];
    }

    // Print a newline character at the end of the output
    cout<<endl;
}
