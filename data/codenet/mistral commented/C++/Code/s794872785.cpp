#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

// Function to solve the problem
bool solve(){
	// Initialize variables
	int maxsize = 0;
	int maxcnt = 0;
	int ans_num = -1;
	int ans_num2 = -1;
	vector<string> str_v; // Vector to store strings read from input

	// Read strings from input
	string in;
	while(cin>>in){
		// Push the string into the vector
		str_v.push_back(in);
		// Update maxsize if the current string is larger
		if(maxsize < in.size()){
			maxsize = in.size();
			ans_num = str_v.size()-1;
		}
	}

	// Find the string with maximum occurrences in the vector
	for(int i=0;i<str_v.size();i++){
		int cnt = 0;
		// Count the occurrences of the current string in the vector
		for(int j=0;j<str_v.size();j++){
			if(str_v[i] == str_v[j]) cnt++;
		}
		// Update maxcnt and ans_num2 if the current string has more occurrences
		if(maxcnt < cnt){
			maxcnt = cnt;
			ans_num2 = i;
		}
	}

	// Print the answer
	cout<< str_v[ans_num2]<< " "<< str_v[ans_num]<< endl;

	// Return true to indicate successful execution
	return true;
}

// Main function
int main(){
	// Set the precision of cout to 10 decimal places
	cout.setf(ios::fixed);
	cout.precision(10);
	// Call the solve function
	solve();

	// Return 0 to indicate successful execution
	return 0;
}
