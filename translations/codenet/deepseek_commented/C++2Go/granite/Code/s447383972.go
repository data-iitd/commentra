
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Step 7: Main function
	var n int
	fmt.Fscanf(os.Stdin, "%d\n", &n) // Read the size of the array.
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(os.Stdin, "%d", &a[i]) // Read the elements of the array.
	}
	sort.Ints(a) // Sort the array.
	var tot int
	for i := 0; i < n; i++ {
		if i == n-1 || a[i]!= a[i+1] {
			a[tot] = a[i]
			tot++
		}
	}
	fmt.Println(a[tot-1] * a[tot-2]) // Print the product of the two largest distinct elements.
}

