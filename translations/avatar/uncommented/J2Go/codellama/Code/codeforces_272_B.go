
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
	sc := newScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	n := sc.nextInt()
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(sc.nextInt())]++
	}
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1+float64(a[i])-1)/2.0*float64(a[i]-1) + 0.0
		answer += summ
	}
	fmt.Fprintln(out, int64(answer))
	out.Flush()
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if (x & (1 << k)) != 0 {
			answer++
		}
	}
	return answer
}

type scanner struct {
	reader *bufio.Reader
}

func newScanner(input io.Reader) *scanner {
	return &scanner{
		reader: bufio.NewReader(input),
	}
}

func (s *scanner) next() string {
	for {
		line, err := s.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		line = strings.TrimSpace(line)
		if line != "" {
			return line
		}
	}
}

func (s *scanner) nextInt() int {
	i, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return i
}

func (s *scanner) nextLong() int64 {
	i, err := strconv.ParseInt(s.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func (s *scanner) nextFloat() float64 {
	f, err := strconv.ParseFloat(s.next(), 64)
	if err != nil {
		panic(err)
	}
	return f
}

func (s *scanner) nextDouble() float64 {
	return s.nextFloat()
}

