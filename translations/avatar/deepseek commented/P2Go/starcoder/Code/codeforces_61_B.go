
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var (
		n int
		l [3]string
	)
	fmt.Scanf("%d", &n)
	for i := 0; i < 3; i++ {
		fmt.Scanf("%s", &l[i])
	}
	var (
		t   []string
		ans string
	)
	t = permutations(l[:])
	for i := 0; i < len(t); i++ {
		if strings.Join(t[i], "") == strings.Join(l[:], "") {
			ans = "ACC"
			break
		}
	}
	if ans == "" {
		ans = "WA"
	}
	fmt.Printf("%s\n", ans)
}

func permutations(l []string) (r []string) {
	if len(l) == 1 {
		r = append(r, l[0])
		return
	}
	for i := 0; i < len(l); i++ {
		t := l[i]
		l = append(l[:i], l[i+1:]...)
		for j := 0; j < len(permutations(l)); j++ {
			r = append(r, t+permutations(l)[j])
		}
		l = append(l[:i], t)
	}
	return
}

