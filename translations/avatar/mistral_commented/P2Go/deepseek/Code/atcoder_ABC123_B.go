package main

import (
	"fmt"
	"math"
)

func main() {
	var menu [][]int

	for i := 0; i < 5; i++ {
		var m string
		fmt.Scan(&m)

		e := int(m[len(m)-1] - '0')
		if e == 0 {
			e = 10
		}

		menu = append(menu, []int{int(m[0] - '0'), e})
	}

	for i := 0; i < len(menu); i++ {
		for j := i + 1; j < len(menu); j++ {
			if menu[i][1] > menu[j][1] {
				menu[i], menu[j] = menu[j], menu[i]
			}
		}
	}

	var ans int

	for _, m := range menu[1:] {
		numFull10s := int(math.Ceil(float64(m[0]) / 10))
		ans += numFull10s * 10
	}

	fmt.Println(menu[0][0] + ans)
}

