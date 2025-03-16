

#include <bits/stdc++.h>  // Include necessary libraries

using namespace std;

int main() {
    int n;
    cin >> n;  // Read the number 'n' from the user

    int square = n * n;  // Calculate the square of the number 'n'

    vector < int > odd;  // Create an empty vector for odd numbers
    vector < int > even;  // Create an empty vector for even numbers

    for (int i = 1; i <= square; i++) {  // Loop from 1 to square
        if (i % 2 == 0) {  // If the number is even
            even.push_back(i);  // Add the number to the even vector
        } else {  // If the number is odd
            odd.push_back(i);  // Add the number to the odd vector
        }
    }

    int loop = square / n;  // Calculate the number of pairs to be printed
    int div = loop / 2;  // Calculate half of the number of pairs

    for (int i = 1; i <= loop; i++) {  // Loop through each pair
        for (int j = 0; j < div; j++) {  // Loop through half of the pair
            if (i % 2 == 1) {  // If the current pair is odd
                cout << odd.back() << " " << even.back() << " ";  // Print the first and last numbers of the current pair
                odd.pop_back();  // Remove the last number from the odd vector
                even.pop_back();  // Remove the last number from the even vector
            } else {  // If the current pair is even
                cout << even.back() << " " << odd.back() << " ";  // Print the last and first numbers of the current pair
                even.pop_back();  // Remove the last number from the even vector
                odd.pop_back();  // Remove the last number from the odd vector
            }
        }
        cout << endl;  // Print a newline after each pair
    }

    return 0;
}

