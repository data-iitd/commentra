
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	s := bufio.NewReader(os.Stdin)
	l := 2019
	m := make([]int, l)
	m[0] = 1
	a, r := 0, 0
	for i, e := range reverse(s) {
		a += int(e-'0') * pow(10, i, l)
		m[a%l]++
		r += m[a%l]
	}
	fmt.Println(r)
}

func reverse(r *bufio.Reader) []byte {
	b, _ := r.ReadBytes('\n')
	for i, j := 0, len(b)-1; i < j; i, j = i+1, j-1 {
		b[i], b[j] = b[j], b[i]
	}
	return b
}

func pow(x, y, m int) int {
	res := 1
	for y > 0 {
		if y&1 == 1 {
			res = (res * x) % m
		}
		y = y >> 1
		x = (x * x) % m
	}
	return res
}

