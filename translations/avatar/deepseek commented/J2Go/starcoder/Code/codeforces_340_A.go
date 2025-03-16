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
	fmt.Println("Enter the first integer: ")
	x, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString()), 10, 64)
	fmt.Println("Enter the second integer: ")
	y, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString()), 10, 64)
	fmt.Println("Enter the third integer: ")
	a, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString()), 10, 64)
	fmt.Println("Enter the fourth integer: ")
	b, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString()), 10, 64)

	j := int64(2)
	var i, x1, y1, c int64
	var ans bool = true

	c = int64(math.Max(float64(x), float64(y)))

	if c > b {
		fmt.Println("0")
		ans = false
	}

	for c%int64(math.Min(float64(x), float64(y)))!= 0 && ans {
		if x > y {
			c = x * j
		} else {
			c = y * j
		}
		j++

		if c > b {
			fmt.Println("0")
			ans = false
			break
		}
	}

	if ans {
		count := int64(0)
		i = a
		for i = a; i <= b; i++ {
			if i%c == 0 {
				break
			}
		}
		if i!= b+1 {
			fmt.Println((b-i)/c + 1)
		} else {
			fmt.Println("0")
		}
	}
}

