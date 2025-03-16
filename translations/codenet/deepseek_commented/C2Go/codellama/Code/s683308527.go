package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		var s string
		fmt.Scanf("%s", &s)
		s = strings.Replace(s, "Hoshino", "Hoshina", -1)
		fmt.Println(s)
	}
}

