package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	s := make(map[string]int)
	l := make([]string, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &l[i])
	}

	f := "Yes"
	i := -1

	for _, v := range l {
		s[v]++
		if s[v] >= 2 {
			f = "No"
		}
		if i != -1 && l[i][len(l[i])-1] != v[0] {
			f = "No"
		}
		i++
	}

	fmt.Fprintln(writer, f)
}
