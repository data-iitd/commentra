package main

import (
	"fmt"
	"strings"
)

func main() {
	var str1, str2 string
	fmt.Scan(&str1)
	fmt.Scan(&str2)

	if len(str1) != len(str2) {
		fmt.Println("NO")
	} else {
		str1 = strings.Reverse(str1)
		if str1 == str2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

