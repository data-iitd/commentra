package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for the maximum number of elements
const NUM = 100001

func main() {
	// Create a new Scanner to read input from stdin
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())

	// Initialize a HashMap to store the index of each number
	map := make(map[int]int)

	// Initialize a PriorityQueue to store the numbers in sorted order
	nums := make([]int, 0)

	// Read N numbers from input
	for i := 0; i < N; i++ {
		sc.Scan()
		tmp, _ := strconv.Atoi(sc.Text())
		nums = append(nums, tmp)
		map[tmp] = i
	}

	// Initialize variables to track the binary state and the difference count
	bin := 0
	diff := 0

	// Process the numbers in sorted order
	for len(nums) > 0 {
		num := nums[0]
		nums = nums[1:]
		idx := map[num]

		// Check if the parity of the current index and the binary state differ
		if (bin % 2)!= (idx % 2) {
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

