package main

import "fmt"

func main() {
	var n, m int
	fmt.Scanf("%d", &n)
	m = n
	n--
	for ; n > 1; n-- {
		m *= n
	}
	fmt.Printf("%d\n", m)
}

