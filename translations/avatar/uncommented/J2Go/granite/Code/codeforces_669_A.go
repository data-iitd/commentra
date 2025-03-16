
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine())
	solve(n)
}

func solve(n int) {
	fmt.Println((n / 3) * 2 + (n % 3 == 0? 0 : 1))
}

