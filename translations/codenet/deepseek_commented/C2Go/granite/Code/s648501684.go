
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables to store the input values
	var n, k, q int64

	// Read three integers from the standard input
	reader := bufio.NewReader(os.Stdin)
	n, _ = strconv.ParseInt(readLine(reader), 10, 64)
	k, _ = strconv.ParseInt(readLine(reader), 10, 64)
	q, _ = strconv.ParseInt(readLine(reader), 10, 64)

	// Declare an array of size n initialized to 0
	arr := make([]int64, n)
	for i := int64(0); i <= n; i++ {
		arr[i] = 0 // Initialize each element to 0
	}

	// Read q integers and increment the corresponding index in the array arr
	for i := int64(0); i < q; i++ {
		temp, _ := strconv.ParseInt(readLine(reader), 10, 64)
		arr[temp] += 1
	}

	// Check if the value at each index in arr is greater than q-k
	for i := int64(1); i <= n; i++ {
		if arr[i] > (q - k) {
			fmt.Println("Yes") // Print "Yes" if the condition is met
		} else {
			fmt.Println("No") // Print "No" otherwise
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

