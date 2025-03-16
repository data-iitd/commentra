

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> li;
    int ind = 0;
    // Initialize an empty vector and a variable to keep track of the index

    for (int i = 1; i < 371; i++) {
        vector<int> temp;
        int p = i, q = i;
        int count = 0;
        // Initialize an empty temporary vector and set p and q to the current value of i
        // Initialize a counter to count the number of digits in i

        while (p!= 0) {
            p /= 10;
            count++;
        }
        // Count the number of digits in i by repeatedly dividing p by 10

        if (count == 1) {
            li.push_back(i);
        }
        // If i has 1 digit, append it to the vector li

        if (count == 2) {
            temp.clear();
            while (q!= 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }
        // If i has 2 digits, extract the digits and reverse them, then append to li

        if (count == 3) {
            temp.clear();
            while (q!= 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }
        // If i has 3 digits, extract the digits and reverse them, then append to li
    }

    li.pop_back();
    li.pop_back();
    // Remove the last two elements from li

    int n;
    cin >> n;
    // Take an integer input from the user

    cout << li[n - 1] << endl;
    // Print the nth element of li based on the user's input

    return 0;
}
// Translate the above C++ code to Java and end with comment "