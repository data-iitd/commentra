package main

import (
	"fmt"
)

func main() {
	var io [5]int
	for i := 0; i < 5; i++ {
		fmt.Scan(&io[i])
	}

	for i := 0; i < 5; i++ {
		max := io[i]
		max_j := i
		for j := i + 1; j < 5; j++ {
			if max < io[j] {
				max = io[j]
				max_j = j
			}
		}
		buf := io[i]
		io[i] = io[max_j]
		io[max_j] = buf
		if i < 4 {
			fmt.Printf("%d ", io[i])
		} else {
			fmt.Printf("%d\n", io[i])
		}
	}
}

// <END-OF-CODE>
