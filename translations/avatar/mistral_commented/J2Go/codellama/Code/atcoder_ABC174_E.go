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
	in := InputReader{inputStream}
	out := bufio.NewWriter(outputStream)
	sol := Solution{}
	sol.solve(in, out)
	out.Flush()
}

type InputReader struct {
	reader *bufio.Reader
}

func (in InputReader) next() string {
	line, err := in.reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(line)
}

func (in InputReader) nextInt() int {
	line := in.next()
	n, err := strconv.Atoi(line)
	if err != nil {
		panic(err)
	}
	return n
}

func (in InputReader) readArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.nextInt()
	}
	return a
}

type Solution struct{}

func (sol Solution) solve(in InputReader, out *bufio.Writer) {
	n := in.nextInt()
	k := in.nextInt()
	min := 1
	max := 1e9 + 1000
	for min < max {
		mid := (min + max) / 2
		if sol.nei(mid, in.readArray(n), k) {
			max = mid
		} else {
			min = mid + 1
		}
	}
	fmt.Fprintln(out, min)
}

func (sol Solution) nei(mid int, logsLength []int, k int) bool {
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

// 