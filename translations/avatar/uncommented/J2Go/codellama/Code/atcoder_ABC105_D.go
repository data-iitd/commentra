
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
	in := InputReader{
		br: bufio.NewReader(inputStream),
		st: strings.Split(strings.TrimSpace(readLine(in.br)), " "),
	}
	out := bufio.NewWriter(outputStream)
	solver := TaskD{}
	solver.solve(1, in, out)
	out.Flush()
}

type InputReader struct {
	br *bufio.Reader
	st []string
}

func readLine(br *bufio.Reader) string {
	var s string
	_, err := fmt.Fscan(br, &s)
	if err == io.EOF {
		return ""
	}
	return s
}

func (in *InputReader) nextString() string {
	if in.st == nil || len(in.st) == 0 {
		in.st = strings.Split(strings.TrimSpace(readLine(in.br)), " ")
	}
	return in.st[0]
}

func (in *InputReader) nextInt() int {
	s := in.nextString()
	x, _ := strconv.Atoi(s)
	return x
}

func (in *InputReader) nextIntArray(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = in.nextInt()
	}
	return res
}

type TaskD struct{}

func (solver *TaskD) solve(testNumber int, in InputReader, out *bufio.Writer) {
	n := in.nextInt()
	m := in.nextInt()
	a := in.nextIntArray(n)
	dp := make(map[int]int)
	ans := 0
	base := 0
	for i := 0; i < n; i++ {
		base = (base - a[i]%m + m) % m
		dp[((base+a[i])%m)]++
		ans += dp[base]
	}
	fmt.Fprintln(out, ans)
}

