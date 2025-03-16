
package main

import (
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := bufio.NewScanner(inputStream)
	out := bufio.NewWriter(outputStream)
	solver := BABC{}
	solver.solve(1, in, out)
	out.Flush()
}

type BABC struct{}

func (solver *BABC) solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	s := in.Text()
	s = strings.Replace(s, "BC", "D", -1)
	cnt := 0
	tmp := 0
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			tmp++
		} else if s[i] == 'D' {
			cnt += tmp
		} else {
			tmp = 0
		}
	}
	fmt.Fprintln(out, cnt)
}

