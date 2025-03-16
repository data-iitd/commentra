#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n + 1];

    // Populating the array with integers from the user input
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }

    int odd = 0, even = 0, odd_ind = 0, even_ind = 0; // Initializing variables to count odd and even numbers and their indices

    // Counting the number of odd and even numbers and recording their indices
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) {
            even++;
            even_ind = i;
        } else {
            odd++;
            odd_ind = i;
        }
    }

    // Comparing the counts of odd and even numbers and printing the index of the majority
    if (odd > even) {
        cout << even_ind << endl;
    } else {
        cout << odd_ind << endl;
    }

