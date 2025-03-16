
#include<stdio.h>

// Declare variables
int i, j, max, max_j, buf;
int io[5];

// Read 5 integers from the user and store them in the array io
void read_input(){
	scanf("%d %d %d %d %d",&io[0],&io[1],&io[2],&io[3],&io[4]);
}

int main(){
	// Initialize variables
	read_input();

	// Perform bubble sort on the array io
	for(i=0;i<5;i++){
		// Initialize max and max_j with the first element of the array
		max = io[i];
		max_j = i;

		// Compare the current element with the remaining elements
		for(j=i+1;j<5;j++){
			// If the current max is smaller than the next element, update max and max_j
			if(max<io[j]){
				max = io[j];
				max_j = j;
			}
		}

		// Swap the current element with the maximum element
		buf = io[i];
		io[i] = io[max_j];
		io[max_j] = buf;

		// Print the sorted elements, except for the last one
		i<4?printf("%d ",io[i]):printf("%d\n",io[i]);
	}

	// Return 0 to indicate successful execution
	return 0;
}