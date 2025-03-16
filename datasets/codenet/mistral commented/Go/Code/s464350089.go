// Constants and package imports
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007
// 1MB
const ioBufferSize = 1 * 1024 * 1024

// Helper function to read input
func sc() *bufio.Scanner {
	sc := bufio.NewScanner(os.Stdin)
	sc.Buffer(make([]byte, ioBufferSize), ioBufferSize)
	sc.Split(bufio.ScanWords)
	return sc
}()

// Helper functions to read input as a word and an integer
func next() string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func main() {
	// Reading the first two integers h and n
	h, n := nextInt(), nextInt()

	// Initializing variable a to 0
	a := 0

	// Iterating through the array of size n and adding each integer to variable a
	for i := 0; i < n; i++ {
		a += nextInt()
	}

	// Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
	if h > a {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}