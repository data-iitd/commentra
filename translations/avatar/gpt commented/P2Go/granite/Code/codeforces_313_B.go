
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the input string from the user
	soz := readString()

	// Initialize a slice 'a' to store the cumulative count of consecutive characters
	// The length of 'a' is one more than the length of'soz' to handle the base case
	a := make([]int, len(soz)+1)

	// Iterate through the string to fill the cumulative count slice 'a'
	for i := 1; i < len(soz); i++ {
		// Carry forward the previous count
		a[i] = a[i-1]

		// If the current character is the same as the previous one, increment the count
		if soz[i-1] == soz[i] {
			a[i]++
		}
	}

	// Read the number of queries from the user
	n := readInt()

	// Initialize an empty slice to store the results of each query
	arr := make([]int, n)

	// Process each query
	for i := 0; i < n; i++ {
		// Read the start and end indices for the query
		m, l := readString(), readString()

		// Calculate the number of consecutive characters between indices m and l
		// and append the result to the 'arr' slice
		arr[i] = a[toInt(l)] - a[toInt(m)]
	}

	// Print the results for each query
	for _, v := range arr {
		fmt.Println(v)
	}
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	res, err := strconv.Atoi(readString())
	if err!= nil {
		panic(err)
	}
	return res
}

func toInt(s string) int {
	res, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return res
}

