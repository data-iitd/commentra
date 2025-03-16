

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
	input := NewFastScanner(os.Stdin)

	// Read the number of integers
	n, _ := strconv.Atoi(input.nextLine())

	// Create a map to store the frequency of each integer
	map := make(map[int]int)

	// Read n integers and update their counts in the map
	for i := 0; i < n; i++ {
		val, _ := strconv.Atoi(input.nextLine())
		map[val] += 1
	}

	// Initialize max to the smallest possible integer value
	max := -1000000000

	// Iterate through the map to find the maximum count
	for _, value := range map {
		if value > max {
			max = value
		}
	}

	// Print the maximum count and the size of the map
	fmt.Println(strconv.Itoa(max) + " " + strconv.Itoa(len(map)))
}

// Utility class to read input efficiently
type FastScanner struct {
	reader *bufio.Reader
}

// Method to create a new instance of FastScanner
func NewFastScanner(reader *bufio.Reader) *FastScanner {
	return &FastScanner{reader: reader}
}

// Method to read the next token
func (f *FastScanner) next() string {
	token, _ := f.reader.ReadString(' ')
	return strings.TrimSpace(token)
}

// Method to read the next integer
func (f *FastScanner) nextInt() int {
	val, _ := strconv.Atoi(f.next())
	return val
}

// Method to read the next long
func (f *FastScanner) nextLong() int64 {
	val, _ := strconv.ParseInt(f.next(), 10, 64)
	return val
}

// Method to read the next double
func (f *FastScanner) nextDouble() float64 {
	val, _ := strconv.ParseFloat(f.next(), 64)
	return val
}

// Method to read the next line
func (f *FastScanner) nextLine() string {
	line, _ := f.reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// END-OF-CODE