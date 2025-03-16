package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(readLine())

	// Read the list of integers and convert them to a list of integers
	a := strings.Split(readLine(), " ")
	a = convertStringSliceToInt(a)

	// Initialize the previous value to infinity
	pre := float64(math.MaxInt64)

	// Initialize the answer variable to accumulate the result
	ans := 0

	// Sort the list in descending order
	sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })

	// Iterate through the sorted list
	for j := 0; j < n; j++ {
		// Calculate the current contribution to the answer
		// It takes the minimum of (pre - 1) and the current element a[j], ensuring it's non-negative
		ans += int(math.Max(0, math.Min(pre-1, float64(a[j]))))

		// Update the previous value for the next iteration
		pre = math.Max(0, math.Min(pre-1, float64(a[j])))
	}

	// Print the final accumulated answer
	fmt.Println(ans)
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

func convertStringSliceToInt(arr []string) []int {
	var output []int
	for _, val := range arr {
		if val!= "" {
			num, _ := strconv.Atoi(val)
			output = append(output, num)
		}
	}
	return output
}

