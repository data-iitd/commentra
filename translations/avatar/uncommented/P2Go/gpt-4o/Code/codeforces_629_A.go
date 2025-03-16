package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	cake := make([]string, n)
	happiness := 0.0
	chocCount := 0
	nfat := 1

	for i := 0; i < n; i++ {
		var line string
		fmt.Scan(&line)
		cake[i] = line
		for _, j := range line {
			if j == 'C' {
				chocCount++
			}
		}
		if chocCount > 1 {
			for k := chocCount; k > chocCount-2; k-- {
				nfat *= k
			}
			happiness += float64(nfat) / 2
		}
		nfat = 1
		chocCount = 0
	}

	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			if cake[i][j] == 'C' {
				chocCount++
			}
		}
		if chocCount > 1 {
			for k := chocCount; k > chocCount-2; k-- {
				nfat *= k
			}
			happiness += float64(nfat) / 2
		}
		nfat = 1
		chocCount = 0
	}

	fmt.Println(int(happiness))
}

// <END-OF-CODE>
