
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner object for input and a writer for output
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of elements
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])

	// Initialize an array to store the elements
	ara := make([]int, n)

	// Create a map to count the frequency of each element
	map := make(map[int]int)

	// Read elements and populate the frequency map
	for i := 0; i < n; i++ {
		ara[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		if _, ok := map[ara[i]];!ok {
			map[ara[i]] = 1
		} else {
			map[ara[i]]++
		}
	}

	// Find the maximum frequency among the elements
	max := 0
	for _, v := range map {
		if v > max {
			max = v
		}
	}

	// Create another map to track the order of elements while checking frequency
	mm := make(map[int]int)

	// Iterate through the original array to find the first element with maximum frequency
	for i := 0; i < n; i++ {
		if _, ok := mm[ara[i]];!ok {
			mm[ara[i]] = 1
			// Check if the current element's frequency matches the maximum frequency
			if mm[ara[i]] == max {
				fmt.Fprintln(writer, ara[i])
				break
			}
		} else {
			// Increment the count for the existing element
			mm[ara[i]]++
			// Check if the current element's frequency matches the maximum frequency
			if mm[ara[i]] == max {
				fmt.Fprintln(writer, ara[i])
				break
			}
		}
	}

	// Flush the writer
	writer.Flush()
}

// Debugging function to print objects
func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

// End of code