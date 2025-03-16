
#include <iostream>

using namespace std;

// Declare variables
int a[10000], min, max, n, i;
long long sum = 0;

int main()
{
// Read the number of elements in the array
cout << "Enter the number of elements in the array: ";
cin >> n;

// Initialize a for loop to read elements into the array and calculate sum
for(i = 0; i < n; i++){
// Read each element into the array
cout << "Enter element " << i + 1 << ": ";
cin >> a[i];

// Add the current element to the sum
sum += a[i];
}

// Initialize a for loop to find minimum and maximum elements in the array
for(i = 1; i < n; i++){
// Initialize min and max with the first element of the array
if(a[i] > max)max = a[i];
if(a[i] < min)min = a[i];
}

// Print the minimum, maximum, and sum
cout << "Minimum element is " << min << endl;
cout << "Maximum element is " << max << endl;
cout << "Sum of all elements is " << sum << endl;

// Return 0 to indicate successful execution
return 0;
}

