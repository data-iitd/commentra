package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer n from the standard input
	n, _ := strconv.Atoi(readLine())

	// Create a list a of size n by reading n integers from the standard input and applying the map() function to convert each input integer to an integer
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readLine())
	}

	// Initialize two variables, pre and ans, to float('inf') and 0, respectively
	pre := float64(math.MaxInt64)
	ans := 0

	// Sort the list a in descending order using the sort() method
	sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })

	// Iterate through the list a using a for loop
	for j := 0; j < n; j++ {
		// Calculate the maximum of 0 and the minimum of pre - 1 and a[j]. This value is added to ans.
		ans += int(math.Max(0, math.Min(pre-1, float64(a[j]))))

		// Update the value of pre to be the minimum of pre - 1 and a[j].
		pre = math.Min(pre-1, float64(a[j]))
	}

	// After the loop, print the value of ans.
	fmt.Println(ans)
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

