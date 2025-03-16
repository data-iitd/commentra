
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scanf("%s", &s)
	t = s[0:1]
	t += fmt.Sprintf("%d", len(s)-2)
	t += s[len(s)-1:]
	fmt.Println(t)
}

