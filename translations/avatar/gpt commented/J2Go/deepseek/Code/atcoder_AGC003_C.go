package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Create a Scanner object for input
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the number of elements
	sc.Scan()
	N := parseInt(sc.Text())

	// Initialize a map to store the index of each number
	numMap := make(map[int]int)

	// Initialize a slice to store the numbers
	nums := make([]int, N)

	// Read N numbers from input
	for i := 0; i < N; i++ {
		sc.Scan()
		tmp := parseInt(sc.Text())
		nums[i] = tmp
		numMap[tmp] = i
	}

	// Sort the numbers
	sort.Ints(nums)

	// Initialize variables to track the binary state and the difference count
	bin := 0
	diff := 0

	// Process the numbers in sorted order
	for _, num := range nums {
		idx := numMap[num]

		// Check if the parity of the current index and the binary state differ
		if bin%2 != idx%2 {
			diff++
		}

		// Update the binary state
		bin++
		bin %= 2
	}

	// Calculate the final answer as half of the difference count
	ans := diff / 2

	// Output the result
	fmt.Println(ans)
}

// Helper function to parse string to int
func parseInt(s string) int {
	var num int
	fmt.Sscanf(s, "%d", &num)
	return num
}

