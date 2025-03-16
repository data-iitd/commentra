
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Take the number of test cases as input
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Read the first list 'a' of numbers from the standard input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	}

	// Read the second list 'b' of numbers from the standard input
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	}

	// Read the third list 'c' of numbers from the standard input
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	}

	// Initialize variables x, y, and z to 0
	x := 0
	y := 0
	z := 0

	// Iterate through each number in list 'a' and add it to the variable 'x'
	for i := 0; i < n; i++ {
		x += a[i]
	}

	// Iterate through each number in list 'b' and add it to the variable 'y'
	for i := 0; i < n; i++ {
		y += b[i]
	}

	// Iterate through each number in list 'c' and add it to the variable 'z'
	for i := 0; i < n; i++ {
		z += c[i]
	}

	// Print the absolute difference between 'x' and 'y'
	fmt.Println(int(math.Abs(float64(x - y))))

	// Print the absolute difference between 'y' and 'z'
	fmt.Println(int(math.Abs(float64(y - z))))
}
