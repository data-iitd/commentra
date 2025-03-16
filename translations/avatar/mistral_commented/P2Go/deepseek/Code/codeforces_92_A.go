package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, m int
	fmt.Scanln(&n, &m)

	i := 1

	for m >= i {
		m -= i
		i = (i % n) + 1
	}

	fmt.Println(m)
}
