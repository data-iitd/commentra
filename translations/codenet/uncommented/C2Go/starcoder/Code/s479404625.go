package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	var a, b, c string
	fmt.Scanf("%s %s %s", &a, &b, &c)
	la := len(a)
	lb := len(b)
	if a[la-1] == b[0] && b[lb-1] == c[0] {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

