package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Initialize a Scanner object to read input
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the number of elements
	sc.Scan()
	N := 0
	fmt.Sscan(sc.Text(), &N)

	// Initialize a map to store value and its index
	m := make(map[int]int)

	// Initialize a slice to store numbers
	nums := make([]int, 0, N)

	// Read each number, append it to the slice, and store its value and index in the map
	for i := 0; i < N; i++ {
		sc.Scan()
		tmp := 0
		fmt.Sscan(sc.Text(), &tmp)
		nums = append(nums, tmp)
		m[tmp] = i
	}

	// Sort the slice of numbers
	sort.Ints(nums)

	// Initialize variables to keep track of the current index and the count of differences
	bin := 0
	diff := 0

	// Loop through the sorted slice of numbers
	for i := 0; i < N; i++ {
		num := nums[i]
		idx := m[num]

		// If the current index is not even when bin is even (or vice versa), increment the diff counter
		if (bin%2 != idx%2) {
			diff++
		}

		// Update bin and take modulo 2 to keep it within 0 or 1
		bin++
		bin %= 2
	}

	// Calculate the answer by dividing diff by 2
	ans := diff / 2

	// Print the result
	fmt.Println(ans)
}

