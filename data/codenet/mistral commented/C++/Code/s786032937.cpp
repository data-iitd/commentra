
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;

// Declare an integer variable 'n' and read its value from the standard input
int main()
{
	int n;
	cin >> n;

	// Output the result, which is calculated as (n - 2) * 180
	cout << (n - 2) * 180 << endl;

	// Indicate successful termination of the program by returning 0
	return 0;
}