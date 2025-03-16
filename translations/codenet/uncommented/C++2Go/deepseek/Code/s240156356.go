package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var str1, str2 string
	fmt.Scan(&str1, &str2)

	str1Slice := strings.Split(str1, "")
	str2Slice := strings.Split(str2, "")

	sort.Strings(str1Slice)
	sort.Sort(sort.Reverse(sort.StringSlice(str2Slice)))

	loop := len(str1Slice)
	if len(str2Slice) < loop {
		loop = len(str2Slice)
	}

	flag := false

	for i := 0; i < loop; i++ {
		ch1 := str1Slice[i]
		ch2 := str2Slice[i]

		if ch1 == ch2 {
			if i == loop-1 && len(str1Slice) < len(str2Slice) {
				flag = true
				break
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

