#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
using namespace std;
#define int long long int

// Initialize I/O streams
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Read input string from standard input
	string str;
	cin>>str;

	// Initialize sum variable to 0
	int sum=0;

	// Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
	for(char x:str)
	{
		sum+=(x-48); // Subtract 48 to convert ASCII value of digit character to its integer value
	}

	// Check if sum is divisible by 9
	if(sum%9==0)
	{
		cout<<"Yes"<<endl; // Output "Yes" if sum is divisible by 9
	}
	else
	{
		cout<<"No"<<endl; // Output "No" otherwise
	}
}

