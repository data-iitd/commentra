#include <cstdio> // Include standard input/output library for basic input/output operations
#include <cstdlib> // Include standard library for general utilities such as dynamic memory allocation, conversions, and others
#include <iostream> // Include input/output stream library for reading from standard input and writing to standard output
#include <fstream> // Include file stream library for file handling
#include <sstream> // Include string stream library for string manipulation
#include <set> // Include set library for set data structure
#include <map> // Include map library for map data structure
#include <vector> // Include vector library for dynamic array
#include <list> // Include list library for linked list
#include <algorithm> // Include algorithm library for various algorithms including sort
#include <cstring> // Include string library for string manipulation
#include <cmath> // Include math library for mathematical functions
#include <string> // Include string library for string manipulation
#include <stack> // Include stack library for stack data structure
#include <queue> // Include queue library for queue data structure
#include <bitset> // Include bitset library for bit manipulation
#include <cassert> // Include assert library for debugging with assertions
#include <iomanip> // Include iomanip library for setprecision and other manipulators
#include <ctime> // Include ctime library for date and time functions
#include <complex> // Include complex library for complex number operations
using namespace std; // Use the standard namespace

#define FOR(i,b,e) for(int i=(b);i<(e);++i) // Define a macro for a for loop
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i) // Define a macro for a for loop with inclusive upper bound
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i) // Define a macro for a reverse for loop
#define REP(x, n) for(int x = 0; x < (n); ++x) // Define a macro for a simple for loop

#define ST first // Define a macro for accessing the first element of a pair
#define ND second // Define a macro for accessing the second element of a pair
#define PB push_back // Define a macro for pushing an element to the end of a vector
#define PF push_front // Define a macro for pushing an element to the front of a vector
#define MP make_pair // Define a macro for creating a pair
#define LL long long // Define a macro for long long integer type
#define ULL unsigned LL // Define a macro for unsigned long long integer type
#define LD long double // Define a macro for long double floating-point type
#define pii pair<int,int> // Define a macro for a pair of integers
#define pll pair<LL,LL> // Define a macro for a pair of long long integers
#define vi vector<int> // Define a macro for a vector of integers
#define vl vector<LL> // Define a macro for a vector of long long integers
#define vii vector<vi> // Define a macro for a vector of vector of integers
#define vll vector<vl> // Define a macro for a vector of vector of long long integers

const double pi = 3.14159265358979323846264; // Define a constant for the value of pi
const int mod=1000000007; // Define a constant for the modulo value

int main(){
    int n,m;
    cin>>n>>m; // Read the number of digits and the number of constraints
    vi s(m),c(m); // Declare vectors to store the positions and values of constraints
    FOR(i,0,m){
        cin>>s[i]>>c[i]; // Read the position and value of each constraint
        s[i]--; // Decrement the position by 1 to convert to 0-based index
    }
    FOR(i,0,1000){
        string st=to_string(i); // Convert the current number to a string
        if (st.length()!=n){ // Check if the length of the string is equal to the number of digits
            continue; // If not, continue to the next iteration
        }
        //cerr<<st<<endl; // Print the current number (for debugging purposes)
        int f=1; // Initialize a flag to 1 (true)
        FOR(j,0,m){
            if(st[s[j]]==c[j]+'0'){ // Check if the digit at the constraint position matches the constraint value
                // Do nothing (continue to the next iteration)
            }else{
                f=0; // If any constraint is not met, set the flag to 0 (false)
            }
        }
        if(f){ // Check if all constraints are met
            cout<<i<<endl; // Print the valid number
            return 0; // Exit the program
        }
    }
    cout<<-1<<endl; // If no valid number is found, print -1
}
