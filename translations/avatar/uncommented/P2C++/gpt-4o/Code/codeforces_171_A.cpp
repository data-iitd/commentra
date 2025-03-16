#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    // Remove the newline character at the end
    a = a.substr(0, a.size() - 1);
    b = b.substr(0, b.size() - 1);
    
    int x = max(a.size(), b.size());
    a.insert(0, x - a.size(), '0'); // Right justify a
    b.append(x - b.size(), '0'); // Left justify b
    
    string s = "";
    int c = 0; // carry
    
    for (int i = 0; i < x; i++) {
        int d = (b[i] - '0') + (a[x - i - 1] - '0') + c;
        if (d > 9) {
            s += to_string(d)[1]; // add the unit place
            c = 1; // carry over
        } else {
            s += to_string(d);
            c = 0; // no carry
        }
    }
    
    if (c == 1) {
        s += '1'; // if there's a carry left
    }
    
    // Reverse the string to get the final result
    reverse(s.begin(), s.end());
    
    // Print the result as an integer
    cout << stoi(s) << endl;

    return 0;
}

// <END-OF-CODE>
