package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Step 1: Reading the number of elements (n)
	n, _ := strconv.Atoi(readLine(reader))
	
	// Step 2: Reading the list of elements (a)
	a := readInts(reader)
	
	// Step 3: Initializing variables
	pre := int(1e9)  // Initialize pre to infinity
	ans := 0  // Initialize ans to 0
	
	// Step 4: Sorting the list in descending order
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
	
	// Step 5: Iterating through the list
	for j := 0; j < n; j++ {
		// Calculate the maximum value that can be added to ans
		ans += max(0, min(pre - 1, a[j]))
		// Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
		pre = max(0, min(pre - 1, a[j]))
	}
	
	// Step 6: Printing the result
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

func readInts(reader *bufio.Reader) []int {
	str, _ := reader.ReadString('\n')
	str = str[:len(str)-1] // Remove the newline character
	nums := []int{}
	for _, numStr := range strings.Split(str, " ") {
		num, _ := strconv.Atoi(numStr)
		nums = append(nums, num)
	}
	return nums
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

