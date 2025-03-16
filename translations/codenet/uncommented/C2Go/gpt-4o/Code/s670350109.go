package main

import (
	"fmt"
	"strings"
)

func main() {
	var str1, str2 string
	fmt.Scanln(&str1)
	fmt.Scanln(&str2)

	if len(str1) != len(str2) {
		fmt.Println("NO")
		return
	}

	temp := make([]rune, len(str1))
	for i, j := len(str1)-1, 0; i >= 0; i, j = i-1, j+1 {
		temp[j] = rune(str1[i])
	}

	t := 0
	for i := 0; i < len(temp); i++ {
		if temp[i] == rune(str2[i]) {
			t++
		}
	}

	if len(str2) == t {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
