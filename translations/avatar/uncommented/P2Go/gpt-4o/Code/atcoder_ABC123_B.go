package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
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
		num, _ := strconv.Atoi(m)
		menu = append(menu, []int{num, e})
	}

	sort.Slice(menu, func(i, j int) bool {
		return menu[i][1] < menu[j][1]
	})

	ans := 0
	for _, m := range menu[1:] {
		ans += int(math.Ceil(float64(m[0]) / 10)) * 10
	}
	fmt.Println(ans + menu[0][0])
}

// <END-OF-CODE>
