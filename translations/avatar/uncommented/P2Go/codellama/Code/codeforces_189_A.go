package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func cutRibbon() {
	arr := strings.Split(input(), " ")
	length, _ := strconv.Atoi(arr[0])
	arr = arr[1:4]
	sort.Ints(arr)
	if length%arr[0] == 0 {
		fmt.Println(length / arr[0])
		return
	}
	ans := 0
	if arr[0] == arr[1] {
		for i := 0; i <= int(length/arr[2]); i++ {
			check := length - i*arr[2]
			if check >= 0 && check%arr[0] == 0 {
				k := check / arr[0]
				ans = max(ans, k+i)
			}
		}
	} else {
		for i := 0; i <= int(length/arr[2]); i++ {
			for j := 0; j <= int(length/arr[1]); j++ {
				check := length - i*arr[2] - j*arr[1]
				if check >= 0 && check%arr[0] == 0 {
					k := check / arr[0]
					ans = max(ans, k+i+j)
				}
			}
		}
	}
	fmt.Println(ans)
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

func main() {
	cutRibbon()
}

