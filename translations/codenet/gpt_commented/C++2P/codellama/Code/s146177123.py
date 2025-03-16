#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<numeric>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>

// Macro definitions for convenience
#define rep(i,n) for(int i=0;i<n;i++) // Loop from 0 to n-1
#define all(c) (c).begin(),(c).end() // Get all elements of a container
#define mp make_pair // Create a pair
#define pb push_back // Add an element to the end of a vector
#define rp(i,c) rep(i,(c).size()) // Loop through the size of a container
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) // Iterate through a container
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl // Debugging output

using namespace std;

// Type definitions for convenience
typedef long long ll; // Define ll as long long
typedef vector<int> vi; // Define vi as a vector of integers
typedef pair<int,int> pi; // Define pi as a pair of integers
const int inf=1<<28; // Define a large integer constant
const double INF=1e12,EPS=1e-9; // Define constants for floating-point comparisons

// Segment representation for digits 0-9
bool seg[][7]={
	{0,1,1,1,1,1,1}, // 0
	{0,0,0,0,1,1,0}, // 1
	{1,0,1,1,0,1,1}, // 2
	{1,0,0,1,1,1,1}, // 3
	{1,1,0,0,1,1,0}, // 4
	{1,1,0,1,1,0,1}, // 5
	{1,1,1,1,1,0,1}, // 6
	{0,1,0,0,1,1,1}, // 7
	{1,1,1,1,1,1,1}, // 8
	{1,1,0,1,1,1,1}  // 9
};

int main()
{
	int n, t; // Declare variables for input and digit
	bool st[7]; // Array to store the state of segments

	// Read input until a negative number is encountered
	while(cin >> n, ~n) {
		rep(i, 7) st[i] = 0; // Initialize segment states to 0

		// Process each digit input
		rep(i, n) {
			cin >> t; // Read the digit
			char ans[8] = {0}; // Initialize answer array to store segment states

			// Determine the segment states based on the input digit
			rep(i, 7) {
				// Calculate the current segment state and store it in ans
				ans[i] = st[i] ^ seg[t][i] ? '1' : '0'; 
				st[i] = seg[t][i]; // Update the current segment state
			}
			cout << ans << endl; // Output the segment states for the current digit
		}
	}
	
	return 0; // Return success
}

