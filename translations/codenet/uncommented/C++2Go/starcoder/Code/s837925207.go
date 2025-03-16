package main

import (
	"fmt"
	"math"
)

func main() {
	var x, ans int
	fmt.Scanf("%d", &x)
	ans = x + x*x + x*x*x
	fmt.Println(ans)
}

