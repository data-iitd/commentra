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

	// Take the number of elements as input
	N, _ := strconv.Atoi(readLine(reader))

	// Take a space-separated string of integers as input and convert them to a list of integers
	nStr, _ := reader.ReadString('\n')
	nStr = strings.TrimSpace(nStr)
	nStrSlice := strings.Split(nStr, " ")
	n := make([]int, N)
	for i := 0; i < N; i++ {
		n[i], _ = strconv.Atoi(nStrSlice[i])
	}

	// Initialize a counter to 1 and a position index to 0
	a := 1
	pos := 0

	// Loop through the array from the second element to the last
	for i := 1; i < N; i++ {
		// Check if the current minimum element is greater than the current element
		if n[pos] > n[i] {
			// Increment the counter and update the position index
			a += 1
			pos = i
		}
	}

	// Print the final count of elements that are greater than the current minimum
	fmt.Println(a)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(string(str), "\r\n")
}
