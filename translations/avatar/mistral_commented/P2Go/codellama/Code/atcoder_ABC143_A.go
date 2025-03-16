package main

import "fmt"

func main() {
	var A, B int
	fmt.Scan(&A, &B)
	ans := A - 2*B
	if ans < 0 {
		ans = 0
	}
	fmt.Println(ans)
}

