package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	ans := a - 2*b
	if ans < 0 {
		ans = 0
	}
	fmt.Println(ans)
}

