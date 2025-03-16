

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(reader, &n)  // Read the number of elements in each list

	a := make([]int, n)  // Create a slice to store the first list of integers
	b := make([]int, n)  // Create a slice to store the second list of integers
	c := make([]int, n)  // Create a slice to store the third list of integers

	for i := 0; i < n; i++ {
		input, _ := reader.ReadString('\n')  // Read the elements of each list
		input = strings.TrimSpace(input)
		split := strings.Split(input, " ")

		a[i], _ = strconv.Atoi(split[0])  // Convert the string elements to integers and store in the respective slices
		b[i], _ = strconv.Atoi(split[1])
		c[i], _ = strconv.Atoi(split[2])
	}

	x := 0  // Initialize the sum of elements in list a
	y := 0  // Initialize the sum of elements in list b
	z := 0  // Initialize the sum of elements in list c

	// Calculate the sum of elements in each list
	for i := 0; i < n; i++ {
		x += a[i]  // Add each element of list a to x
		y += b[i]  // Add each element of list b to y
		z += c[i]  // Add each element of list c to z
	}

	// Print the absolute differences between the sums of the lists
	fmt.Println(int(math.Abs(float64(x - y))))  // Print the absolute difference between the sums of lists a and b
	fmt.Println(int(math.Abs(float64(y - z))))  // Print the absolute difference between the sums of lists b and c
