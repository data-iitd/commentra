
#include <iostream>
using namespace std;
typedef long long ll;
ll n, k, ans, L, ans2;
string s;

// Input the number of strings and the maximum number of occurrences of a character allowed
int main(void){
    // Read the number of strings and the maximum number of occurrences of a character allowed from the standard input
    cin >> n >> k;

    // Read the string from the standard input
    cin >> s;

    // Initialize the length of the first character and the counter for the current character
    L = s[0];
    ll cnt = 0;

    // Iterate through the string starting from the second character
    for(int i = 1; i < n; i++){
        // If the current character is the same as the previous character, increment the counter
        if(L == s[i]){
            cnt++;
        }
        // If the current character is different from the previous character, update the answer and reset the counter
        else {
            // Update the answer with the sum of the count of the previous character and the number of times the previous character appeared in the string
            ans += cnt;
            ans2++;
            // Reset the counter for the new character
            cnt = 0;
            // Update the length of the current character
            L = s[i];
        }
    }

    // Update the answer with the count of the last character and the number of times it appeared in the string
    ans += cnt;
    ans2++;

    // Output the answer with the minimum of twice the number of allowed occurrences and the number of unique characters in the string minus one
    cout << ans + min(2 * k, ans2 - 1) << endl;
}