package main

import (
	"fmt"
	"strings"
)

func main() {
	s := strings.Split(input(), "")
	even := make(map[string]int)
	odd := make(map[string]int)
	for i := 0; i < len(s); i += 2 {
		even[s[i]]++
	}
	for i := 1; i < len(s); i += 2 {
		odd[s[i]]++
	}
	fmt.Println(min(len(s)-(even["0"]+odd["1"]), len(s)-(even["1"]+odd["0"])))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

