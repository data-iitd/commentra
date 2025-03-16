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
	
	// Read the size of the array
	N, _ := strconv.Atoi(readLine(reader))
	
	// Read the array elements
	A := readArray(reader)
	
	// Initialize the result variable to 0
	result := 0
	
	// Loop over each bit position from 0 to 59
	for b := 0; b < 60; b++ {
		// Count the number of set bits at the current bit position
		bs := 0
		for _, a := range A {
			if (a >> uint(b)) & 1 == 1 {
				bs++
			}
		}
		
		// Calculate the contribution of the current bit position to the result
		result = (result + bs * (N - bs) * (1 << uint(b))) % 1000000007
	}
	
	// Print the final result
	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

func readArray(reader *bufio.Reader) []int {
	line := readLine(reader)
	parts := strings.Split(line, " ")
	A := make([]int, len(parts))
	for i, part := range parts {
		A[i], _ = strconv.Atoi(part)
	}
	return A
}
