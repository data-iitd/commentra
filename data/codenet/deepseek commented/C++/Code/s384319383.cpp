#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(), (v).end() // Corrected the macro to use proper syntax
#define INF 1e9
#define MOD 1e9+7
typedef long long llong;
using namespace std;

int main(){
	int n;
	cin >> n; // Read the number of characters
	vector<int> cnt(26, 1); // Initialize a vector to count occurrences of each letter, starting with 1 for each
	vector<char> s(n); // Vector to store the characters
	REP(i, n){
		cin >> s[i]; // Read each character
		cnt[s[i] - 'a']++; // Increment the count for the corresponding letter
	}

	llong ans = cnt[0]; // Initialize the answer with the count of the first letter
	for(int i = 1; i < 26; ++i){ // Loop through the counts of other letters
		ans *= cnt[i]; // Multiply the answer by the count of the current letter
		ans %= (int)MOD; // Take the modulo to prevent overflow
	}

	cout << ans - 1 << endl; // Output the result, subtracting 1 because we don't count the empty set
	return 0;
}