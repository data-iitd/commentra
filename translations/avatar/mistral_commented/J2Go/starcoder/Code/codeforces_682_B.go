
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
	// Reading the number of elements in the list from the input
	n, _ := strconv.Atoi(readLine())

	// Creating an array list of size 'n' to store the elements
	list := make([]int, n)

	// Reading 'n' elements from the input and adding them to the array list
	for i := 0; i < n; i++ {
		list[i], _ = strconv.Atoi(readLine())
	}

	// Sorting the array list in ascending order using sort.Sort() method
	sort.Sort(sort.IntSlice(list))

	// Initializing a variable 'c' to keep track of the number of distinct elements
	c := 1

	// Iterating through the array list to find the number of distinct elements
	for i := 0; i < n; i++ {
		// If the current element is greater than or equal to the current count 'c', increment the count
		if list[i] >= c {
			c++
		}
	}

	// Writing the result to the output
	fmt.Println(c)
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

