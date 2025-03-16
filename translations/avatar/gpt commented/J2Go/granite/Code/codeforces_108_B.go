
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Creating a scanner to read input from the console
	in := bufio.NewReader(os.Stdin)

	// Reading the number of elements in the array
	n, _ := strconv.Atoi(read(in))

	// Initializing an array of size n
	a := make([]int, n)

	// Loop to read n integers from the user and store them in the array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(read(in))
	}

	// Sorting the array in ascending order
	sort.Ints(a)

	// Loop to check the condition for adjacent elements in the sorted array
	for i := 0; i < len(a)-1; i++ {
		// Checking if the next element is less than double the current element
		// and ensuring they are not equal
		if a[i+1] < a[i]*2 && a[i]!= a[i+1] {
			// If the condition is met, print "YES" and exit the program
			fmt.Println("YES")
			return
		}
	}

	// If no such pair is found, print "NO"
	fmt.Println("NO")
}

func read(in *bufio.Reader) string {
	str, _ := in.ReadString('\n')
	return str
}

