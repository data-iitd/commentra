package main

import (
	"fmt"
)

func main() {
	var a, b, c, d int

	fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)

	i := a * b
	j := c * d
	if i > j {
		fmt.Println(i)
	} else {
		fmt.Println(j)
	}
}

// <END-OF-CODE>
