package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var str1, str2 string
	fmt.Scanf("%s %s", &str1, &str2)

	sort.Strings(str1)
	sort.Sort(sort.Reverse(strings.Sort(str2)))

	loop := len(str1)
	if loop > len(str2) {
		loop = len(str2)
	}

	flag := false
	for i := 0; loop > i; i++ {
		ch1 := str1[i]
		ch2 := str2[i]

		if ch1 == ch2 {
			if loop == i+1 && len(str1) < len(str2) {
				flag = true
				break
			} else {
				continue
			}
		} else {
			if ch2 > ch1 {
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

