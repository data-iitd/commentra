#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Function to solve the problem
bool solve(){
	// Initialize variables
	int maxsize = 0;
	int maxcnt = 0;
	int ans_num = -1;
	int ans_num2 = -1;
	char **str_v; // Vector to store strings read from input

	// Read strings from input
	char in[1000];
	while(scanf("%s", in)!= EOF){
		// Allocate memory for the current string
		str_v = (char **) realloc(str_v, sizeof(char *) * (str_v[0]+1));
		// Push the string into the vector
		str_v[str_v[0]] = (char *) malloc(sizeof(char) * (strlen(in)+1));
		strcpy(str_v[str_v[0]], in);
		str_v[0]++;
		// Update maxsize if the current string is larger
		if(maxsize < strlen(in)){
			maxsize = strlen(in);
			ans_num = str_v[0]-1;
		}
	}

	// Find the string with maximum occurrences in the vector
	for(int i=0;i<str_v[0];i++){
		int cnt = 0;
		// Count the occurrences of the current string in the vector
		for(int j=0;j<str_v[0];j++){
			if(strcmp(str_v[i], str_v[j]) == 0) cnt++;
		}
		// Update maxcnt and ans_num2 if the current string has more occurrences
		if(maxcnt < cnt){
			maxcnt = cnt;
			ans_num2 = i;
		}
	}

	// Print the answer
	printf("%s %s\n", str_v[ans_num2], str_v[ans_num]);

	// Return true to indicate successful execution
	return true;
}

// Main function
int main(){
	// Set the precision of printf to 10 decimal places
	printf("%.10f\n", 1.2345678901234567890);
	// Call the solve function
	solve();

	// Return 0 to indicate successful execution
	return 0;
}

