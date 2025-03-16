
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Main method that starts the program
int main() {
    string x; // String to store the input string
    stack<char> s; // Stack to store characters
    int c; // Counter to store the number of pairs

    cin >> x; // Reading the input string
    s = stack<char>(); // Creating an empty stack
    c = 0; // Initializing the counter to zero

    // Iterating through each character in the input string
    for (int i = 0; i < x.length(); i++) {
        s.push(x.at(i)); // Pushing the character onto the stack

        // Popping two characters from the stack and checking for a pair
        while (s.size() > 1) {
            char p = s.top(); // Popping the top character
            s.pop();
            char q = s.top(); // Popping the second top character
            s.pop();

            // If the popped characters form a pair, increment the counter and continue
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++;
                continue;
            }

            // If the characters don't form a pair, push them back onto the stack and break
            s.push(q);
            s.push(p);
            break;
        }
    }

    // Writing the output to the console
    cout << c * 2 << endl;

    return 0;
}

