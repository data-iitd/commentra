
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

// Function to solve the problem
bool solve(){
	// Initialize variables
	int maxsize = 0;
	int maxcnt = 0;
	int ans_num = -1;
	int ans_num2 = -1;
	char str_v[1000][101]; // Array to store strings read from input
	int str_v_size = 0; // Size of the array

	// Read strings from input
	char in[101];
	while(scanf("%s",in)){
		// Copy the input string into the array
		strcpy(str_v[str_v_size],in);
		// Update maxsize if the current string is larger
		if(maxsize < strlen(in)){
			maxsize = strlen(in);
			ans_num = str_v_size;
		}
		// Increment the size of the array
		str_v_size++;
	}

	// Find the string with maximum occurrences in the array
	for(int i=0;i<str_v_size;i++){
		int cnt = 0;
		// Count the occurrences of the current string in the array
		for(int j=0;j<str_v_size;j++){
			if(strcmp(str_v[i],str_v[j]) == 0) cnt++;
		}
		// Update maxcnt and ans_num2 if the current string has more occurrences
		if(maxcnt < cnt){
			maxcnt = cnt;
			ans_num2 = i;
		}
	}

	// Print the answer
	printf("%s %s\n",str_v[ans_num2],str_v[ans_num]);

	// Return true to indicate successful execution
	return true;
}

// Main function
int main(){
	// Call the solve function
	solve();

	// Return 0 to indicate successful execution
	return 0;
}

