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
	in := NewInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	sol := Solution{}
	sol.solve(in, out)
}

type Solution struct{}

func (sol Solution) solve(in *InputReader, out io.Writer) {
	n, k := in.nextInt(), in.nextInt()
	logsLength := in.readArray(n)
	min, max := 1, int(1e9+1000)
	for min < max {
		mid := (min + max) / 2
		if sol.nei(mid, logsLength, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}
	fmt.Fprintln(out, min)
}

func (sol Solution) nei(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
	}
	return k >= 0
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(stream)}
}

func (in *InputReader) next() string {
	for {
		line, err := in.reader.ReadString('\n')
		if err == nil {
			return strings.TrimSpace(line)
		}
	}
}

func (in *InputReader) nextInt() int {
	n, _ := strconv.Atoi(in.next())
	return n
}

func (in *InputReader) readArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.nextInt()
	}
	return a
}

