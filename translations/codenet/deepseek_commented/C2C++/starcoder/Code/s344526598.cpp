#include<iostream> // Step 1: Include the standard input/output library.

using namespace std; // Step 2: Use the standard namespace.

int main(void) // Step 3: Define the main function.
{
	int i,j,x[10000]; // Step 4: Declare integer variables i, j, and an array x with a size of 10000.

	for(i=0;i<10000;i++){ // Step 5: Initialize the array x with zeros.
		x[i] = 0;
	}
	i=0; // Step 6: Initialize i to 0.
	cin >> x[i]; // Step 7: Read an integer from the input and store it in x[0].
	
	while(x[i]!= 0){ // Step 8: Use a while loop to read integers into the array x until a zero is entered.
		i++;
		cin >> x[i];
	}
	
	for(j=0;j<i;j++){ // Step 9: Use a for loop to print the integers stored in the array x.
		cout << "Case " << j+1 << ": " << x[j] << endl;
	}
	
	return 0; // Step 10: Return 0 to indicate successful execution.
}

