#include <algorithm>  // Include the algorithm library for sorting the vector
#include <iostream>   // Include the iostream library for input/output operations
#include <vector>      // Include the vector container from the STL
using namespace std;   // Use the standard namespace for easier access to iostream functions

int main(){
    int n, k; // Declare two integer variables, n and k, to read the number of elements and the size of the subarray from the user

    cin >> n >> k; // Read the number of elements and the size of the subarray from the user and store them in the variables n and k

    vector<int> l(n); // Declare a vector l of size n and initialize it with n default-constructed elements

    for(int i = 0; i < n; i++){ // Iterate through the elements of the vector l and read each element from the user
        cin >> l[i];
    }

    sort(l.begin(), l.end()); // Sort the vector l in ascending order

    int ans=0; // Initialize an integer variable ans to 0 for storing the sum of the first k elements in descending order

    for(int i = 0; i < k; i++){ // Iterate through the first k elements in descending order and add their values to the variable ans
        ans += l[n - 1 - i];
    }

    cout << ans << endl; // Output the value of the variable ans to the console
}
