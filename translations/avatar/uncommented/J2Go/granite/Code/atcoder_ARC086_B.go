
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Split(bufio.ScanWords)
	s.Scan()
	n, _ := strconv.Atoi(s.Text())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		s.Scan()
		a[i], _ = strconv.Atoi(s.Text())
	}
	r := make([]string, 0)
	m := 0
	for i := 1; i < n; i++ {
		if abs(a[m]) < abs(a[i]) {
			m = i
		}
	}
	for i := 0; i < n; i++ {
		if (a[m] >= 0)!= (a[i] >= 0) {
			r = append(r, fmt.Sprintf("%d %d", m+1, i+1))
		}
	}
	if a[m] >= 0 {
		for i := 1; i < n; i++ {
			r = append(r, fmt.Sprintf("%d %d", i, i+1))
		}
	} else {
		for i := n; i > 1; i-- {
			r = append(r, fmt.Sprintf("%d %d", i, i-1))
		}
	}
	fmt.Println(len(r))
	for _, v := range r {
		fmt.Println(v)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

