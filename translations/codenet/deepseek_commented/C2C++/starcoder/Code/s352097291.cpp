#include <iostream>
#include <string>

using namespace std;

int main(){
    string c, ans = ""; // Declare string variables c and ans
    cin >> c; // Read input string into c

    // Process the input string
    for (int i = 0; i < c.length(); i++) {
        if (c[i]!= 'B')
            ans += c[i]; // Append character to ans if not 'B'
        else
            ans.pop_back(); // Remove last character from ans if 'B'
    }

    cout << ans << endl; // Output the result string ans
}

