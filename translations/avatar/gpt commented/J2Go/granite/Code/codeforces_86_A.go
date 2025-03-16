
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func power(a int64) int {
	res := 0
	for a > 0 {
		res++
		a /= 10
	}
	return res
}

func mult(a int64) int64 {
	pow := power(a)
	max := int64(0)
	for j := 0; j < pow; j++ {
		max = max*10 + 9
	}
	return a * (max - a)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var l, r int64
	if scanner.Scan() {
		l, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
	if scanner.Scan() {
		r, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
	res := int64(0)
	maxxes := make([]int64, 10)
	temp := int64(0)
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		maxxes[i] = temp / 2 * (temp - temp/2)
	}
	res = int64(max(mult(l), mult(r)))
	temp = 0
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		if l <= temp/2 && temp/2 <= r {
			res = int64(max(maxxes[i], res))
		}
	}
	fmt.Println(res)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

