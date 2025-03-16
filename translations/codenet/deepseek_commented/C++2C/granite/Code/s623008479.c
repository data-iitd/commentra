
#include <stdio.h> // Include the standard input/output header
#include <stdlib.h> // Include the standard library header
#include <string.h> // Include the string header
#include <math.h> // Include the math header
#include <time.h> // Include the time header
#include <algorithm> // Include the algorithm header for sorting
#include <iostream>  // Include the iostream header for input and output
#include <vector>    // Include the vector header for using vectors
using namespace std; // Use the standard namespace

int main(){
	int n, k;
	scanf("%d %d", &n, &k); // Read the values of n and k from the input
	vector<int> l(n); // Declare a vector of size n
	for(int i = 0; i < n; i++){
		scanf("%d", &l[i]); // Read the elements of the vector l
	}

	sort(l.begin(), l.end()); // Sort the vector l in ascending order

	int ans=0; // Initialize ans to 0
	for(int i = 0; i < k; i++){
		ans += l[n - 1 - i]; // Sum the last k elements of the sorted vector
	}
	printf("%d\n", ans); // Print the result
}
