
/*
 * InsertionSort.cpp
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
#include <iostream>
#include <vector>
using namespace std;
 
// Function to sort the vector in ascending order using insertion sort algorithm
void sort(vector<int>& a_rvecIntValue);
 
int main(void) {
 
    int iNum = 0; // Initialize a variable to store the number of elements in the vector
    cin >> iNum; // Read the number of elements from the standard input
 
    vector<int> vecIntValue; // Create an empty vector to store the integers
    while (iNum) {
        int iIntValue = 0; // Initialize a variable to store the next integer to be added to the vector
        cin >> iIntValue; // Read the next integer from the standard input
        vecIntValue.push_back(iIntValue); // Add the integer to the vector
        iNum--; // Decrement the counter
    }
 
    // Call the sorting function to sort the vector
    sort(vecIntValue);
 
    return 0;
}
 
void sort(vector<int>& a_rvecIntValue) {
 
    // Iterate through each element in the vector starting from the second element
    for (unsigned int i = 0; i < a_rvecIntValue.size(); i++) {
        if (i != 0) { // Check if we are not at the first element
 
            int iIntValue = a_rvecIntValue.at(i); // Get the value of the current element
            int j = i - 1; // Initialize a variable to store the index of the previous element
            while ((j >= 0) && (a_rvecIntValue.at(j) > iIntValue)) { // While the previous element is greater than the current element
                a_rvecIntValue.at(j+1) = a_rvecIntValue.at(j); // Swap the previous and next elements
                j--; // Decrement the index of the previous element
            }
            a_rvecIntValue.at(j+1) = iIntValue; // Place the current element at its correct position
        }
 
        // Print the sorted vector after each insertion
        for (unsigned int k = 0; k < a_rvecIntValue.size(); k++) {
            cout << a_rvecIntValue.at(k); // Print the value of the current element
            if (k != a_rvecIntValue.size() - 1) { // Check if we are not at the last element
                cout << " "; // Print a space if not
            }
        }
        cout << endl; // Print a newline after each pass
    }
}