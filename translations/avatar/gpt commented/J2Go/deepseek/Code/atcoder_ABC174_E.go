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
	line, err := ir.reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(line, "\r\n")
}

func (ir *InputReader) NextInt() int {
	num, err := strconv.Atoi(ir.Next())
	if err != nil {
		panic(err)
	}
	return num
}

func (ir *InputReader) ReadArray(n int) []int {
	line := ir.Next()
	fields := strings.Fields(line)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(fields[i])
	}
	return arr
}

type Solution struct{}

func (sol *Solution) Solve(in *InputReader, out *bufio.Writer) {
	n := in.NextInt()
	k := in.NextInt()
	logsLength := in.ReadArray(n)

	min, max := 1, int(1e9+1000)

	for min < max {
		mid := (min + max) / 2

		if sol.nei(mid, logsLength, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}

	out.WriteString(strconv.Itoa(min) + "\n")
	out.Flush()
}

func (sol *Solution) nei(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
	}
	return k >= 0
}

func main() {
	in := NewInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	sol := &Solution{}
	sol.Solve(in, out)
}

