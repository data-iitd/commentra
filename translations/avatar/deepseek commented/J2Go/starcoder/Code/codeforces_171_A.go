
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
	fmt.Println("Enter the first integer")
	first, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the second integer")
	second, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println(reverse(second) + first)
}

func reverse(n int) int {
	if n < 10 {
		return n * 10
	}
	t := n
	r := 0
	for t > 0 {
		r = (r * 10) + t%10
		t = t / 10
	}
	return r
}

