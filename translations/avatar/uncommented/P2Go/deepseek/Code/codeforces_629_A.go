package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	cake := []string{}
	happiness := 0
	chocCount := 0
	nfat := 1

	for i := 0; i < n; i++ {
		var line string
		fmt.Scan(&line)
		cake = append(cake, line)
		for _, j := range line {
			if j == 'C' {
				chocCount++
			}
		}
		if chocCount > 1 {
			for i := chocCount; i > chocCount-2; i-- {
				nfat *= i
			}
			happiness += nfat / 2
			nfat = 1
		}
		chocCount = 0
	}

	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			if cake[i][j] == 'C' {
				chocCount++
			}
		}
		if chocCount > 1 {
			for i := chocCount; i > chocCount-2; i-- {
				nfat *= i
			}
			happiness += nfat / 2
			nfat = 1
		}
		chocCount = 0
	}

	fmt.Println(happiness)
}

