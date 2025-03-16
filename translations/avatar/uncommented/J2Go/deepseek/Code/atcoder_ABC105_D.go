package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := NewInputReader(inputStream)
	out := bufio.NewWriter(outputStream)
	defer out.Flush()

	solver := TaskD{}
	solver.solve(1, in, out)
}

type TaskD struct{}

func (td TaskD) solve(testNumber int, in *InputReader, out io.Writer) {
	n := in.nextInt()
	m := in.nextInt()
	a := in.nextIntArray(n)
	dp := make(map[int]int)
	var ans int64 = 0
	base := 0
	for i := 0; i < n; i++ {
		base = (base - a[i]%m + m) % m
		dp[(base+a[i])%m]++
		ans += int64(dp[base])
	}
	fmt.Fprintln(out, ans)
}

type InputReader struct {
	sc *bufio.Scanner
}

func NewInputReader(inputStream io.Reader) *InputReader {
	sc := bufio.NewScanner(inputStream)
	sc.Split(bufio.ScanWords)
	return &InputReader{sc}
}

func (ir *InputReader) nextString() string {
	if !ir.sc.Scan() {
		panic("EOF")
	}
	return ir.sc.Text()
}

func (ir *InputReader) nextInt() int {
	num, err := strconv.Atoi(ir.nextString())
	if err != nil {
		panic("Invalid number")
	}
	return num
}

func (ir *InputReader) nextIntArray(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = ir.nextInt()
	}
	return res
}

