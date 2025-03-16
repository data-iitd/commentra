package main

import (
	"fmt"
)

func main() {
	var str string
	fmt.Scan(&str)

	max := 0
	cnt := 0
	for _, sc := range str {
		if sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T' {
			cnt++
		} else {
			cnt = 0
		}
		if cnt > max {
			max = cnt
		}
	}

	fmt.Println(max)
}

// <END-OF-CODE>
