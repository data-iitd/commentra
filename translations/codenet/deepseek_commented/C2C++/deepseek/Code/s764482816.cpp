#include<iostream>
#include<vector>
using namespace std;

int main(){
	int i,j,max,max_j,buf;
	vector<int> io(5);
	
	// Read five integers from the input and store them in the array 'io'
	for(i=0;i<5;i++) cin >> io[i];
	
	// Outer loop to iterate over each element in the array 'io'
	for(i=0;i<5;i++){
		max=io[i]; // Initialize 'max' with the current element
		max_j=i;   // Store the index of the current element in 'max_j'
		
		// Inner loop to find the maximum element in the unsorted part of the array
		for(j=i+1;j<5;j++){
			if(max<io[j]){ // If the current maximum is less than the element at index 'j'
				max=io[j]; // Update 'max' with the new maximum value
				max_j=j;   // Update 'max_j' with the index of the new maximum value
			}
		}
		
		// Swap the current element with the maximum element found in the unsorted part
		buf=io[i];
		io[i]=io[max_j];
		io[max_j]=buf;
		
		// Print the current element, with a space for all but the last element, and a newline for the last element
		if(i<4) cout << io[i] << " ";
		else cout << io[i] << endl;
	}
	return 0;
}
