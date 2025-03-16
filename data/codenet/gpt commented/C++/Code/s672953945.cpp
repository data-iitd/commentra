// Include necessary header files
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>

// Uncomment the following lines to include Boost multiprecision libraries
/*
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/

using namespace std;

// Define long long as int for convenience
#define int long long

// Macros for loop iterations
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)

// Define a constant for modulo operation
#define MOD 1000000007

signed main() {
    // Declare a vector to store strings and variables for input
    vector<string> v;
    int N, L;

    // Read the number of strings (N) and the length of strings (L)
    cin >> N >> L;

    // Input N strings from the user and store them in the vector
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s); // Add the string to the vector
    }

    // Sort the vector of strings in lexicographical order
    sort(v.begin(), v.end());

    // Output the sorted strings
    for(int i = 0; i < v.size(); i++) {
        cout << v[i]; // Print each string in the sorted order
    }
    cout << endl; // Print a newline at the end
}
