package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(stream)}
}

func (ir *InputReader) Next() string {
	for {
		line, err := ir.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		line = strings.TrimSpace(line)
		if len(line) > 0 {
			return line
		}
	}
}

func (ir *InputReader) NextInt() int {
	num, err := strconv.Atoi(ir.Next())
	if err != nil {
		panic(err)
	}
	return num
}

func (ir *InputReader) ReadArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = ir.NextInt()
	}
	return arr
}

type Solution struct{}

func (sol *Solution) Solve(in *InputReader, out io.Writer) {
	n := in.NextInt()
	k := in.NextInt()

	min, max := 1, int(1e9+1000)

	for min < max {
		mid := (min + max) / 2
		if sol.nei(mid, in.ReadArray(n), k) {
			max = mid
		} else {
			min = mid + 1
		}
	}

	fmt.Fprintln(out, min)
}

func (sol *Solution) nei(mid int, logsLength []int, k int) bool {
	daysNeeded := 0

	for _, log := range logsLength {
		daysNeeded += (log + mid - 1) / mid
		k -= daysNeeded
		if k < 0 {
			return false
		}
	}

	return true
}

func main() {
	in := NewInputReader(os.Stdin)
	out := os.Stdout
	sol := Solution{}
	sol.Solve(in, out)
}

