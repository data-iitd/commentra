#include <iostream>  // Importing required header for input and output
#include <vector>   // Importing required header for vector
#include <algorithm> // For std::reverse
using namespace std;

int main() {
    // Initializing input and output
    int n;
    cin >> n;  // Reading the number 'n' from the user

    int square = n * n;  // Calculating the square of the number 'n'

    vector<int> odd;  // Creating an empty vector for odd numbers
    vector<int> even; // Creating an empty vector for even numbers

    for (int i = 1; i <= square; i++) {  // Looping from 1 to square
        if (i % 2 == 0) {  // If the number is even
            even.push_back(i);  // Add the number to the even vector
        } else {  // If the number is odd
            odd.push_back(i);  // Add the number to the odd vector
        }
    }

    int loop = square / n;  // Calculating the number of pairs to be printed
    int div = loop / 2;  // Calculating half of the number of pairs

    for (int i = 1; i <= loop; i++) {  // Looping through each pair
        for (int j = 0; j < div; j++) {  // Looping through half of the pair
            if (i % 2 == 1) {  // If the current pair is odd
                cout << odd.front() << " " << even.back() << " ";  // Print the first and last numbers of the current pair
                odd.erase(odd.begin());  // Remove the first element from odd
                even.pop_back();  // Remove the last element from even
            } else {  // If the current pair is even
                cout << even.front() << " " << odd.back() << " ";  // Print the last and first numbers of the current pair
                even.erase(even.begin());  // Remove the first element from even
                odd.pop_back();  // Remove the last element from odd
            }
        }
        cout << endl;  // Printing a newline after each pair
    }

    return 0;  // Indicating successful completion
}

// <END-OF-CODE>
