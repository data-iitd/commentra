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
	
	// Read the number of test cases
	n, _ := strconv.Atoi(readLine(reader))
	
	// Read the list 't' and initialize it with 0 as the first element
	t := []int{0}
	t = append(t, readInts(reader)...)
	
	// Read the list 'a' and initialize it with 0 as the first element
	a := []int{0}
	a = append(a, readInts(reader)...)
	
	// Initialize empty lists 'ans' and 'cnt'
	ans := []int{}
	cnt := make([]int, n+1)
	
	// Iterate through each element in list 'a' and increment the count of its corresponding index in list 'cnt'
	for _, i := range a {
		cnt[i]++
	}
	
	// Iterate through each index from 1 to n
	for i := 1; i <= n; i++ {
		// If the current index in list 't' is 1
		if t[i] == 1 {
			// Initialize an empty list 'crt' to store the current sequence
			crt := []int{i}
			// Get the current element in list 'a'
			x := a[i]
			// Continue adding elements to 'crt' as long as the corresponding index in 'cnt' has a count of 1
			for cnt[x] == 1 {
				crt = append(crt, x)
				x = a[x]
			}
			// If the length of the current sequence is greater than the length of the current answer sequence
			if len(crt) > len(ans) {
				// Update the answer sequence with the current sequence
				ans = append([]int(nil), crt...)
			}
		}
	}
	
	// Reverse the order of elements in the answer sequence
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	
	// Print the length of the answer sequence
	fmt.Println(len(ans))
	// Print the answer sequence with each element separated by a space
	fmt.Println(strings.Trim(fmt.Sprint(ans), "[]"))
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

func readInts(reader *bufio.Reader) []int {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(strings.TrimRight(line, "\n"))
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}
