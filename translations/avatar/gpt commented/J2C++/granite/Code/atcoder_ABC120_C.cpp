
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;
    stack<char> s;
    int c = 0; // Counter for pairs of '0' and '1'

    for (int i = 0; i < x.length(); i++) {
        s.push(x[i]);

        while (s.size() > 1) {
            char p = s.top();
            s.pop();
            char q = s.top();
            s.pop();

            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++; // Increment the counter for valid pairs
                continue; // Continue to check for more pairs
            } else {
                s.push(q);
                s.push(p);
                break; // Exit the while loop
            }
        }
    }

    cout << c * 2 << endl; // Output the result, which is twice the count of pairs found

    return 0;
}

