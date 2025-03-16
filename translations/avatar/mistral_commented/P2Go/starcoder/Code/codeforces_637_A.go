package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read input from stdin
func readInput(reader *bufio.Reader) string {
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to read input from stdin
func readInt(reader *bufio.Reader) int {
	input, _ := reader.ReadString('\n')
	i, _ := strconv.Atoi(strings.TrimSpace(input))
	return i
}

// Function to read input from stdin
func readInts(reader *bufio.Reader, n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i] = readInt(reader)
	}
	return ints
}

// Function to read input from stdin
func readStringArray(reader *bufio.Reader, n int) []string {
	strings := make([]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readInput(reader)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix(reader *bufio.Reader, n int) [][]string {
	strings := make([][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringArray(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix2D(reader *bufio.Reader, n int) [][]string {
	strings := make([][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringArray(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix3D(reader *bufio.Reader, n int) [][][]string {
	strings := make([][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix2D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix4D(reader *bufio.Reader, n int) [][][][]string {
	strings := make([][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix3D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix5D(reader *bufio.Reader, n int) [][][][][]string {
	strings := make([][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix4D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix6D(reader *bufio.Reader, n int) [][][][][][]string {
	strings := make([][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix5D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix7D(reader *bufio.Reader, n int) [][][][][][][]string {
	strings := make([][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix6D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix8D(reader *bufio.Reader, n int) [][][][][][][][]string {
	strings := make([][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix7D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix9D(reader *bufio.Reader, n int) [][][][][][][][][]string {
	strings := make([][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix8D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix10D(reader *bufio.Reader, n int) [][][][][][][][][][]string {
	strings := make([][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix9D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix11D(reader *bufio.Reader, n int) [][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix10D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix12D(reader *bufio.Reader, n int) [][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix11D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix13D(reader *bufio.Reader, n int) [][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix12D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix14D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix13D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix15D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix14D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix16D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix15D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix17D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix16D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix18D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix17D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix19D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix18D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix20D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix19D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix21D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix20D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix22D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix21D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix23D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix22D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix24D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix23D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix25D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix24D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix26D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix25D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix27D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix26D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix28D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix27D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix29D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix28D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix30D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix29D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix31D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix30D(reader, n)
	}
	return strings
}

// Function to read input from stdin
func readStringMatrix32D(reader *bufio.Reader, n int) [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string {
	strings := make([][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readStringMatrix31D(reader, n)
	