
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements")
	// Read the number of elements
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	// Initialize a HashMap to store value and its index
	var map = make(map[int]int)
	// Initialize a PriorityQueue to store numbers
	var nums = make([]int, 0)
	// Read each number, add it to the PriorityQueue, and store its value and index in the HashMap
	for i := 0; i < N; i++ {
		var tmp int
		fmt.Println("Enter the number")
		// Read the number
		tmp, _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		nums = append(nums, tmp)
		map[tmp] = i
	}
	// Initialize variables to keep track of the current index and the count of differences
	var bin int = 0
	var diff int = 0
	// Loop until the PriorityQueue is empty
	for len(nums) > 0 {
		// Retrieve the next number and its index from the PriorityQueue and HashMap
		var num int = nums[0]
		var idx int = map[num]
		// If the current index is not even when bin is even (or vice versa), increment the diff counter
		if (bin%2)!= (idx%2) {
			diff++
		}
		// Update bin and take modulo 2 to keep it within 0 or 1
		bin++
		bin %= 2
		// Remove the number from the PriorityQueue
		nums = nums[1:]
	}
	// Calculate the answer by dividing diff by 2
	var ans int = diff / 2
	// Print the result
	fmt.Println(ans)
}

