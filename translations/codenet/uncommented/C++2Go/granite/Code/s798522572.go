
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	N, T := readInt(), readInt()
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = readInt()
	}
	m := A[0]
	B := make([]int, N)
	B[1] = A[1] - m
	m = min(m, A[1])
	for i := 2; i < N; i++ {
		B[i] = A[i] - m
		m = min(m, A[i])
	}
	fmt.Println(count(B, *max_element(B)))
	out.Flush()
}

func readInt() int {
	i, _ := strconv.Atoi(read())
	return i
}

func read() string {
	str, _ := in.ReadString('\n')
	return str
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func count(a []int, m int) int {
	c := 0
	for _, v := range a {
		if v == m {
			c++
		}
	}
	return c
}

func max_element(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}
