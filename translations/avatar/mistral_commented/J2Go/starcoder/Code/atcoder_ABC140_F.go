
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Initialize scanner for user input
func main() {
	sc := bufio.NewScanner(os.Stdin)
	// Read the number of slimes N from user input
	var N int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	// Calculate the size of the array S based on N
	size := 1 << N
	// Initialize the array S with user input
	S := make([]int, size)
	// Initialize a boolean array spawned to keep track of which slimes have been spawned
	spawned := make([]bool, size)
	// Set the last element of spawned to true, as it represents the position of the last slime
	spawned[size-1] = true
	// Read the initial positions of slimes from user input and store them in array S
	for i := 0; i < size; i++ {
		sc.Scan()
		S[i], _ = strconv.Atoi(sc.Text())
	}
	// Sort the array S in ascending order
	sort.Ints(S)
	// Initialize an array named active to store the indices of the currently active slimes
	active := make([]int, 0)
	// Set the last element of spawned to true and add its index to the active list
	active = append(active, size-1)
	spawned[size-1] = true
	// Iterate through each generation of slimes
	for i := 0; i < N; i++ {
		// Sort the array active in descending order
		sort.Slice(active, func(i, j int) bool { return active[i] > active[j] })
		// Initialize an array named activated to store the indices of the slimes that will be activated in the next generation
		activated := make([]int, 0)
		// Initialize a variable named next to keep track of the index of the current slime in array S
		next := size - 1
		// Iterate through each slime in the current generation
		for _, slime := range active {
			// While the current index next is greater than or equal to 0 and the slime size is greater than or equal to the size of the current slime or the current index has already been spawned
			for next >= 0 && (S[next] >= slime || spawned[next]) {
				next--
			}
			// If the current index next is less than 0, it means that there is no empty space for the new slime to spawn, so print "No" and exit the program
			if next < 0 {
				fmt.Println("No")
				return
			}
			// Set the current index as spawned and add its index to the activated array
			spawned[next] = true
			activated = append(activated, S[next])
		}
		// Add all the indices of the activated slimes to the active array
		active = append(active, activated...)
	}
	// Print "Yes" to indicate that the program has successfully determined the positions of all N slimes
	fmt.Println("Yes")
}

