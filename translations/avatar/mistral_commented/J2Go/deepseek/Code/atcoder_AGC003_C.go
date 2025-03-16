package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Reading the number of elements in the array
	scanner.Scan()
	N := parseInt(scanner.Text())

	// Creating an empty map to store the index of each unique element
	m := make(map[int]int)

	// Creating an empty slice to store the elements in ascending order
	nums := []int{}

	// Reading the elements one by one and adding them to the slice and map
	for i := 0; i < N; i++ {
		scanner.Scan()
		tmp := parseInt(scanner.Text())
		nums = append(nums, tmp)
		m[tmp] = i
	}

	bin := 0
	diff := 0

	// Processing the elements in the slice
	for _, num := range nums {
		idx := m[num]

		// Checking if the binary index and the index of the current element have opposite parity
		if bin%2 != idx%2 {
			diff++
		}

		bin++
		bin %= 2
	}

	// Calculating and printing the answer
	ans := diff / 2
	fmt.Println(ans)
}

// Helper function to parse string to int
func parseInt(s string) int {
	var num int
	for _, ch := range s {
		num = num*10 + int(ch-'0')
	}
	return num
}

