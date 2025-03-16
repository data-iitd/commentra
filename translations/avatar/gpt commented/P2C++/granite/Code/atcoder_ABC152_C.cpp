
#include <iostream>  // Importing the standard input/output library
#include <vector>  // Importing the vector library for dynamic arrays

using namespace std;  // Using the standard namespace

int main() {
    int N;  // Declaring the variable 'N' to store the number of elements
    cout << "Enter the number of elements: ";  // Asking the user to enter the number of elements
    cin >> N;  // Taking input for the number of elements

    vector<int> n(N);  // Creating a dynamic array 'n' to store the elements
    cout << "Enter the elements separated by spaces: ";  // Asking the user to enter the elements
    for (int i = 0; i < N; i++) {
        cin >> n[i];  // Taking input for each element and storing it in the array
    }

    int a = 1;  // Initializing the counter 'a' to count the number of elements that are less than the current element
    int pos = 0;  // Initializing 'pos' to keep track of the position of the last element that was smaller

    for (int i = 1; i < N; i++) {  // Looping through the array starting from the second element
        if (n[pos] > n[i]) {  // Checking if the current element is smaller than the element at 'pos'
            a++;  // Incrementing the counter if the condition is met
            pos = i;  // Updating 'pos' to the current index
        }
    }

    cout << a << endl;  // Printing the final count of elements that were smaller than the previous ones

    return 0;  // Returning 0 to indicate successful execution
}
