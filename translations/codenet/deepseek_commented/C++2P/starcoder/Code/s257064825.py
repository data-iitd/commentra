#include<iostream>          # Include input/output stream library
#include<algorithm>         # Include algorithms library
#include<vector>            # Include vector container library
#include<set>               # Include set container library
#include<map>               # Include map container library
#include<cmath>             # Include mathematical functions library
using namespace std;         # Use standard namespace
#define int long long int   # Define a custom integer type

int32_t main()
{
	ios_base::sync_with_stdio(false);  # Optimize input/output streams
	cin.tie(NULL);                     # Disable synchronization between cin and cout
	cout.tie(NULL);                    # Disable synchronization between cout and cin
	string str;                        # Declare a string variable to store input
	cin>>str;                          # Read input string
	int sum=0;                         # Initialize sum variable to store the sum of digits
	for(char x:str)                    # Iterate over each character in the string
	{
		sum+=(x-48);                    # Convert character to integer and add to sum
	}
	if(sum%9==0)                       # Check if sum is divisible by 9
	{
        cout<<"Yes"<<endl;             # Print "Yes" if sum is divisible by 9
	}
	else                               # Otherwise
	   cout<<"No"<<endl;               # Print "No"
}
