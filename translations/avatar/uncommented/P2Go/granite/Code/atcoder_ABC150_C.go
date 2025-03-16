
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
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	orig := make([][]int, 0)
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			for k := 1; k <= n; k++ {
				for l := 1; l <= n; l++ {
					if i!= j && i!= k && i!= l && j!= k && j!= l && k!= l {
						orig = append(orig, []int{i, j, k, l})
					}
				}
			}
		}
	}
	p := make([]int, 0)
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	for _, v := range strings.Split(s.Text(), " ") {
		i, _ := strconv.Atoi(v)
		p = append(p, i)
	}
	q := make([]int, 0)
	s.Scan()
	for _, v := range strings.Split(s.Text(), " ") {
		i, _ := strconv.Atoi(v)
		q = append(q, i)
	}
	pn := -1
	qn := -1
	for i, v := range orig {
		if equal(v, p) {
			pn = i
		}
		if equal(v, q) {
			qn = i
		}
	}
	fmt.Println(abs(pn - qn))
}

func equal(a, b []int) bool {
	if len(a)!= len(b) {
		return false
	}
	for i := 0; i < len(a); i++ {
		if a[i]!= b[i] {
			return false
		}
	}
	return true
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
