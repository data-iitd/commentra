
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	q, _ := strconv.Atoi(read(reader))
	h, _ := strconv.Atoi(read(reader))
	s, _ := strconv.Atoi(read(reader))
	d, _ := strconv.Atoi(read(reader))
	n, _ := strconv.Atoi(read(reader))

	// Calculating the best price for single liters
	best1L := min(q*4, h*2, s)

	// Calculating the best price for double liters
	best2L := min(d, best1L*2)

	// Checking if the quantity n is even or odd and printing the total cost accordingly
	if n%2 == 0 {
		fmt.Println(best2L * (n / 2))
	} else {
		fmt.Println(best2L*(n/2) + best1L)
	}
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func min(a, b, c int) int {
	m := a
	if b < m {
		m = b
	}
	if c < m {
		m = c
	}
	return m
}

