#include<cstdio> // Include the C standard input/output library for scanf and printf functions.
#include<map> // Include the map library for using the map container.
#include<cstring> // Include the C string library for string manipulation functions.
#include<cmath> // Include the C math library for mathematical functions.
#include<iostream> // Include the iostream library for input and output operations.
#include<algorithm> // Include the algorithm library for using the STL algorithms.
#include<queue> // Include the queue library for using the queue container.
using namespace std; // Use the standard namespace to avoid prefixing standard library names with 'std::'.

long long a[200005]; // Declare an array to store the input values.
long long pre[200005]; // Declare an array to store the prefix sums.
long long last[200005]; // Declare an array to store the suffix sums.

int main(){ // The main function where the execution of the program begins.
	int n; // Declare a variable to store the number of elements.
	scanf("%d",&n); // Read the value of n from the standard input.
	for(int i = 1;i<=n;i++){ // Loop to read n integers into the array a.
			scanf("%lld",&a[i]); // Read the i-th integer and store it in a[i].
	}
	long long sumpre=0,sumlast=0; // Declare variables to store the cumulative sums of prefix and suffix.
	for(int i = 1;i<n;i++){ // Loop to calculate the prefix sums.
		sumpre=sumpre+a[i]; // Add the current element to the cumulative sum.
		pre[i]=sumpre; // Store the cumulative sum in the pre array.
//		printf("%lld++\n",pre[i]); // Uncommented code to print the prefix sums (for debugging purposes).
	}
	for(int i = n;i>1;i--){ // Loop to calculate the suffix sums.
		sumlast=sumlast+a[i]; // Add the current element to the cumulative sum.
		last[i]=sumlast; // Store the cumulative sum in the last array.
//		printf("%lld+++\n",last[i]); // Uncommented code to print the suffix sums (for debugging purposes).
	}
	long long d=(1ll<<60); // Declare a variable to store the minimum difference and initialize it to a large number.
	for(int i = 1;i<n;i++){ // Loop to find the minimum absolute difference between prefix and suffix sums.
//		printf("%lld\n",pre[i]-last[i+1]); // Uncommented code to print the difference between prefix and suffix sums (for debugging purposes).
		d=min(d,abs(pre[i]-last[i + 1])); // Update the minimum difference if a smaller one is found.
	}
	printf("%lld\n",d); // Print the minimum difference found.
}
