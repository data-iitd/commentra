package main

import (
	"fmt"
)

const mod = 1000000007 // Defining a constant value for modulus

func main() {
	var n, q int
	fmt.Scan(&n) // Reading the first integer input representing the length of the string
	fmt.Scan(&q) // Reading the second integer input representing the number of queries

	c := make([]rune, n)
	for i := 0; i < n; i++ {
		var ch rune
		fmt.Scanf("%c", &ch) // Reading the string character by character
		c[i] = ch
	}

	rangeQueries := make([][2]int, q) // Declaring and initializing a 2D array to store the range of each query
	for i := 0; i < q; i++ { // Loop to read the range of each query
		fmt.Scan(&rangeQueries[i][0]) // Reading the starting index of the range
		fmt.Scan(&rangeQueries[i][1]) // Reading the ending index of the range
	}

	frag := make([]int, n+1) // Declaring and initializing an array to store the frequency of 'AC' substring
	rui := make([]int, n+1)  // Declaring and initializing an array to store the running sum of 'AC' substring frequency

	for i := 2; i <= n; i++ { // Loop to iterate through the string from index 2 to the end
		if c[i-2] == 'A' && c[i-1] == 'C' { // Checking if the current position is an 'AC' substring
			frag[i]++ // Incrementing the frequency of 'AC' substring at the current position
		}
		rui[i] = rui[i-1] + frag[i] // Updating the running sum of 'AC' substring frequency
	}

	for i := 0; i < q; i++ { // Loop to iterate through each query
		left := rangeQueries[i][0]  // Storing the starting index of the current query range
		right := rangeQueries[i][1]  // Storing the ending index of the current query range
		fmt.Println(rui[right] - rui[left]) // Printing the result of the current query
	}
}

// <END-OF-CODE>
