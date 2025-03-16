
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var testCases int
	var s string
	var cnt int64
	var tmp int64

	fmt.Fscan(reader, &testCases)

	for i := 0; i < testCases; i++ {
		fmt.Fscan(reader, &s)
		s = strings.ReplaceAll(s, "BC", "D")

		cnt = 0
		tmp = 0

		for j := 0; j < len(s); j++ {
			if s[j] == 'A' {
				tmp++
			} else if s[j] == 'D' {
				cnt += tmp
			} else {
				tmp = 0
			}
		}

		fmt.Fprintln(writer, cnt)
	}
}

