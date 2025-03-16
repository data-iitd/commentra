
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Create a scanner object for input
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements
	var N int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())

	// Initialize a map to store the index of each number
	m := make(map[int]int)

	// Initialize a slice to store the numbers in sorted order
	nums := make([]int, 0, N)

	// Read N numbers from input
	for i := 0; i < N; i++ {
		sc.Scan()
		num, _ := strconv.Atoi(sc.Text())
		nums = append(nums, num)
		m[num] = i
	}

	// Initialize variables to track the binary state and the difference count
	bin := 0
	diff := 0

	// Process the numbers in sorted order
	sort.Ints(nums)
	for _, num := range nums {
		idx := m[num]

		// Check if the parity of the current index and the binary state differ
		if (bin%2) != (idx % 2) {
			diff++ // Increment the difference count if they differ
		}

		// Update the binary state
		bin++
		bin %= 2 // Toggle between 0 and 1
	}

	// Calculate the final answer as half of the difference count
	ans := diff / 2

	// Output the result
	fmt.Println(ans)
}

