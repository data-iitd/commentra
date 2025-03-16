package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create an instance of FastScanner to read input efficiently
	input := NewFastScanner()
	
	// Read the number of integers
	n := input.nextInt()
	
	// Create a map to store the frequency of each integer
	m := make(map[int]int)
	
	// Read n integers and update their counts in the map
	for i := 0; i < n; i++ {
		val := input.nextInt()
		m[val]++
	}
	
	// Initialize max to the smallest possible integer value
	max := -1 << 31
	
	// Iterate through the map to find the maximum count
	for _, value := range m {
		if value > max {
			max = value
		}
	}
	
	// Print the maximum count and the size of the map
	fmt.Println(max, len(m))
}

// Utility class to read input efficiently
type FastScanner struct {
	sc *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	return &FastScanner{bufio.NewScanner(os.Stdin)}
}

// Method to read the next token
func (fs *FastScanner) next() string {
	fs.sc.Scan()
	return fs.sc.Text()
}

// Method to read the next integer
func (fs *FastScanner) nextInt() int {
	val, _ := strconv.Atoi(fs.next())
	return val
}

// Method to read the next long
func (fs *FastScanner) nextLong() int64 {
	val, _ := strconv.ParseInt(fs.next(), 10, 64)
	return val
}

// Method to read the next double
func (fs *FastScanner) nextDouble() float64 {
	val, _ := strconv.ParseFloat(fs.next(), 64)
	return val
}

// Method to read the next line
func (fs *FastScanner) nextLine() string {
	return fs.sc.Text()
}

