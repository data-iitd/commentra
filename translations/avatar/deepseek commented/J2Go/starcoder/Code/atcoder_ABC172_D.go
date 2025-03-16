
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter n: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))
	ans := 0

	for i := 1; i < n+1; i++ {
		term := n / i
		sum := term * (term + 1) / 2
		ans += i * sum
	}

	fmt.Println(ans)
}

