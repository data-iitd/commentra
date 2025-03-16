package main

import (
	"fmt"
	"os"
)

func main() {
	var n, m int
	fmt.Fscan(os.Stdin, &n, &m)
	fmt.Printf("%d\n", (n - 1) * (m - 1))
}

