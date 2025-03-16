package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Step 1: Read the input values for n and k
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n := toInt(scanner.Bytes()) // Read the size of the array
	scanner.Scan()
	k := toInt(scanner.Bytes()) // Read the number of queries

	// Step 2: Read the array elements
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i] = toInt(scanner.Bytes()) // Read each element of the array
	}

	// Step 3: Initialize two counters, o and e, to count the number of 1s and 0s in the array, respectively
	var res []byte // To store the result
	o, e := 0, 0

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
		scanner.Scan()
		l := toInt(scanner.Bytes()) // Read the left index of the subarray
		scanner.Scan()
		r := toInt(scanner.Bytes()) // Read the right index of the subarray

		if (r-l+1)%2 == 1 {
			res = append(res, '0')
			res = append(res, '\n')
		} else {
			// Step 6: If the length of the subarray is even, check if the number of 1s and 0s is sufficient
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				res = append(res, '1')
				res = append(res, '\n')
			} else {
				res = append(res, '0')
				res = append(res, '\n')
			}
		}
	}

	// Step 7: Print the result
	os.Stdout.Write(res)
}

func toInt(buf []byte) int {
	i := 0
	for _, b := range buf {
		i = i*10 + int(b-'0')
	}
	return i
}

