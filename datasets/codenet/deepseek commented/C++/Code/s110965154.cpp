/*
 * InsertionSort.cpp
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
#include <iostream>
#include <vector>
using namespace std;

// Step 1: Include necessary headers
// The code includes <iostream> and <vector> which are necessary for input and vector operations.

void sort(vector<int>& a_rvecIntValue);

// Step 2: Define the sort function
// The `sort` function is defined to take a reference to a vector of integers.

int main(void) {

    // Step 3: Main function
    // The main function reads the number of integers to be sorted.
    // It then reads each integer and stores them in a vector.
    // It calls the `sort` function with the vector.

    int iNum = 0;
    cin >> iNum;
    vector<int> vecIntValue;
    while (iNum) {
        int iIntValue = 0;
        cin >> iIntValue;
        vecIntValue.push_back(iIntValue);
        iNum--;
    }

    sort(vecIntValue);

    return 0;
}

void sort(vector<int>& a_rvecIntValue) {

    // Step 4: Sort function implementation
    // The sort function uses the insertion sort algorithm.
    // It iterates through the vector, inserting each element in the correct position.
    // It prints the vector after each insertion to show the progress of the sorting process.

    for (unsigned int i = 0; i < a_rvecIntValue.size(); i++) {

        // If it's not the first element, insert it in the correct position
        if (i != 0) {
            int iIntValue = a_rvecIntValue.at(i);
            int j = i - 1;
            while ((j >= 0) && (a_rvecIntValue.at(j) > iIntValue)) {
                a_rvecIntValue.at(j+1) = a_rvecIntValue.at(j);
                j--;
            }
            a_rvecIntValue.at(j+1) = iIntValue;
        }

        // Print the vector after each insertion
        for (unsigned int k = 0; k < a_rvecIntValue.size(); k++) {
            cout << a_rvecIntValue.at(k);
            if (k != a_rvecIntValue.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Step 5: Output
// The program outputs the sorted vector after each insertion.
