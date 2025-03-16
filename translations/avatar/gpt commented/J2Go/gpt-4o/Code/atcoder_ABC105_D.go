package main

import (
	"bufio"
	"fmt"
	"os"
)

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader() *InputReader {
	return &InputReader{scanner: bufio.NewScanner(os.Stdin)}
}

func (ir *InputReader) NextInt() int {
	ir.scanner.Scan()
	var x int
	fmt.Sscan(ir.scanner.Text(), &x)
	return x
}

func (ir *InputReader) NextIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = ir.NextInt()
	}
	return arr
}

type TaskD struct{}

func (t *TaskD) Solve(n, m int, a []int) int64 {
	dp := make(map[int]int)
	var ans int64 = 0
	base := 0

	for i := 0; i < n; i++ {
		base = (base - a[i]%m + m) % m
		dp[(base+a[i])%m]++
		ans += int64(dp[base])
	}

	return ans
}

func main() {
	inputReader := NewInputReader()
	n := inputReader.NextInt()
	m := inputReader.NextInt()
	a := inputReader.NextIntArray(n)

	solver := TaskD{}
	result := solver.Solve(n, m, a)

	fmt.Println(result)
}

// <END-OF-CODE>
