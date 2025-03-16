package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	var l [][]rune

	for i := 0; i < n; i++ {
		scanner.Scan()
		s := scanner.Text()
		sRunes := []rune(s)

		for j := 0; j < m; j++ {
			if sRunes[j] == '.' {
				if (i+j)%2 == 1 {
					sRunes[j] = 'W'
				} else {
					sRunes[j] = 'B'
				}
			}
		}

		l = append(l, sRunes)
	}

	for _, c := range l {
		fmt.Println(string(c))
	}
}

