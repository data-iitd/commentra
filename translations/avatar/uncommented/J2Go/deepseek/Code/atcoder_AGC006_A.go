package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 200 + 10

var f [N]int
var b [N]rune

func getFail(b []rune, m int) {
	j := 0
	f[0], f[1] = 0, 0
	for i := 2; i <= m; i++ {
		for j > 0 && b[j+1] != b[i] {
			j = f[j]
		}
		if b[j+1] == b[i] {
			j++
		}
		f[i] = j
	}
}

func main() {
	in := NewInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n := in.nextInt()
	s1 := in.next()
	str := in.next()
	cnt := 0
	for i := 0; i < n; i++ {
		b[++cnt] = rune(str[i])
	}
	for i := 0; i < n; i++ {
		b[++cnt] = rune(s1[i])
	}
	getFail(b[:cnt+1], cnt)
	len := min(f[cnt], min(n, n))
	fmt.Fprintln(out, 2*n-len)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(stream interface{}) *InputReader {
	return &InputReader{reader: bufio.NewReader(os.Stdin)}
}

func (r *InputReader) next() string {
	for {
		line, err := r.reader.ReadString('\n')
		if err == nil {
			return strings.TrimSpace(line)
		}
	}
}

func (r *InputReader) nextInt() int {
	n, _ := strconv.Atoi(r.next())
	return n
}
