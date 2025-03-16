
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

type Solution struct {
}

func (this *Solution) solve(in *InputReader, out *bufio.Writer) {
	n := in.nextInt()
	k := in.nextInt()
	logsLength := in.readArray(n)
	min := 1
	max := 1e9 + 1000
	for min < max {
		mid := (min + max) / 2
		if this.nei(mid, logsLength, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}
	fmt.Fprintln(out, min)
}

func (this *Solution) nei(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
	}
	return k >= 0
}

type InputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Reader
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
		tokenizer: nil,
	}
}

func (this *InputReader) next() string {
	for this.tokenizer == nil || !this.tokenizer.Scan() {
		var err error
		line, err := this.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		this.tokenizer = strings.NewReader(line)
	}
	return this.tokenizer.Text()
}

func (this *InputReader) nextInt() int {
	return int(this.nextInt64())
}

func (this *InputReader) nextInt64() int64 {
	i, err := strconv.ParseInt(this.next(), 0, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func (this *InputReader) readArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = this.nextInt()
	}
	return a
}

