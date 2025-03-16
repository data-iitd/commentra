#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
//---------------------------------------------
 

int main(void)
{
    // Include necessary libraries for input/output operations, mathematical functions, and data structures
    // Define a constant PI for representing the value of π
    // Define a type alias for long long integers
    // Define a macro for a loop that iterates n times
    // Include additional libraries for sets

    int n, m;

    // Read two integers n and m from the standard input
    cin >> n >> m;

    // n represents the number of items, m represents the number of items

    int ans = 0;
    // Initialize a variable to store the result, which will be the sum of combinations

    // Calculate the number of ways to choose 2 items from n items (n choose 2)
    ans += n * (n - 1) / 2;

    // The formula for n choose 2 is n * (n - 1) / 2
    // Add this value to the answer

    // Calculate the number of ways to choose 2 items from m items (m choose 2)
    ans += m * (m - 1) / 2;

    // The formula for m choose 2 is m * (m - 1) / 2
    // Add this value to the answer

    // Output the final answer, which is the sum of combinations from n and m
    cout << ans << endl;
}

