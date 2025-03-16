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
	
	// Read the number of elements in the array
	n, _ := strconv.Atoi(readLine(reader))
	
	// Read the array elements from input, converting them to integers
	arrStr, _ := reader.ReadString('\n')
	arrStr = strings.TrimSpace(arrStr)
	arrStrSlice := strings.Split(arrStr, " ")
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(arrStrSlice[i])
	}
	
	// Initialize an answer array with zeros, which will store the results
	ans := make([]int, n)
	
	// Set the maximum value to the last element of the array
	mx := arr[n-1]
	
	// Iterate through the array from the second last element to the first
	for i := n - 2; i >= 0; i-- {
		// Calculate the required value for ans[i] based on the difference from the maximum
		ans[i] = max(0, mx - arr[i] + 1)
		
		// Update the maximum value if the current element is greater than the current maximum
		if arr[i] > mx {
			mx = arr[i]
		}
	}
	
	// Print the result array as space-separated values
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(ans[i])
	}
	fmt.Println()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(string(str), "\r\n")
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
