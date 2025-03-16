#include <iostream>
#include <limits.h> // Include headers for input/output operations and other utilities
#include <algorithm> // Include headers for algorithms like sort
#include <bitset> // Include headers for bit manipulation
#include <cctype> // Include headers for character manipulation
#include <cmath> // Include headers for mathematical functions
#include <cstdio> // Include headers for standard I/O functions
#include <cstdlib> // Include headers for general utilities like memory allocation
#include <cstring> // Include headers for string manipulation
#include <ctime> // Include headers for time-related functions
#include <deque> // Include headers for deque container
#include <functional> // Include headers for functional programming
#include <iomanip> // Include headers for input/output manipulators
#include <list> // Include headers for list container
#include <map> // Include headers for map container
#include <numeric> // Include headers for numeric operations
#include <set> // Include headers for set container
#include <sstream> // Include headers for string stream operations
#include <stack> // Include headers for stack container
#include <string> // Include headers for string operations
#include <utility> // Include headers for utility functions
#include <vector> // Include headers for vector container
#include <queue> // Include headers for queue container
#include <unordered_map> // Include headers for unordered_map container
#include <unordered_set> // Include headers for unordered_set container
#include <cassert> // Include headers for assertions

#define REP(i,n) for(int i=0;i<n;i++) // Define a macro for loop operations
#define all(x) (x).begin(),(x).end() // Define a macro for accessing all elements of a container
#define mp make_pair // Define a macro for creating pairs
#define pb push_back // Define a macro for adding elements to a vector
#define eb emplace_back // Define a macro for adding elements to a vector in a more efficient way

typedef long long ll; // Define a type alias for long long
using namespace std; // Use the standard namespace

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in); // Create a Scanner object for input
        cin.useLocale(Locale.US); // Set the locale to US English to ensure correct input
        cin.useDelimiter("\\s+"); // Set the delimiter to whitespace
        int n;cin >> n; // Read an integer n
        int[] a = new int[n];REP(i,n)cin >> a[i]; // Read n integers into a vector a
        Arrays.sort(a); // Sort the vector a
        REP(i,n-1){ // Iterate through the sorted vector to check for duplicates
            if(a[i] == a[i+1]){
                System.out.println("NO"); // If duplicates are found, print "NO" and exit
                return;
            }
        }
        System.out.println("YES"); // If no duplicates are found, print "YES"
        
        return; // Return 0 to indicate successful execution
    }
}

