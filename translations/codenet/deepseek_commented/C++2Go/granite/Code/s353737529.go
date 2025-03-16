
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
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	if n == 0 {
		fmt.Println("0")
		return
	}

	s := ""
	for n!= 0 {
		if n%2 == 0 {
			s += "0"
		} else {
			s += "1"
		}
		n -= abs(n % 2)
		n /= -2
	}

	s = reverse(s)
	fmt.Println(s)
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

