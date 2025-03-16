package main

import (
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := bufio.NewScanner(inputStream)
	out := bufio.NewWriter(outputStream)
	solver := TaskC{}
	solver.solve(1, in, out)
	out.Flush()
}

type TaskC struct{}

func (solver *TaskC) solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	n := nextInt(in)
	cnt := make([]int64, 5)
	for i := 0; i < n; i++ {
		str := nextString(in)
		if str[0] == 'M' {
			cnt[0]++
		} else if str[0] == 'A' {
			cnt[1]++
		} else if str[0] == 'R' {
			cnt[2]++
		} else if str[0] == 'C' {
			cnt[3]++
		} else if str[0] == 'H' {
			cnt[4]++
		}
	}
	res := cnt[0]*cnt[1]*cnt[2] + cnt[0]*cnt[1]*cnt[3] + cnt[0]*cnt[1]*cnt[4] + cnt[0]*cnt[2]*cnt[3] + cnt[0]*cnt[2]*cnt[4] + cnt[0]*cnt[3]*cnt[4] + cnt[1]*cnt[2]*cnt[3] + cnt[1]*cnt[2]*cnt[4] + cnt[1]*cnt[3]*cnt[4] + cnt[2]*cnt[3]*cnt[4]
	fmt.Fprintln(out, res)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	nextI, err := strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}
	return nextI
}

func nextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

