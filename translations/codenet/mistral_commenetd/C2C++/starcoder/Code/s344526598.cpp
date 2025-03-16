#include<iostream>

using namespace std;

// Declare variables
int i, j, x[10000];

int main(void)
{
	// Initialize array x with zeros
	for(i=0;i<10000;i++){
		x[i] = 0;
		// Comment explaining what the loop does
		// This loop initializes all elements of the array x with zero
	}

	i = 0;
	// Read the first integer input and store it in the array x at index i
	cin>>x[i];
	// Comment explaining what the line does
	// Read the first integer input and store it in the array x

	// Read remaining integers and store them in the array x
	while(x[i]!= 0){
		i++;
		cin>>x[i];
		// Comment explaining what the loop does
		// This loop reads and stores the remaining integers in the array x
	}

	// Print the results
	for(j=0;j<i;j++){
		cout<<"Case "<<j+1<<": "<<x[j]<<endl;
		// Comment explaining what the loop does
		// This loop prints the results for each input integer
	}

	// Signal successful termination of the program
	return 0;
}

