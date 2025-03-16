package main

import (
	"fmt"
)

func main() {
	var i, j, max, maxJ, buf int
	var io [5]int
	fmt.Scan(&io[0], &io[1], &io[2], &io[3], &io[4])
	for i = 0; i < 5; i++ {
		max = io[i]
		maxJ = i
		for j = i + 1; j < 5; j++ {
			if max < io[j] {
				max = io[j]
				maxJ = j
			}
		}
		buf = io[i]
		io[i] = io[maxJ]
		io[maxJ] = buf
		if i < 4 {
			fmt.Printf("%d ", io[i])
		} else {
			fmt.Printf("%d\n", io[i])
		}
	}
}

