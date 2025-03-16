package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	N int
	f [200 + 10]int
	b [200 + 10]byte
)

func getFail(b []byte, m int) {
	// Function declaration and initialization of variables
	var j int
	f[0], f[1] = 0, 0

	// Main logic of the function
	for i := 2; i <= m; i++ {
		for j = f[i-1]; j > 0 && b[j+1]!= b[i]; j = f[j] {
			// Searching for the longest common prefix of the current and previous strings
		}
		if b[j+1] == b[i] {
			j++
		}
		f[i] = j
	}
}

func main() {
	// Main function declaration and initialization of variables
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	// Reading the number of characters in the strings
	N, _ = strconv.Atoi(strings.TrimSpace(readLine(in)))

	// Reading the two strings from the input
	s1 := strings.TrimSpace(readLine(in))
	str := strings.TrimSpace(readLine(in))

	cnt := 0
	// Concatenating the two strings and creating character arrays for each
	for i := 0; i < N; i++ {
		b[i+1] = str[i]
	}
	for i := 0; i < N; i++ {
		b[i+1+N] = s1[i]
	}

	getFail(b, N+N)

	// Computing the length of the longest common prefix
	len := min(f[N+N], min(N, N))

	// Writing the output to the console
	fmt.Fprintln(out, 2*N-len)

	out.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readLine(in *bufio.Reader) string {
	buf := make([]byte, 0, 1024)
	for {
		line, isPrefix, err := in.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}
	return string(buf)
}

