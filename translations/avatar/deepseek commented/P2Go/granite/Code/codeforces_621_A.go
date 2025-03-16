

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

	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	lst := readLine(reader)
	split := strings.Split(lst, " ")
	lstInt := make([]int, n)
	for i := 0; i < n; i++ {
		lstInt[i], _ = strconv.Atoi(split[i])
	}

	// Sort the list in ascending order
	for i := 0; i < n; i++ {
		for j := 0; j < n-i-1; j++ {
			if lstInt[j] > lstInt[j+1] {
				lstInt[j], lstInt[j+1] = lstInt[j+1], lstInt[j]
			}
		}
	}

	// Reverse the list to get descending order
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		lstInt[i], lstInt[j] = lstInt[j], lstInt[i]
	}

	// Initialize a counter for odd numbers
	od := 0
	for i := 0; i < n; i++ {
		if lstInt[i]%2 == 1 {
			od++
		}
	}

	// Initialize sum to accumulate the result
	sum := 0
	ok := false  // Initialize a flag to track if an odd number has been added

	// Iterate through the list to process each number
	for i := 0; i < n; i++ {
		if lstInt[i]%2 == 0 {  // Check if the number is even
			sum += lstInt[i]  // Add even numbers to sum
		} else {
			if ok || od > 1 {  // Check if an odd number can be added
				sum += lstInt[i]  // Add odd number to sum
				od--              // Decrement the count of odd numbers
				ok =!ok         // Toggle the flag
			}
		}
	}

	fmt.Println(sum)  // Print the final sum
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}
