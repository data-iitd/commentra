package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := NewInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solver := Task{}
	solver.solve(in, out)
}

type Task struct{}

func (t Task) solve(in *InputReader, out *bufio.Writer) {
	n := in.nextInt()
	array := make([]int, 1001)
	for i := 0; i < n; i++ {
		index := in.nextInt()
		array[index]++
	}

	countMax := -1
	for i := 1; i < len(array); i++ {
		if countMax < array[i] {
			countMax = array[i]
		}
	}

	if n%2 == 0 {
		if countMax <= n/2 {
			out.WriteString("YES\n")
		} else {
			out.WriteString("NO\n")
		}
	} else {
		if countMax <= n/2+1 {
			out.WriteString("YES\n")
		} else {
			out.WriteString("NO\n")
		}
	}
}

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(stream interface{ io.Reader }) *InputReader {
	scanner := bufio.NewScanner(stream)
	scanner.Split(bufio.ScanWords)
	return &InputReader{scanner: scanner}
}

func (r *InputReader) next() string {
	r.scanner.Scan()
	return r.scanner.Text()
}

func (r *InputReader) nextInt() int {
	num, _ := strconv.Atoi(r.next())
	return num
}

func (r *InputReader) nextLong() int64 {
	num, _ := strconv.ParseInt(r.next(), 10, 64)
	return num
}

func (r *InputReader) nextDouble() float64 {
	num, _ := strconv.ParseFloat(r.next(), 64)
	return num
}

func (r *InputReader) nextLine() string {
	r.scanner.Scan()
	return r.scanner.Text()
}
