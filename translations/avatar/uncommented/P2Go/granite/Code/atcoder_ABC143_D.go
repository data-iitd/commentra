
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"sort"
)

var (
	readBuf  [1024]byte
	readBytes []byte
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &l[i])
	}
	sort.Ints(l)
	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a, b := l[i], l[j]
			right := sort.Search(n, func(x int) bool {
				return l[x] >= a+b
			})
			left := sort.Search(n, func(x int) bool {
				return l[x] >= abs(a-b)
			})
			tmp := right - left
			if left <= i && i < right {
				tmp--
			}
			if left <= j && j < right {
				tmp--
			}
			ans += tmp
		}
	}
	fmt.Println(ans / 3)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

