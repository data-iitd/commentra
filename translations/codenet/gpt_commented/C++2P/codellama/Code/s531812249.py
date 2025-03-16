#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
using namespace std;

// Define a constant for the value of PI
#define PI 3.14159265358979

// Define a type alias for long long
typedef long long ll;

// Macro to simplify loop creation
#define rep(i,n) for(int i=0;i<n;i++)

#include<set>

//---------------------------------------------

int main(void)
{
    // Declare variables to hold the number of groups
    int n, m;

    // Input the number of groups n and m
    cin >> n >> m;

    // Initialize the answer variable to store the total pairs
    int ans = 0;

    // Calculate the number of pairs within group n
    // The formula n*(n-1)/2 gives the number of ways to choose 2 from n
    ans += n * (n - 1) / 2;

    // Calculate the number of pairs within group m
    // Similarly, m*(m-1)/2 gives the number of ways to choose 2 from m
    ans += m * (m - 1) / 2;

    // Output the total number of pairs
    cout << ans << endl;

    return 0; // Return 0 to indicate successful execution
}


