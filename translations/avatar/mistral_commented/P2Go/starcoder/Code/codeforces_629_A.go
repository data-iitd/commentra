
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var line string
	var cake []string
	var happiness float64
	var chocCount int
	var nfat int

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &line)
		cake = append(cake, line)
		for j := 0; j < len(line); j++ {
			if line[j] == 'C' {
				chocCount++
			}
		}
		if chocCount > 1 {
			nfat = 1
			for i := chocCount; i > chocCount-2; i-- {
				nfat *= i
			}
			happiness += float64(nfat) / 2
		}
		chocCount = 0
	}
	for j := 0; j < n; j++ {
		chocCount = 0
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
			happiness += float64(nfat) / 2
		}
	}
	fmt.Println(int(happiness))
}

