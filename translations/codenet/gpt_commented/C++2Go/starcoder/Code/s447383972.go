package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Function to read a long long integer from input
func read() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}

// Function to write a long long integer to output
func write(x int64) {
	fmt.Println(x)
}

// Function to write a long long integer followed by a newline
func writeln(x int64) {
	fmt.Println(x)
}

func main() {
	n := read()
	a := make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		a[i] = read()
	}
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
	tot := int64(0)
	for i := int64(1); i <= n; i++ {
		if a[i] == a[i+1] {
			q[tot] = a[i]
			tot++
			i++
		}
	}
	write(q[tot]*q[tot-1])
}

