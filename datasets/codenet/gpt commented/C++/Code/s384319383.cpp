#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

// Macro definitions for convenience
#define REP(i,n) for(int i=0;i<(n);++i) // Macro for a loop from 0 to n-1
#define ALL(v) (v).begin(),(v).end() // Macro to get the beginning and end of a vector
#define INF 1e9 // Definition of infinity
#define MOD 1e9+7 // Definition of modulus for large number calculations

typedef long long llong; // Type alias for long long
using namespace std;

int main(){
    int n; // Variable to store the number of characters
    cin >> n; // Input the number of characters

    // Initialize a vector to count occurrences of each character (a-z)
    vector<int> cnt(26, 1); // Start with 1 to account for the multiplication later
    vector<char> s(n); // Vector to store the input characters

    // Read characters and count their occurrences
    REP(i, n){
        cin >> s[i]; // Input each character
        cnt[s[i] - 'a']++; // Increment the count for the corresponding character
    }

    llong ans = cnt[0]; // Initialize answer with the count of 'a'
    
    // Calculate the product of counts for all characters from 'b' to 'z'
    for(int i = 1; i < 26; ++i){
        ans *= cnt[i]; // Multiply the current answer by the count of the character
        ans %= (int)MOD; // Take modulo to prevent overflow
    }

    // Output the final result, subtracting 1 to exclude the empty product case
    cout << ans - 1 << endl; 
    return 0; // End of the program
}
