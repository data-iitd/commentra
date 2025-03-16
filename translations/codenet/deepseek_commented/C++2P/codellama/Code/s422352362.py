#include<cstdio> // Include the C standard input/output library for scanf and printf functions.
#include<map> // Include the map library for using the map container.
#include<cstring> // Include the C string library for string manipulation functions.
#include<cmath> // Include the C math library for mathematical functions.
#include<iostream> // Include the iostream library for input and output operations.
#include<algorithm> // Include the algorithm library for using the STL algorithms.
#include<queue> // Include the queue library for using the queue container.
using namespace std; // Use the standard namespace to avoid prefixing standard library names with 'std::'.

a = [0] * 200005 // Declare an array to store the input values.
pre = [0] * 200005 // Declare an array to store the prefix sums.
last = [0] * 200005 // Declare an array to store the suffix sums.

def main(): // The main function where the execution of the program begins.
	n = int(input()) // Read the value of n from the standard input.
	for i in range(1,n+1): // Loop to read n integers into the array a.
		a[i] = int(input()) // Read the i-th integer and store it in a[i].
	sumpre = 0 // Declare a variable to store the cumulative sums of prefix and suffix.
	sumlast = 0
	for i in range(1,n): // Loop to calculate the prefix sums.
		sumpre = sumpre + a[i] // Add the current element to the cumulative sum.
		pre[i] = sumpre // Store the cumulative sum in the pre array.
		#print(pre[i]) // Uncommented code to print the prefix sums (for debugging purposes).
	for i in range(n,1,-1): // Loop to calculate the suffix sums.
		sumlast = sumlast + a[i] // Add the current element to the cumulative sum.
		last[i] = sumlast // Store the cumulative sum in the last array.
		#print(last[i]) // Uncommented code to print the suffix sums (for debugging purposes).
	d = (1<<60) // Declare a variable to store the minimum difference and initialize it to a large number.
	for i in range(1,n): // Loop to find the minimum absolute difference between prefix and suffix sums.
		#print(pre[i]-last[i+1]) // Uncommented code to print the difference between prefix and suffix sums (for debugging purposes).
		d = min(d,abs(pre[i]-last[i + 1])) // Update the minimum difference if a smaller one is found.
	print(d) // Print the minimum difference found.


