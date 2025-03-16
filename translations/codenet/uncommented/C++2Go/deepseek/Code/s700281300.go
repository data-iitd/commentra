package main

import (
	"bufio"
	"fmt"
	"os"
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
			var ss strings.Builder
			for k := 0; k < j; k++ {
				ss.WriteByte(s[k])
			}
			res := ss.String()

			var ss2 strings.Builder
			for k := j; k < len(s); k++ {
				ss2.WriteByte(s[k])
			}
			res2 := ss2.String()

			t := res
			reverse(&t)
			t2 := res2
			reverse(&t2)

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

func reverse(s *string) {
	runes := []rune(*s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	*s = string(runes)
}

