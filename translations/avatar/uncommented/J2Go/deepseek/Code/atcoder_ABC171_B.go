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
	in := NewInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	sol := Solution{}
	sol.solve(in, out)
}

type Solution struct{}

func (sol Solution) solve(in *InputReader, out io.Writer) {
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
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(stream)}
}

func (in *InputReader) n() string {
	for {
		line, err := in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		line = strings.TrimSpace(line)
		if len(line) > 0 {
			return line
		}
	}
}

func (in *InputReader) ni() int {
	i, err := strconv.Atoi(in.n())
	if err != nil {
		panic(err)
	}
	return i
}
