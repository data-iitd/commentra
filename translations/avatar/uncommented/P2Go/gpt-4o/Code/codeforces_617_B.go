package main

import (
	"fmt"
	"strings"
)

func main() {
	var a string
	fmt.Scanln(&a)

	if strings.Count(a, "1") == 0 {
		fmt.Println(0)
		return
	}

	segments := strings.Split(strings.Trim(a, "0 "), "1")
	prod := 1
	for _, segment := range segments {
		prod *= len(segment) + 1
	}

	fmt.Println(prod)
}

// <END-OF-CODE>
