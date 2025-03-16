
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
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
	n := in.ni()
	k := in.ni()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.ni()
	}
	sort.Ints(a)
	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i]
	}
	fmt.Fprintln(out, ans)
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

func (this *InputReader) n() string {
	for this.tokenizer == nil || !this.tokenizer.Scan() {
		var err error
		this.tokenizer, err = this.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
	}
	return this.tokenizer.Text()
}

func (this *InputReader) ni() int {
	return int(this.nInt64())
}

func (this *InputReader) nInt64() int64 {
	n, err := strconv.ParseInt(this.n(), 0, 64)
	if err != nil {
		panic(err)
	}
	return n
}

