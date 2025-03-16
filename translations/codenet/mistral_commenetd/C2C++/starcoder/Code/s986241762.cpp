
#include <iostream>
using namespace std;

// Declare the main function
int main(){
	int n; // Declare and initialize an integer variable 'n'
  	long sum=0; // Declare and initialize a long integer variable'sum' with zero value

  	// Read the number of elements in the array from the user
  	cout<<"Enter the number of elements in the array: ";
  	cin>>n;

  	// Declare an integer array 'a' of size 'n'
  	int a[n];

  	// Read the elements of the array from the user
  	cout<<"Enter "<<n<<" integers:\n";
  	for(int i=0;i<n;i++){
    	cout<<"Enter element number "<<i+1<<": ";
    	cin>>a[i]; // Read an integer value and store it in the array 'a'
    }

  	// Calculate the sum of the differences between adjacent elements in the array
  	for(int i=1;i<n;i++){
    	// Check if the previous element is greater than the current element
    	if(a[i-1]>a[i]){
          // If true, add the difference to the sum
          sum += a[i-1]-a[i];
          // Swap the elements to maintain the array in non-decreasing order
          a[i] = a[i-1];
        }
    }

  	// Print the sum of the differences
  	cout<<"The sum of the differences is: "<<sum<<endl;
}

