
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
	fmt.Println("Enter the number of elements in each list")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)
	fmt.Println("Enter the first list of integers")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	fmt.Println("Enter the second list of integers")
	for i := 0; i < n; i++ {
		b[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	fmt.Println("Enter the third list of integers")
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	x := 0
	y := 0
	z := 0
	for i := 0; i < n; i++ {
		x += a[i]
		y += b[i]
		z += c[i]
	}
	fmt.Println(abs(x-y))
	fmt.Println(abs(y-z))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

