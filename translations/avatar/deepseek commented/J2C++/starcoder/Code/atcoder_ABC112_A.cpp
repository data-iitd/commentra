
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Reading the number of inputs
    int n;
    cin >> n;

    // Processing the input based on the value of n
    if (n == 1) {
        // Outputting "Hello World" if n is 1
        cout << "Hello World" << endl;
    } else {
        // Reading two strings and calculating their sum if n is not 1
        string str1, str2;
        cin >> str1 >> str2;
        cout << stoi(str1) + stoi(str2) << endl;
    }

    // Closing the input stream
    return 0;
}

