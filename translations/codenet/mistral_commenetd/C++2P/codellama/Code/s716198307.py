#include<iostream>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<algorithm>
#include<functional>
using namespace std;

#include<iostream>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<algorithm>
#include<functional>
using namespace std;

// The main function from where the execution begins
int main(void){
    // Declare variables
    int n;          // Number of elements in the array
    double avg;     // Average of the elements in the array
    double s;       // Difference between the first element and the average
    double ans;     // Index of the element with the maximum difference from the average

    // Initialize variables
    cin >> n;       // Read the number of elements from the standard input
    int a[100];     // Declare and initialize an array of size 100 with zeros

    // Calculate the average of the elements in the array
    for(int i = 0; i < n; i++){
        cin >> a[i]; // Read an element from the standard input and store it in the array
        avg += a[i]; // Add the current element to the sum of all elements
    }

    // Calculate the average and divide it by the number of elements
    avg /= n;

    // Initialize the difference between the first element and the average
    s = abs(a[0] - avg);

    // Initialize the index of the element with the maximum difference from the average
    ans = 0;

    // Find the index of the element with the maximum difference from the average
    for(int i = 1; i < n; i++){
        if(s > abs(a[i] - avg)){ // If the current difference is greater than the previous difference
            s = abs(a[i] - avg); // Update the difference
            ans = i;            // Update the index
        }
    }

    // Print the index of the element with the maximum difference from the average
    cout << ans << endl;

    // Terminate the program
    return 0;
}


