package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements (n)
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Read the array elements
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.ParseFloat(strings.TrimSpace(readLine(reader)), 64)
	}

	// Extract fractional parts and sort them
	arr = sort.Float64Slice(arr[:])[arr[:] < 1]

	// Calculate the number of elements to be added to make the total number of elements equal to 2 * n
	o := 2*n - len(arr)

	// Sum of the sorted fractional parts
	arr_sum := sum(arr)

	// Initialize the result variable to a very large number
	res := int(2e9)

	// Iterate to find the best position
	for i := 0; i <= n; i++ {
		if i+o >= n {
			res = min(res, abs(i-arr_sum))
		}
	}

	// Print the result with three decimal places
	fmt.Printf("%.3f", float64(res))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func sum(arr []float64) float64 {
	var res float64
	for _, v := range arr {
		res += v
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

