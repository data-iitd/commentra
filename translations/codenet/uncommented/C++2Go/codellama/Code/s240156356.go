package main

import (
	"fmt"
	"sort"
)

func main() {
	var str1, str2 string
	fmt.Scan(&str1, &str2)

	sort.Slice(str1, func(i, j int) bool {
		return str1[i] < str1[j]
	})
	sort.Slice(str2, func(i, j int) bool {
		return str2[i] > str2[j]
	})

	loop := len(str1)
	if len(str2) < loop {
		loop = len(str2)
	}

	flag := false
	for i := 0; i < loop; i++ {
		if str1[i] == str2[i] {
			if i == loop-1 && len(str1) < len(str2) {
				flag = true
				break
			}
		} else {
			if str2[i] > str1[i] {
				flag = true
				break
			} else {
				break
			}
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

