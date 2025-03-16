package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	// Read the number of elements in the array
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the elements of the array")
	// Initialize an array of size n to store the input values
	a := make([]int, n)
	// Loop to read n integers from the user and store them in the array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadString('\n'))
	}
	// Sort the array in ascending order
	sort.Ints(a)
	// Store the minimum value from the sorted array
	min := a[0]
	// Check if all elements in the array are divisible by the minimum value
	for _, value := range a {
		if value%min!= 0 {
			// If any element is not divisible, print -1 and exit
			fmt.Println("-1")
			return
		}
	}
	// If all elements are divisible, print the minimum value
	fmt.Println(min)
}

