package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n := readInt(reader)
	left := make([]int, n)
	for i := 0; i < n; i++ {
		left[i] = i
	}
	sort.Ints(left)

	answer := make([]int, n)
	q := readInt(reader)
	for i := 0; i < q; i++ {
		l := readInt(reader) - 1
		r := readInt(reader) - 1
		win := readInt(reader)

		for j := 0; j < len(left); {
			if left[j] < l {
				j++
				continue
			}
			if left[j] > r {
				break
			}
			curr := left[j]
			answer[curr] = win
			left = append(left[:j], left[j+1:]...) // Remove curr
		}
		answer[win-1] = 0
		left = append(left, win-1)
		sort.Ints(left) // Re-sort after adding
	}

	for i := 0; i < n; i++ {
		fmt.Print(answer[i])
	}
	fmt.Println()
}

func readInt(reader *bufio.Reader) int {
	var x int
	fmt.Fscan(reader, &x)
	return x
}

// <END-OF-CODE>
