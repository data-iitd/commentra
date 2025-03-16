package main

import (
	"fmt"
)

func main() {
	for {
		var c [3]int
		_, err := fmt.Scan(&c[0], &c[1], &c[2])
		if err != nil {
			break
		}

		card := make([]int, 10)
		count := 0
		sum := c[0] + c[1]

		for i := 0; i < 3; i++ {
			card[c[i]-1] = 1
		}

		for i := 0; i < 10; i++ {
			if card[i] == 0 && sum+i+1 <= 20 {
				count++
			}
		}

		if count >= 4 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

