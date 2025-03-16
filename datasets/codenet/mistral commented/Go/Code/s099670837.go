
package main

import "fmt"

// Variables declaration
var n, ans int
const arraySize = 101

// 2D array declaration and initialization
var a [arraySize][arraySize]int{}

// Recursive function to find the maximum sum of a sub-matrix
func findAns(i, j, sum int) {
	// Base case: if we have reached the last cell and the sum is greater than the current answer, update the answer
	if i == 1 && j == n-1 {
		ans = sum + a[i][j]
		return
	}
	// Base case: if we have reached the first row, recursively call the function for the next cell and add the current cell value to the sum
	if i == 0 {
		findAns(i+1, j, sum+a[i][j])
		return
	}
	// Recursively call the function for the next cell and add the current cell value to the sum
	if j+1 < n {
		findAns(i, j+1, sum+a[i][j])
		return
	}
}

// Main function
func main() {
	// Read the number of rows and columns from the standard input
	fmt.Scanf("%d", &n)

	// Read the elements of the matrix from the standard input
	for i := 0; i < 2; i++ {
		for j := 0; j < n; j++ {
			fmt.Scanf("%d", &a[i][j])
		}
	}

	// Call the recursive function to find the maximum sum of a sub-matrix
	findAns(0, 0, 0)

	// Print the maximum sum of a sub-matrix
	fmt.Println(ans)

// End of the code
