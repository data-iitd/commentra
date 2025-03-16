package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]string, 0)
	for _, arg := range os.Args[1:] {
		sc = append(sc, arg)
	}
	a, _ := strconv.Atoi(sc[0])
	b, _ := strconv.Atoi(sc[1])
	count := 0
	for {
		if a > 0 && b > 0 {
			count++
			a--
			b--
		} else {
			break
		}
	}
	ans := a/2 + b/2
	fmt.Println(count, ans)
}

