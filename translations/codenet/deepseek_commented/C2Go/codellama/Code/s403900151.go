package main

import "fmt"

func main() {
	var n, r, p, c int
	var i, j, k, l int
	var a [51]int
	var b [51]int

	for { // Loop until both n and r are zero
		fmt.Scanf("%d %d", &n, &r) // Read the number of elements and the number of operations
		if n == 0 && r == 0 {
			break // Exit the loop if both n and r are zero
		}

		// Initialize array a with elements from 1 to n
		for i = 0; i < n; i++ {
			a[i] = i + 1
		}

		// Perform r operations
		for i = 0; i < r; i++ {
			fmt.Scanf("%d %d", &p, &c) // Read the position and count of elements to be moved

			// Copy the last c elements to be moved to array b
			for j = 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}

			// Shift the first p-1 elements before the position where the c elements will be moved
			for j = 0; j < p-1; j++ {
				a[n-p-c+1+j] = a[n-p+j+1]
			}

			// Place the elements from b back into array a at the correct position
			for j = n - p - c + 1 + j, k = 0; k < c; j++, k++ {
				a[j] = b[k]
			}

			// Uncomment the following block to print the array after each operation for debugging
			/*
			for j = 0; j < n; j++ {
				fmt.Println(a[j])
			}
			fmt.Println("---")
			*/
		}
		// Print the last element of the array a after all operations
		fmt.Println(a[n-1])
	}
}

