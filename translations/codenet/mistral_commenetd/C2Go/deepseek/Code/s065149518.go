package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const MAX = 21

func init(n int) [][]int {
	field := make([][]int, MAX)
	for i := range field {
		field[i] = make([]int, MAX)
	}
	x, y := 10, 10
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		field[b][a] = 1
	}
	return field
}

func move(field [][]int, n int, m int) bool {
	x, y := 10, 10
	for i := 0; i < m; i++ {
		var buf string
		var a int
		fmt.Scan(&buf, &a)
		dir := buf[0]
		for j := 0; j < a; j++ {
			switch dir {
			case 'N':
				y--
			case 'E':
				x++
			case 'S':
				y++
			case 'W':
				x--
			}
			if field[y][x] == 1 {
				field[y][x] = 0
				n--
			}
		}
	}
	return n == 0
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		var n int
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &n)
		if n <= 0 {
			break
		}
		field := init(n)
		var m int
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &m)
		result := move(field, n, m)
		if result {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

