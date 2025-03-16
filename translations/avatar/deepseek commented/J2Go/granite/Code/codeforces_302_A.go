

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Read the input values for n and k
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:]) // Read the size of the array
	k, _ := strconv.Atoi(reader.ReadLine()[2:]) // Read the number of queries

	// Step 2: Read the array elements
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadLine()) // Read each element of the array
	}

	// Step 3: Initialize two counters, o and e, to count the number of 1s and 0s in the array, respectively
	var res bytes.Buffer // To store the result
	o, e := 0, 0 // Counters for 1s and 0s

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
		l, _ := strconv.Atoi(reader.ReadLine()[2:]) // Read the left index of the subarray
		r, _ := strconv.Atoi(reader.ReadLine()[2:]) // Read the right index of the subarray

		if (r-l+1)%2 == 1 {
			res.WriteString("0\n") // Append "0" if the length is odd
		} else {
			// Step 6: If the length of the subarray is even, check if the number of 1s and 0s is sufficient
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				res.WriteString("1\n") // Append "1" if the condition is satisfied
			} else {
				res.WriteString("0\n") // Append "0" if the condition is not satisfied
			}
		}
	}

	// Step 7: Print the result
	fmt.Println(res.String())
}

