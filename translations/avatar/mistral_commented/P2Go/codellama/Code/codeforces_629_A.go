
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	cake := make([]string, n)
	happiness := 0
	chocCount := 0
	nfat := 1

	for i := 0; i < n; i++ {
		fmt.Scan(&cake[i])
		for j := 0; j < len(cake[i]); j++ {
			if cake[i][j] == 'C' {
				chocCount++
			}
		}
		if chocCount > 1 {
			nfat = 1
			for i := chocCount; i > chocCount-2; i-- {
				nfat *= i
			}
			happiness += nfat / 2
		}
		chocCount = 0
	}

	posCount := 0
	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			if cake[i][j] == 'C' {
				chocCount++
			}
		}
		if chocCount > 1 {
			nfat = 1
			for i := chocCount; i > chocCount-2; i-- {
				nfat *= i
			}
			happiness += nfat / 2
		}
		chocCount = 0
	}

	fmt.Println(int(happiness))
}

