#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input_array[1000];  // Creating an array of strings to store the input
    int result = 0;  // Initializing a variable to store the count of non-zero elements

    for (int i = 0; i < 1000; i++) {
        cin >> input_array[i];  // Reading input and storing it in the array
        result += 1;  // Incrementing the result for each element
        if (input_array[i] == "0") break;  // Breaking the loop if a zero is encountered
    }

    cout << result << "\n";  // Printing the result to the console
    return 0;
}

