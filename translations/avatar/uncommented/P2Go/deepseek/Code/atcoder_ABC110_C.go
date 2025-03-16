package main

import (
	"fmt"
	"sort"
)

func run(s, t string) string {
	ss := make([]int, 26)
	tt := make([]int, 26)
	for _, char := range s {
		ss[char-'a']++
	}
	for _, char := range t {
		tt[char-'a']++
	}
	sort.Ints(ss)
	sort.Ints(tt)
	if string(ss) == string(tt) {
		return "Yes"
	} else {
		return "No"
	}
}

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	fmt.Println(run(s, t))
}
