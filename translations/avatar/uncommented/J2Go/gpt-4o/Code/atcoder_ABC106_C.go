package main

import (
	"fmt"
)

func main() {
	var str string
	var k int64
	fmt.Scan(&str)
	fmt.Scan(&k)

	c := []rune(str)
	n := len(c)

	for i := int64(0); i < k; i++ {
		if c[i] == '1' {
			if i == k-1 {
				fmt.Println(1)
				return
			}
		} else {
			fmt.Println(string(c[i]))
			return
		}
	}
}

// <END-OF-CODE>
