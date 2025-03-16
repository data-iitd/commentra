package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	
	l := [][]rune{}
	for i := 0; i < n; i++ {
		reader := bufio.NewReader(os.Stdin)
		s, _ := reader.ReadString('\n')
		s = s[:len(s)-1] // Remove newline character
		sRunes := []rune(s)
		for j := 0; j < m; j++ {
			if sRunes[j] == '.' {
				if (i+j)%2 == 0 {
					sRunes[j] = 'B'
				} else {
					sRunes[j] = 'W'
				}
			}
		}
		l = append(l, sRunes)
	}
	
	for _, c := range l {
		fmt.Println(string(c))
	}
}
