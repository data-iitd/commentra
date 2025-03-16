
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
	scanner := bufio.NewScanner(inputStream)
	writer := bufio.NewWriter(outputStream)

	solver := TaskC{}
	solver.Solve(1, scanner, writer)

	writer.Flush()
}

type TaskC struct{}

func (solver *TaskC) Solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	n := nextInt(in)

	cnt := make([]int, 5)
	for i := 0; i < 5; i++ {
		cnt[i] = 0
	}

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
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func nextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

