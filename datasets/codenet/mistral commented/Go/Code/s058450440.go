package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Importing necessary packages

var (
	a   []int
	ans = 0
)

// Defining global variables

func dfs(left, i, res int) {
	// Function to perform Depth First Search (DFS) algorithm

	if left == 0 {
		ans += res
		return
	}

	for j := i; j < len(a); j++ {
		dfs(left-1, j+1, res*a[j])
	}
}

// Main function definition
func main() {
	// Initializing an io object for input/output handling
	io := newIo()

	// Reading the number of test cases
	n := io.nextInt()

	// Initializing an empty map to store the frequency of each character
	var dic map[rune]int
	dic = make(map[rune]int)

	// Reading strings and updating the map
	for range make([]struct{}, n) {
		c := io.nextString()[0]
		switch c {
		case 'M', 'A', 'R', 'C', 'H':
			dic[rune(c)]++
		}
	}

	// Converting map values to integers and appending them to the 'a' slice
	for _, v := range dic {
		a = append(a, v)
	}

	// Calling the 'dfs' function with initial arguments
	dfs(3, 0, 1)

	// Printing the answer
	fmt.Println(ans)
}

// Struct definition for input/output handling
type io struct {
	reader    *bufio.Reader
	tokens    []string
	nextToken int
}

// Function to initialize the io object
func newIo() *io {
	return &io{reader: bufio.NewReader(os.Stdin)}
}

// Function to read a line from the standard input
func (io *io) nextLine() string {
	var buffer []byte
	for {
		line, isPrefix, _ := io.reader.ReadLine()
		buffer = append(buffer, line...)
		if !isPrefix {
			break
		}
	}
	return string(buffer)
}

// Function to read a token (a word) from the standard input
func (io *io) nextString() string {
	for io.nextToken >= len(io.tokens) {
		line := io.nextLine()
		io.tokens = strings.Fields(line)
		io.nextToken = 0
	}
	r := io.tokens[io.nextToken]
	io.nextToken++
	return r
}

// Function to convert a token (a string) to an integer
func (io *io) nextInt() int {
	i, _ := strconv.Atoi(io.nextString())
	return i
}

// 