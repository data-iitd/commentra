
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, m int
	for {
		if _, err := fmt.Scan(&n); err == nil {
			if n >= 0 {
				init(n)
				fmt.Scan(&m)
				move(m)
				fmt.Println(n ? "No" : "Yes")
			} else {
				break
			}
		}
	}
}

func init(n int) {
	var a, b int
	x, y = 10, 10
	for i := 0; i < n; i++ {
		fmt.Scan(&a, &b)
		fld[b][a] = 1
	}
}

func move(m int) {
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
		for j := 0; j < a; j++ {
			if d%2 != 0 {
				if d%2 == 1 {
					if d == 1 {
						x--
					} else {
						x++
					}
				} else {
					if d == 3 {
						y--
					} else {
						y++
					}
					x += d / 2
				}
			} else {
				if d == 0 {
					y--
				} else {
					y++
				}
			}
			if fld[y][x] != 0 {
				fld[y][x] = 0
				n--
			}
		}
	}
}

var fld [21][21]int
var x, y int

