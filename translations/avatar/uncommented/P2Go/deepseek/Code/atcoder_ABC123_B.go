package main

import (
	"fmt"
	"math"
)

func main() {
	menu := [][]int{}
	for i := 0; i < 5; i++ {
		var m string
		fmt.Scan(&m)
		e := int(m[len(m)-1] - '0')
		if e == 0 {
			e = 10
		}
		menu = append(menu, []int{toInt(m), e})
	}

	sortMenu(menu)
	ans := 0
	for _, m := range menu[1:] {
		ans += int(math.Ceil(float64(m[0]) / 10)) * 10
	}
	fmt.Println(ans + menu[0][0])
}

func toInt(s string) int {
	num := 0
	for _, ch := range s {
		num = num*10 + int(ch-'0')
	}
	return num
}

func sortMenu(menu [][]int) {
	for i := 0; i < len(menu); i++ {
		for j := i + 1; j < len(menu); j++ {
			if menu[i][1] > menu[j][1] {
				menu[i], menu[j] = menu[j], menu[i]
			}
		}
	}
}

