
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	n, m := get_input()
	i := 1
	for m >= i {
		m -= i
		i = (i%n) + 1
	}
	fmt.Println(m)
}

func get_input() (int, int) {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	return n, m
}

