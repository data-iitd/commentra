#include <iostream> // Include the input-output stream library
#include <vector>   // Include the vector library
#include <algorithm> // Include the algorithm library for sorting
using namespace std; // Use the standard namespace

int find(const vector<int>& li, int from, int target) { // Define the find function
    int low = from; // Initialize the lower bound of the binary search
    int upp = li.size() - 1; // Initialize the upper bound of the binary search

    if (upp < low) { // Check if the vector is empty or the target integer is less than the first element
        return 0;
    } else if (li[from] >= target) { // Check if the target integer is greater than or equal to the first element
        return 0;
    } else if (li[upp] < target) { // Check if the target integer is less than the last element
        return upp - low + 1;
    }

    while (upp - low > 1) { // Perform the binary search
        int mid = (low + upp) / 2; // Calculate the middle index of the binary search

        if (li[mid] >= target) { // If the middle element is greater than or equal to the target, update the upper bound of the search
            upp = mid;
        } else { // If the middle element is less than the target, update the lower bound of the search
            low = mid;
        }
    }

    return low - from + 1; // Return the index of the middle element minus the starting index plus one
}

int main() { // Define the main function
    int N; // Declare an integer variable N
    cin >> N; // Read the first integer N from the standard input

    vector<int> L; // Create an empty vector of integers

    for (int i = 0; i < N; i++) { // Use a for loop to read N integers from the standard input and add them to the vector
        int num;
        cin >> num;
        L.push_back(num);
    }

    sort(L.begin(), L.end()); // Sort the vector using the sort() function

    int count = 0; // Initialize a counter variable to 0

    for (int i = 0; i < N; i++) { // Use a nested for loop to iterate through all pairs of adjacent elements in the sorted vector
        for (int j = i + 1; j < N; j++) {
            int a = L[i]; // Get the first integer of the pair
            int b = L[j]; // Get the second integer of the pair
            int res = find(L, j + 1, a + b); // Call the find() function to find the number of elements greater than the sum of the pair
            count += res; // Add the result of the find() function to the counter variable
        }
    }

    cout << count << endl; // Print the final value of the counter variable to the standard output
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
