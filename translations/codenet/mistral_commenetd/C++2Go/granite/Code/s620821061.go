

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"os"
	"sort"
)

const (
	EOF = -1
)

type Runner struct {
	in  *bufio.Scanner
	buf *bytes.Buffer
	w   *bufio.Writer
}

func NewRunner() *Runner {
	r := &Runner{
		buf: bytes.NewBufferString(""),
		w:   bufio.NewWriter(os.Stdout),
	}
	r.in = bufio.NewScanner(r.buf)
	r.in.Split(bufio.ScanWords)
	return r
}

func (r *Runner) Read() {
	r.buf.Reset()
	io.Copy(r.buf, os.Stdin)
	r.buf.Seek(0, 0)
}

func (r *Runner) Write() {
	r.w.Flush()
}

func (r *Runner) Close() {
	r.w.Flush()
	os.Exit(0)
}

func (r *Runner) ReadInt() int {
	r.Read()
	r.in.Scan()
	return int(r.in.Int())
}

func (r *Runner) ReadString() string {
	r.Read()
	r.in.Scan()
	return r.in.Text()
}

func (r *Runner) ReadFloat64() float64 {
	r.Read()
	r.in.Scan()
	return r.in.Float()
}

func (r *Runner) ReadLine() string {
	r.Read()
	r.in.Scan()
	return r.in.Text()
}

func (r *Runner) ReadSlice(sep rune) []string {
	r.Read()
	return strings.Split(r.ReadLine(), string(sep))
}

func (r *Runner) ReadIntSlice(sep rune) []int {
	r.Read()
	s := strings.Split(r.ReadLine(), string(sep))
	res := make([]int, len(s))
	for i := range s {
		res[i] = int(mustParseInt(s[i]))
	}
	return res
}

func (r *Runner) ReadInt64Slice(sep rune) []int64 {
	r.Read()
	s := strings.Split(r.ReadLine(), string(sep))
	res := make([]int64, len(s))
	for i := range s {
		res[i] = mustParseInt64(s[i])
	}
	return res
}

func (r *Runner) ReadFloat64Slice(sep rune) []float64 {
	r.Read()
	s := strings.Split(r.ReadLine(), string(sep))
	res := make([]float64, len(s))
	for i := range s {
		res[i] = mustParseFloat64(s[i])
	}
	return res
}

func (r *Runner) WriteLine(line string) {
	fmt.Fprintln(r.w, line)
}

func (r *Runner) WriteInt(x int) {
	fmt.Fprint(r.w, x)
}

func (r *Runner) WriteInt64(x int64) {
	fmt.Fprint(r.w, x)
}

func (r *Runner) WriteFloat64(x float64, prec int) {
	fmt.Fprintf(r.w, "%.*f", prec, x)
}

func (r *Runner) WriteSlice(sep rune, slice []string) {
	for i := range slice {
		if i > 0 {
			fmt.Fprint(r.w, sep)
		}
		fmt.Fprint(r.w, slice[i])
	}
}

func (r *Runner) WriteIntSlice(sep rune, slice []int) {
	for i := range slice {
		if i > 0 {
			fmt.Fprint(r.w, sep)
		}
		fmt.Fprint(r.w, slice[i])
	}
}

func (r *Runner) WriteInt64Slice(sep rune, slice []int64) {
	for i := range slice {
		if i > 0 {
			fmt.Fprint(r.w, sep)
		}
		fmt.Fprint(r.w, slice[i])
	}
}

func (r *Runner) WriteFloat64Slice(sep rune, slice []float64, prec int) {
	for i := range slice {
		if i > 0 {
			fmt.Fprint(r.w, sep)
		}
		r.WriteFloat64(slice[i], prec)
}

func mustParseInt(s string) int {
	res, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return res
}

func mustParseInt64(s string) int64 {
	res, err := strconv.ParseInt(s, 10, 64)
	if err!= nil {
		panic(err)
	}
	return res
}

func mustParseFloat64(s string) float64 {
	res, err := strconv.ParseFloat(s, 64)
	if err!= nil {
		panic(err)
	}
	return res
}

type BipartiteMatching struct {
	V int
	G []int
	match []int
	used []bool
}

func NewBipartiteMatching(V int) *BipartiteMatching {
	bm := &BipartiteMatching{
		V: V,
		G: make([]int, 2*V),
		match: make([]int, 2*V),
		used: make([]bool, 2*V),
	}
	return bm
}

func (bm *BipartiteMatching) AddEdge(a, b int) {
	bm.G[a] = b + V
	bm.G[b + V] = a
}

func (bm *BipartiteMatching) Dfs(v int) bool {
	bm.used[v] = true
	for i := 0; i < len(bm.G[v]); i++ {
		u := bm.G[v][i]
		w := bm.match[u]
		if w < 0 || (!bm.used[w] && bm.Dfs(w)) {
			bm.match[v] = u
			bm.match[u] = v
			return true
		}
	}
	return false
}

func (bm *BipartiteMatching) Exec() int {
	res := 0
	for v := 0; v < bm.V; v++ {
		if bm.match[v] < 0 {
			for i := 0; i < len(bm.used); i++ {
				bm.used[i] = false
			}
			if bm.Dfs(v) {
				res++
			}
		}
	}
	return res
}

func gcd(a, b int64) int64 {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	r := NewRunner()
	defer r.Close()

	for {
		n := r.ReadInt()
		m := r.ReadInt()
		if n == 0 {
			break
		}

		a := r.ReadIntSlice(' ')
		b := r.ReadIntSlice(' ')

		bm := NewBipartiteMatching(n)
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(int64(a[i]), int64(b[j]))!= 1 {
					bm.AddEdge(i, j)
				}
			}
		}

		r.WriteLine(strconv.Itoa(bm.Exec()))
	}
}

