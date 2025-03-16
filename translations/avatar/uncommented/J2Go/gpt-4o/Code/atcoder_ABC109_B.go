package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	mapData := make(map[int]string)
	for i := 0; i < N; i++ {
		var input string
		fmt.Scan(&input)
		mapData[i] = input
	}

	ans := true
	past := make(map[int]string)
	next := ""

	for i := 0; i < N; i++ {
		if containsValue(past, mapData[i]) {
			ans = false
			break
		}
		past[i] = mapData[i]

		if i != 0 {
			if next != string(mapData[i][0]) {
				ans = false
				break
			}
		}
		next = string(mapData[i][len(mapData[i])-1])
	}

	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func containsValue(m map[int]string, value string) bool {
	for _, v := range m {
		if v == value {
			return true
		}
	}
	return false
}
