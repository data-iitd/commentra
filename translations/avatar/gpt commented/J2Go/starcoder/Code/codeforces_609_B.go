package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements (n) and the maximum value (m):")
	// Read the number of elements (n) and the maximum value (m)
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the elements:")
	// Initialize an array to store the input values
	arr := make([]int, n)
	// Initialize a frequency array to count occurrences of each number from 1 to 10
	gen := make([]int, 11) // gen[0] will remain unused
	// Read n integers from input and populate the arr and gen arrays
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		gen[arr[i]]++
	}
	// Initialize a variable to hold the final answer
	ans := 0
	// Calculate the number of valid pairs (i, k) where i!= k
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i!= k {
				// Add the product of the counts of i and k to the answer
				ans += gen[i] * gen[k]
			}
		}
	}
	// Since each pair (i, k) is counted twice, divide the result by 2
	fmt.Println(ans / 2)
}

