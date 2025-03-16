package main

import (
	"bufio"
	"fmt"
	"os"
	"reverse"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < n; i++ {
		scanner.Scan()
		s := scanner.Text()

		st := make(map[string]bool)
		st[s] = true

		for j := 1; j < len(s); j++ {
			ss := strings.Builder{}
			for k := 0; k < j; k++ {
				ss.WriteByte(s[k])
			}
			res := ss.String()
			res = reverse.Reverse(res)

			ss2 := strings.Builder{}
			for k := j; k < len(s); k++ {
				ss2.WriteByte(s[k])
			}
			res2 := ss2.String()
			res2 = reverse.Reverse(res2)

			t := res
			t2 := res2
			st[t+t2] = true
			st[t2+t] = true

			st[t+res2] = true
			st[res2+t] = true

			st[res+t2] = true
			st[t2+res] = true

			st[res+res2] = true
			st[res2+res] = true
		}

		fmt.Println(len(st))
	}
}

