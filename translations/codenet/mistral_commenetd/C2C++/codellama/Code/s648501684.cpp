
#include <iostream>

using namespace std;

int main()
{
   long int n, k, q; // Declare and initialize three long integers n, k, and q to read input values from the user

   cin >> n >> k >> q; // Read the input values n, k, and q from the user using cin function

    int arr[n]; // Declare an integer array arr of size n

    for(long int i=0; i<=n; i++) { // Initialize the array arr with zeros using a for loop
        arr[i] = 0;
    }

    
    for(long int i=0; i<q; i++) { // Read q query values from the user and increment the corresponding index in the array arr
        long int temp;
        cin >> temp;
        arr[temp] += 1;
    }

    for(long int i=1; i<=n; i++) { // Check each index i in the array arr and print "Yes" if the count is greater than q-k, otherwise print "No"
        if(arr[i]>(q-k)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0; // Indicate the successful termination of the main function
}

