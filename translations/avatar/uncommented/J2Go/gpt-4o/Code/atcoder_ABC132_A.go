package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)
	targ := []rune(s)
	mapCount := make(map[rune]int)

	for _, char := range targ {
		mapCount[char]++
	}

	ok := true
	if len(mapCount) == 2 {
		for _, count := range mapCount {
			if count != 2 {
				ok = false
				break
			}
		}
	} else {
		ok = false
	}

	if ok {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
