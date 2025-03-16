
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	orig := make([][]int, factorial(n))
	for i := range orig {
		orig[i] = make([]int, n)
	}
	for i := range orig {
		for j := range orig[i] {
			orig[i][j] = j + 1
		}
	}
	p := make([]int, n)
	q := make([]int, n)
	for i := range p {
		fmt.Scanf("%d", &p[i])
	}
	for i := range q {
		fmt.Scanf("%d", &q[i])
	}
	pn := -1
	for i, v := range orig {
		if reflect.DeepEqual(v, p) {
			pn = i
			break
		}
	}
	qn := -1
	for i, v := range orig {
		if reflect.DeepEqual(v, q) {
			qn = i
			break
		}
	}
	fmt.Printf("%d\n", abs(pn-qn))
}

func factorial(n int) int {
	if n == 0 {
		return 1
	}
	return n * factorial(n-1)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func reflect(a, b []int) bool {
	if len(a)!= len(b) {
		return false
	}
	for i := range a {
		if a[i]!= b[i] {
			return false
		}
	}
	return true
}

