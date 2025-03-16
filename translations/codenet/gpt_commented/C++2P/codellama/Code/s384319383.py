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

    # <START-OF-CODE>
    # Initialize a vector to count occurrences of each character (a-z)
    cnt = [1] * 26
    s = [None] * n

    # Read characters and count their occurrences
    for i in range(n):
        s[i] = input()
        cnt[ord(s[i]) - ord('a')] += 1

    ans = cnt[0]
    
    # Calculate the product of counts for all characters from 'b' to 'z'
    for i in range(1, 26):
        ans *= cnt[i]
        ans %= MOD

    # Output the final result, subtracting 1 to exclude the empty product case
    print(ans - 1)
    # 