package main

import (
	"fmt"
)

func main() {
	var a, b, x int64
	fmt.Scanf("%d %d %d", &a, &b, &x)
	s := (b/x - a/x)
	if a%x == 0 {
		s++
	}
	fmt.Println(s)
}

// <END-OF-CODE>
