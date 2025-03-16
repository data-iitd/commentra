#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A; // initialize a vector to store integers

/* 二分探索 */
bool binarySearch(int key) { // function to perform binary search
    int left = 0; // initialize left index to 0
    int right = A.size(); // initialize right index to the last index of the vector
    int mid; // initialize middle index

    while (left < right) { // while left index is less than right index
        mid = (left + right) / 2; // calculate middle index
        if (key == A[mid]) { // if key is equal to the middle element
            return true; // return true to indicate key is found
        }
        if (key > A[mid]) { // if key is greater than the middle element
            left = mid + 1; // update left index to search in the right half
        } else { // if key is less than the middle element
            right = mid; // update right index to search in the left half
        }
    }
    return false; // if key is not found, return false
}

int main() { // main function
    int n, q, k, sum = 0; // initialize variables n, q, k, and sum

    cin >> n; // read the number of elements in the array from the standard input
    A.resize(n); // resize the vector to hold n elements
    for (int i = 0; i < n; i++) { // for loop to read and store the elements of the vector
        cin >> A[i];
    }
    
    sort(A.begin(), A.end()); // sort the vector to prepare for binary search

    cin >> q; // read the number of queries from the standard input
    for (int i = 0; i < q; i++) { // for loop to perform binary search for each query
        cin >> k;
        if (binarySearch(k)) // if key is found in the vector
            sum++; // increment sum by 1
    }
    
    cout << sum << endl; // print the number of queries with a matching element in the vector
    return 0; // return 0 to indicate successful execution of the program
}

// <END-OF-CODE>
