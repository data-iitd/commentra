
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

	a, _ := strconv.Atoi(strings.TrimSpace(readLine(fin)))
	b, _ := strconv.Atoi(strings.TrimSpace(readLine(fin)))
	if a < b {
		for i := 0; i < b; i++ {
			fmt.Fprintln(fout, a)
		}
	} else {
		for i := 0; i < a; i++ {
			fmt.Fprintln(fout, b)
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

