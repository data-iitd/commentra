

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fin := bufio.NewReader(os.Stdin)
	fout := bufio.NewWriter(os.Stdout)
	defer fout.Flush()

	a, _ := strconv.Atoi(strings.TrimSpace(Readln(fin)))
	b, _ := strconv.Atoi(strings.TrimSpace(Readln(fin)))

	if a < b {
		for i := 0; i < b; i++ {
			fmt.Fprint(fout, a, " ")
		}
	} else {
		for i := 0; i < a; i++ {
			fmt.Fprint(fout, b, " ")
		}
	}

	fmt.Fprintln(fout)
}

func Readln(r *bufio.Reader) string {
	str, _, err := r.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

