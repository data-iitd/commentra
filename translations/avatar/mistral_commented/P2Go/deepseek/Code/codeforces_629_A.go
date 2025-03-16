package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	cake := []string{}
	happiness := 0
	chocCount := 0
	nfat := 1

	for i := 0; i < n; i++ {
		line, _ := readLine(reader), _
		cake = append(cake, line)

		for _, j := range line {
			if j == 'C' {
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

	fmt.Println(happiness)
}

func readLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}
