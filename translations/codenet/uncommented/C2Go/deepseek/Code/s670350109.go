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

	temp := make([]byte, len(str1))
	j := len(str1) - 1
	for i := 0; i < len(str1); i++ {
		temp[i] = str1[j]
		j--
	}

	if strings.EqualFold(string(temp), str2) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

