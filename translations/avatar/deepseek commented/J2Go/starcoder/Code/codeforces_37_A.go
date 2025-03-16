
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

func main() {
	// Create an instance of FastScanner to read input efficiently
	input := NewFastScanner()

	// Read the number of integers
	n := input.nextInt()

	// Create a HashMap to store the frequency of each integer
	map := make(map[int]int)

	// Read n integers and update their counts in the hash map
	for i := 0; i < n; i++ {
		val := input.nextInt()
		map[val] = map[val] + 1
	}

	// Initialize max to the smallest possible integer value
	max := int(^uint(0) >> 1)

	// Iterate through the hash map to find the maximum count
	for _, value := range map {
		max = int(math.Max(float64(max), float64(value)))
	}

	// Print the maximum count and the size of the hash map
	fmt.Println(max, len(map))
}

// Utility class to read input efficiently
type FastScanner struct {
	s   *bufio.Scanner
	buf []byte
}

func NewFastScanner() *FastScanner {
	return &FastScanner{
		s:   bufio.NewScanner(os.Stdin),
		buf: make([]byte, 0),
	}
}

func (s *FastScanner) nextInt() int {
	s.s.Scan()
	i, _ := strconv.Atoi(s.s.Text())
	return i
}

// 