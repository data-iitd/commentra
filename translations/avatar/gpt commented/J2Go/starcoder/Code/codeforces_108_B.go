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
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Reading the number of elements in the array
	n, _ := strconv.Atoi(readLine(reader))
	// Initializing an array of size n
	a := make([]int, n)
	// Loop to read n integers from the user and store them in the array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readLine(reader))
	}
	// Sorting the array in ascending order
	sort.Ints(a)
	// Loop to check the condition for adjacent elements in the sorted array
	for i := 0; i < n - 1; i++ {
		// Checking if the next element is less than double the current element
		// and ensuring they are not equal
		if a[i+1] < a[i]*2 && a[i]!= a[i+1] {
			// If the condition is met, print "YES" and exit the program
			fmt.Println("YES")
			return
		}
	}
	// If no such pair is found, print "NO"
	fmt.Println("NO")
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

