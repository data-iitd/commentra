
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	solve(n)
}

func solve(n int) {
	fmt.Println((n / 3) * 2 + (n % 3 == 0 ? 0 : 1))
}

