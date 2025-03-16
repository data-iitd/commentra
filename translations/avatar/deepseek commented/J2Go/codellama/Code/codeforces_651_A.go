package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	var a, b, c int
	var err error
	var input []string
	var scanner *bufio.Scanner

	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		input = append(input, scanner.Text())
	}

	a, err = strconv.Atoi(input[0])
	if err != nil {
		fmt.Println(err)
		return
	}
	b, err = strconv.Atoi(input[1])
	if err != nil {
		fmt.Println(err)
		return
	}

	if a == 1 && b == 1 {
		fmt.Println(0)
	} else {
		c = 0
		for a >= 1 || b >= 1 {
			if a >= b {
				b++
				a -= 2
			} else {
				a++
				b -= 2
			}
			if a <= 0 || b <= 0 {
				c++
				break
			}
			c++
		}
		fmt.Println(c)
	}
}

func swap(a, b int) {
	t := b
	b = a
	a = t
}

func debug(obj ...interface{}) {
	fmt.Println(obj)
}

// 