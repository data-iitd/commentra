package main

import (
	"fmt"
)

func main() {
	var n int
	var m uint64
	fmt.Scan(&n)
	m = uint64(n)
	n--
	for n > 1 {
		m *= uint64(n)
		n--
	}
	fmt.Println(m)
}

// <END-OF-CODE>
