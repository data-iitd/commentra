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
	fmt.Println("Enter the values of x, y, a and b")
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	x, y, a, b := split(line)
	x, y, a, b = toInt(x, y, a, b)
	c := max(x, y)
	if c > b {
		fmt.Println("0")
		return
	}
	j := 2
	var i int
	var x1, y1, c int
	var ans bool
	c = max(x, y)
	if c > b {
		fmt.Println("0")
		return
	}
	ans = true
	for c%min(x, y)!= 0 && ans {
		if x > y {
			c = x * j
			j++
		} else {
			c = y * j
			j++
		}
		if c > b {
			fmt.Println("0")
			ans = false
			break
		}
	}
	if ans {
		count := 0
		i = a
		for i <= b {
			if i%c == 0 {
				break
			}
			i++
		}
		if i!= b+1 {
			fmt.Println((b-i)/c + 1)
		} else {
			fmt.Println("0")
		}
	}
}

func toInt(x, y, a, b string) (int, int, int, int) {
	x1, _ := strconv.Atoi(x)
	y1, _ := strconv.Atoi(y)
	a1, _ := strconv.Atoi(a)
	b1, _ := strconv.Atoi(b)
	return x1, y1, a1, b1
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func split(line string) (string, string, string, string) {
	x, y, a, b := "", "", "", ""
	for i := 0; i < len(line); i++ {
		if line[i] =='' {
			continue
		}
		if line[i] == ',' {
			continue
		}
		if line[i] == 'x' {
			x = line[0:i]
			y = line[i+1:]
			break
		}
		if line[i] == 'a' {
			a = line[0:i]
			b = line[i+1:]
			break
		}
	}
	return x, y, a, b
}

