package main

import (
	"fmt"
	"strconv"
)

func main() {
	var k, n, w string
	fmt.Scan(&k, &n, &w)
	if 1 <= parseInt(k) && parseInt(w) <= 1000 {
		total := 0
		for i := 1; i <= parseInt(w); i++ {
			total += i * parseInt(k)
		}
		if total > parseInt(n) {
			fmt.Println(total - parseInt(n))
		} else {
			fmt.Println(0)
		}
	}
}

func parseInt(s string) int {
	num, _ := strconv.Atoi(s)
	return num
}
