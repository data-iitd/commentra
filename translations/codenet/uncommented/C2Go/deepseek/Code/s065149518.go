package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const MAX = 21

func init(n int) [][]int {
	var a, b int
	x, y := 10, 10
	fld := make([][]int, MAX)
	for i := range fld {
		fld[i] = make([]int, MAX)
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&a, &b)
		fld[b][a] = 1
	}
	return fld
}

func move(fld [][]int, m int) bool {
	var a, d int
	var buf string
	for i := 0; i < m; i++ {
		fmt.Scan(&buf, &a)
		switch buf {
		case "N":
			d = 0
		case "E":
			d = 1
		case "S":
			d = 2
		case "W":
			d = 3
		}
		for a > 0 {
			switch d {
			case 0:
				y--
			case 1:
				x++
			case 2:
				y++
			case 3:
				x--
			}
			if fld[y][x] == 1 {
				fld[y][x] = 0
				a--
			}
		}
	}
	return a == 0
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		scanner.Scan()
		n := scanner.Text()
		if n == "" {
			break
		}
		n_int := strings.TrimSpace(n)
		if n_int == "0" {
			break
		}
		n_int_int := 0
		fmt.Sscanf(n_int, "%d", &n_int_int)
		fld := init(n_int_int)
		scanner.Scan()
		m := scanner.Text()
		m_int := strings.TrimSpace(m)
		m_int_int := 0
		fmt.Sscanf(m_int, "%d", &m_int_int)
		if move(fld, m_int_int) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

