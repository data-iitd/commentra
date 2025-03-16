
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the list `w`
	n, _ := strconv.Atoi(readLine())

	// Read `n` integers from the standard input and store them in the list `w`
	w := make([]int, n)
	for i := 0; i < n; i++ {
		w[i], _ = strconv.Atoi(readLine())
	}

	// Calculate the sum of all elements in the list `w`
	x := 0
	for i := 0; i < n; i++ {
		x += w[i]
	}

	// Initialize an empty list `d` to store the indices of elements that satisfy the condition
	d := make([]int, 0)

	// Iterate over each element in the list `w`
	for i := 0; i < n; i++ {
		// Check if the current element `w[i]` is equal to the average of the total sum `x` and the number of elements `n` minus one
		if (x - w[i]) / (n - 1) == w[i] {
			// Append the 1-based index of the element to the list `d`
			d = append(d, i+1)
		}
	}

	// Print the length of the list `d`
	fmt.Println(len(d))

	// Print the indices in `d` separated by spaces
	fmt.Println(strings.Trim(strings.Join(strings.Fields(fmt.Sprint(d)), " "), "[]"))
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

