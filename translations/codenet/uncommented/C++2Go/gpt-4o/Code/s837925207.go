package main

import (
	"fmt"
)

func main() {
	var x, ans int

	fmt.Scan(&x)

	ans = x + x*x + x*x*x

	fmt.Println(ans)
}

// <END-OF-CODE>
