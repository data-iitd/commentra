#include <iostream>
#include <vector>
using namespace std;

// Function to perform counting sort algorithm
void CountingSort(vector<int>& a, vector<int>& b, int k) {
    const int I = 10000; // Define the size for counting array
    vector<int> c(I + 1, 0); // Initialize count array with zeros

    // Count the occurrences of each element in array 'a'
    for (int j = 0; j < k; j++) {
        c[a[j + 1]]++;
    }

    // Calculate the cumulative sum of all elements in array 'c'
    for (int i = 1; i <= I; i++) {
        c[i] += c[i - 1];
    }

    // Sort the array 'b' by placing each element 'a[j]' at its correct position in array 'b'
    for (int j = k; j > 0; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

// Main function starts here
int main() {
    // Declare vectors 'a' and 'b' of integer type
    vector<int> a, b;
    int max = 0, n;

    // Read the number of elements 'n' from the user
    cout << "Enter the number of elements: ";
    cin >> n;

    // Resize vectors 'a' and 'b' to size (n+1)
    a.resize(n + 1);
    b.resize(n + 1);

    // Read elements of array 'a' from the user
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
        // Update the maximum element if a new element is greater
        if (a[i + 1] > max) max = a[i + 1];
    }

    // Call the CountingSort function to sort the array 'a' using counting sort algorithm
    CountingSort(a, b, n);

    // Print the sorted elements of array 'b'
    cout << b[1];
    for (int i = 2; i < n + 1; i++) {
        cout << " " << b[i];
    }
    cout << endl;

    // Main function ends here
    return 0;
}

// <END-OF-CODE>
