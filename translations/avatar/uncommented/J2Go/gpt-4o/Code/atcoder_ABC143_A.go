package main

import (
	"fmt"
	"os"
)

func main() {
	var a, b int
	_, err := fmt.Scanf("%d %d", &a, &b)
	if err != nil {
		return
	}
	c := a - b*2
	if c < 0 {
		c = 0
	}
	fmt.Println(c)
}

// <END-OF-CODE>
