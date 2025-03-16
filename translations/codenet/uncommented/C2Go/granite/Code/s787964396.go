
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const I = 10000

func CountingSort(a, b []int, k int) {
	c := make([]int, I+1)
	for i := 0; i <= I; i++ {
		c[i] = 0
	}
	for j := 0; j < k; j++ {
		c[a[j]]++
	}
	for i := 1; i < I+1; i++ {
		c[i] += c[i-1]
	}
	for j := k - 1; j >= 0; j-- {
		b[c[a[j]]-1] = a[j]
		c[a[j]]--
	}
}

func main() {
	var n int
	fmt.Fscan(bufio.NewReader(os.Stdin), &n)
	a := make([]int, n+1)
	b := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Fscan(bufio.NewReader(os.Stdin), &a[i+1])
	}
	CountingSort(a, b, n)
	fmt.Printf("%d", b[1])
	for i := 2; i < n+1; i++ {
		fmt.Printf(" %d", b[i])
	}
	fmt.Println()
}

