
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the value of n:")
	n, _ := reader.ReadString('\n')
	n, _ = strconv.Atoi(n)
	fmt.Println("Enter the value of m:")
	m, _ := reader.ReadString('\n')
	m, _ = strconv.Atoi(m)

	ans := 0

	// gu gu
	ans += n * (n - 1) / 2

	// kiki
	ans += m * (m - 1) / 2

	fmt.Println(ans)
}

