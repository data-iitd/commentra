package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements (n) and the maximum size of the queue (b):")
	// Read the number of elements (n) and the maximum size of the queue (b)
	n, b, err := readInput(reader)
	if err!= nil {
		fmt.Println(err)
		return
	}
	fmt.Println("Enter the time and duration for each element:")
	// Initialize an array to store the results
	ans := make([]int, n)
	// Process each element based on the input
	for i := 0; i < n; i++ {
		// Read the time (t) and duration (d) for the current element
		t, d, err := readInput(reader)
		if err!= nil {
			fmt.Println(err)
			return
		}
		// Remove elements from the front of the queue that are no longer valid (i.e., their time is less than or equal to t)
		for len(q) > 0 && q[0] <= t {
			q = q[1:]
		}
		// Check if the size of the queue is within the allowed limit
		if len(q) <= b {
			// If the queue is empty, set the answer to the current time (t) plus duration (d)
			// Otherwise, set it to the last element in the queue plus duration (d)
			if len(q) == 0 {
				ans[i] = t + d
			} else {
				ans[i] = q[len(q)-1] + d
			}
			// Add the computed answer to the queue
			q = append(q, ans[i])
		} else {
			// If the queue size exceeds the limit, set the answer to -1
			ans[i] = -1
		}
	}
	// Print the results stored in the ans array
	fmt.Println(ans)
}

func readInput(reader *bufio.Reader) (int, int, error) {
	// Read the number of elements (n) and the maximum size of the queue (b)
	line, err := reader.ReadString('\n')
	if err!= nil {
		return 0, 0, err
	}
	line = strings.TrimSuffix(line, "\n")
	line = strings.TrimSuffix(line, "\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\r")
	line = strings.TrimSuffix(line, "\n\n")
	line = strings.TrimSuffix(line, "\n\r\n")
	line = strings.TrimSuffix(line, "\r\n\r")
	line = strings.TrimSuffix(line, "\r\r\n")
	line = strings.TrimSuffix(line, "\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n")
	line = strings.TrimSuffix(line, "\r\r\r")
	line = strings.TrimSuffix(line, "\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\r")
	line = strings.TrimSuffix(line, "\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\r\r\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.TrimSuffix(line, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	line = strings.T