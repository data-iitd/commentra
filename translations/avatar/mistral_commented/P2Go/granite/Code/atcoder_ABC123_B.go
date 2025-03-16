
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	menu := make([][]int, 5)
	for i := 0; i < 5; i++ {
		var m string
		fmt.Scanln(&m)
		e, _ := strconv.Atoi(string(m[len(m)-1]))
		if e == 0 {
			e = 10
		}
		menu[i] = []int{strconv.Atoi(m), e}
	}
	for i := 1; i < len(menu); i++ {
		menu[i][0] = int(math.Ceil(float64(menu[i][0]) / 10)) * 10
	}
	ans := 0
	for _, m := range menu {
		ans += m[0]
	}
	fmt.Println(menu[0][0] + ans)
}

