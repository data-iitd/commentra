package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	
	grid := [][]rune{}
	
	for i := 0; i < n; i++ {
		reader := bufio.NewReader(os.Stdin)
		line, _ := reader.ReadString('\n')
		line = line[:len(line)-1] // Remove the newline character
		row := []rune(line)
		
		for j := 0; j < m; j++ {
			if row[j] == '.' {
				if (i+j)%2 == 1 {
					row[j] = 'W'
				} else {
					row[j] = 'B'
				}
			}
		}
		grid = append(grid, row)
	}
	
	for _, row := range grid {
		fmt.Println(string(row))
	}
}

