package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	s := in.Text()
	s = replaceAll(s, "BC", "D")
	var cnt, tmp int64
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

func replaceAll(s, old, new string) string {
	return ""
}

