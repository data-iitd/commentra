
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &k)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &p[i])
	}
	for i := 0; i < n; i++ {
		l := i
		for j := i + 1; j < n; j++ {
			if p[j] < p[l] {
				l = j
			}
		}
		if l!= i {
			m := p[i]
			p[i] = p[l]
			p[l] = m
		}
	}
	o := 0
	for i := 0; i < k; i++ {
		o += p[i]
	}
	fmt.Println(o)
}

// 