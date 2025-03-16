
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Read the input values for n and k
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the size of the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the number of queries")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

	// Step 2: Read the array elements
	arr := make([]int, n)
	fmt.Println("Enter the array elements")
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}

	// Step 3: Initialize two counters, o and e, to count the number of 1s and 0s in the array, respectively
	res := "" // To store the result
	o := 0
	e := 0

	// Step 4: Iterate through the array to count the number of 1s and 0s
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++ // Increment the counter for 1s
		} else {
			e++ // Increment the counter for 0s
		}
	}

	// Step 5: For each query, determine if the length of the subarray is odd
	for i := 0; i < k; i++ {
		fmt.Println("Enter the left and right indices of the subarray")
		l, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		r, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

		if (r - l + 1) % 2 == 1 {
			res += "0\n" // Append "0" if the length is odd
		} else {
			// Step 6: If the length of the subarray is even, check if the number of 1s and 0s is sufficient
			if (r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e {
				res += "1\n" // Append "1" if the condition is satisfied
			} else {
				res += "0\n" // Append "0" if the condition is not satisfied
			}
		}
	}

	// Step 7: Print the result
	fmt.Print(res)
}

