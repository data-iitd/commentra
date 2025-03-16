/*
 * InsertionSort.cpp
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
#include <iostream>
#include <vector>
using namespace std;

// Function prototype for the sorting function
void sort(vector<int>& a_rvecIntValue);

int main(void) {
    // Variable to hold the number of integers to be sorted
    int iNum = 0;
    // Read the number of integers from standard input
    cin >> iNum;
    
    // Vector to store the integers
    vector<int> vecIntValue;
    
    // Loop to read integers from input and store them in the vector
    while (iNum) {
        int iIntValue = 0;
        cin >> iIntValue; // Read an integer
        vecIntValue.push_back(iIntValue); // Add the integer to the vector
        iNum--; // Decrement the count of integers to read
    }

    // Call the sort function to sort the vector of integers
    sort(vecIntValue);

    return 0; // Exit the program
}

// Function to perform insertion sort on the vector of integers
void sort(vector<int>& a_rvecIntValue) {
    // Iterate through each element in the vector
    for (unsigned int i = 0; i < a_rvecIntValue.size(); i++) {
        // Check if we are not at the first element
        if (i != 0) {
            // Store the current element to be inserted
            int iIntValue = a_rvecIntValue.at(i);
            int j = i - 1; // Start comparing with the previous element
            
            // Move elements of a_rvecIntValue[0..i-1], that are greater than iIntValue,
            // to one position ahead of their current position
            while ((j >= 0) && (a_rvecIntValue.at(j) > iIntValue)) {
                a_rvecIntValue.at(j + 1) = a_rvecIntValue.at(j); // Shift element to the right
                j--; // Move to the previous element
            }
            // Place the current element at its correct position
            a_rvecIntValue.at(j + 1) = iIntValue;
        }

        // Print the current state of the sorted portion of the vector
        for (unsigned int k = 0; k < a_rvecIntValue.size(); k++) {
            cout << a_rvecIntValue.at(k); // Output the element
            // Print a space between elements, but not after the last element
            if (k != a_rvecIntValue.size() - 1) {
                cout << " ";
            }
        }
        cout << endl; // New line after printing the current state
    }
}
