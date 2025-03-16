package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	n, _ := strconv.Atoi(readLine(reader))

	// Read the list 't' and prepend a 0 for 1-based indexing
	tInput := readLine(reader)
	t := append([]int{0}, parseInts(tInput)...)

	// Read the list 'a' and prepend a 0 for 1-based indexing
	aInput := readLine(reader)
	a := append([]int{0}, parseInts(aInput)...)

	// Initialize the answer list and a count list to track occurrences
	ans := []int{}
	cnt := make([]int, n+1)

	// Count the occurrences of each element in list 'a'
	for _, i := range a {
		cnt[i]++
	}

	// Iterate through each index from 1 to n
	for i := 1; i <= n; i++ {
		// Check if the current element in 't' is 1
		if t[i] == 1 {
			// Initialize a current path list starting with the current index
			crt := []int{i}
			// Set x to the corresponding value in 'a'
			x := a[i]

			// Continue to follow the chain while the count of x is 1
			for cnt[x] == 1 {
				crt = append(crt, x) // Add x to the current path
				x = a[x]             // Move to the next index in the chain
			}

			// Update the answer if the current path is longer than the previous answer
			if len(crt) > len(ans) {
				ans = append([]int{}, crt...) // Store a copy of the current path
			}
		}
	}

	// Reverse the answer list to maintain the original order
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}

	// Print the length of the longest path found
	fmt.Println(len(ans))

	// Print the elements of the longest path as a space-separated string
	fmt.Println(strings.Trim(fmt.Sprint(ans), "[]"))
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

func parseInts(s string) []int {
	strs := strings.Split(s, " ")
	ints := []int{}
	for _, str := range strs {
		num, _ := strconv.Atoi(str)
		ints = append(ints, num)
	}
	return ints
}
