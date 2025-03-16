
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the length of the string and the number of queries
	n, q := readTwoNums(os.Stdin)

	// Read the string
	s := readString(os.Stdin)

	// Read the queries
	problems := make([][]int, q)
	for i := 0; i < q; i++ {
		problems[i] = readNNums(os.Stdin, 2)
	}

	// Define a function to count occurrences of 'AC' in the string
	var count func(total int, i int) int
	count = func(total int, i int) int {
		// Check if the current substring is 'AC'
		if s[i-1:i+1] == "AC" {
			// Increment the count if 'AC' is found
			return total + 1
		}
		// Return the total count if 'AC' is not found
		return total
	}

	// Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
	cumsum := list(accumulate([]int{0} + list(range(1, n)), count))

	// Iterate over the queries and print the difference in cumulative sums
	for l, r := range problems {
		fmt.Println(cumsum[r-1] - cumsum[l-1])
	}
}

// Read two integers from input stream.
func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

// Read a string from input stream.
func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

// Read n integers from input stream.
func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

// Accumulate the result of func f(total, i)
func accumulate(arr []int, f func(total int, i int) int) []int {
	res := make([]int, len(arr))
	for i := 0; i < len(arr); i++ {
		res[i] = f(res[i-1], arr[i])
	}
	return res
}

// List the elements of the array
func list(arr []int) {
	for _, num := range arr {
		fmt.Printf("%d ", num)
	}
	fmt.Println()
}

// 