package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)

	s := strings.Split(input, "")
	dt := make(map[string]int)

	for _, i := range s {
		dt[i]++
	}

	cnt := 0
	x := true

	for _, value := range dt {
		if value%2 != 0 && cnt < 1 {
			cnt++
		} else if value%2 != 0 && cnt >= 1 {
			x = false
			break
		}
	}

	if x {
		fmt.Println("First")
	} else if !x && len(s)%2 == 0 {
		fmt.Println("Second")
	} else if !x && len(s)%2 != 0 {
		fmt.Println("First")
	}
}

// <END-OF-CODE>
