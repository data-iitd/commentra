package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var n int

// Function to read an integer from input
func nextInt() int {
	reader := bufio.NewReader(os.Stdin)
	char, _ := reader.ReadByte()
	// Skip non-digit characters until a digit or '-' is found
	for char != '-' && (char < '0' || char > '9') {
		char, _ = reader.ReadByte()
	}
	s := false
	if char == '-' {
		s = true
		char, _ = reader.ReadByte()
	}
	x := 0
	// Convert characters to integer
	for '0' <= char && char <= '9' {
		x = x*10 + int(char-'0')
		char, _ = reader.ReadByte()
	}
	if s {
		return -x
	}
	return x
}

// Function to calculate a unique identifier for a pair of nodes
func p(a, b int) int {
	if a < b {
		return a + b*n
	}
	return b + a*n
}

var a [1000][999]int

// Arrays to store edges and distances
var e1 [1000000]int
var e2 [1000000]int
var d [1000000]int
var b [1000000]bool

// Recursive function to compute the maximum distance from a given node
func f(from int) int {
	if b[from] {
		return -1
	}
	if d[from] != 0 {
		return d[from]
	}
	b[from] = true
	to := e1[from]
	max := 0
	if to != 0 {
		now := f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	to = e2[from]
	if to != 0 {
		now := f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	b[from] = false
	d[from] = max + 1
	return d[from]
}

func main() {
	n = nextInt()
	// Read the adjacency list from input
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			a[i][j] = nextInt() - 1
		}
	}
	// Build the edge representation
	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			from := p(i, a[i][j])
			to := p(i, a[i][j+1])
			if e1[from] == 0 {
				e1[from] = to
			} else if e2[from] == 0 {
				e2[from] = to
			} else {
				fmt.Println(-1)
				return
			}
		}
	}
	ans := 0
	// Compute the maximum distance for each node
	for i := 0; i < n; i++ {
		from := p(i, a[i][0])
		now := f(from)
		if now < 0 {
			ans = -1
			break
		}
		if now > ans {
			ans = now
		}
	}
	fmt.Println(ans)
}

