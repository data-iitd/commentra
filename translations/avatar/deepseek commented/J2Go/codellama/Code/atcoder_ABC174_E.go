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
	sol := new(Solution)
	sol.solve(in, out)
	out.Flush()
}

type Solution struct{}

func (sol *Solution) solve(in *InputReader, out *bufio.Writer) {
	n := in.nextInt()
	k := in.nextInt()
	logsLength := in.readArray(n)
	min := 1
	max := 1e9 + 1000
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

func (sol *Solution) nei(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
		if k < 0 {
			return false
		}
	}
	return true
}

type InputReader struct {
	reader       *bufio.Reader
	tokenizer    *strings.Reader
	tokenizerStr string
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
	}
}

func (in *InputReader) next() string {
	if in.tokenizer == nil || !in.tokenizer.Scan() {
		in.tokenizerStr, _ = in.reader.ReadString('\n')
		in.tokenizer = strings.NewReader(in.tokenizerStr)
		in.tokenizer.Scan()
	}
	return in.tokenizer.Text()
}

func (in *InputReader) nextInt() int {
	return int(in.nextInt64())
}

func (in *InputReader) nextInt64() int64 {
	return int64(in.nextInt32())
}

func (in *InputReader) nextInt32() int32 {
	return int32(in.nextInt16())
}

func (in *InputReader) nextInt16() int16 {
	return int16(in.nextInt8())
}

func (in *InputReader) nextInt8() int8 {
	return int8(in.nextInt64())
}

func (in *InputReader) readArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.nextInt()
	}
	return a
}

