
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	cake := make([]string, n)
	for i := 0; i < n; i++ {
		cake[i] = readLine(reader)
	}
	happiness := 0
	chocCount := 0
	nfat := 1
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if cake[i][j] == 'C' {
				chocCount++
			}
		}
		if chocCount > 1 {
			for i := chocCount; i > chocCount-2; i-- {
				nfat *= i
			}
			happiness += nfat / 2
		}
		nfat = 1
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
			for i := chocCount; i > chocCount-2; i-- {
				nfat *= i
			}
			happiness += nfat / 2
		}
		nfat = 1
		chocCount = 0
	}
	fmt.Println(happiness)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

