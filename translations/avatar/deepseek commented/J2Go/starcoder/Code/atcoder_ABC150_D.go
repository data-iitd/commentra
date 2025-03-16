
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
	fmt.Println("Enter the size of the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the value of m")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	a := make([]int, n)
	fmt.Println("Enter the array elements")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	var gcd, lcd int
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, a[i])
		lcd = lcd*a[i]/gcd
		if lcd > m {
			fmt.Println(0)
			return
		}
	}
	for i := 0; i < n; i++ {
		if lcd/a[i]%2 == 0 {
			fmt.Println(0)
			return
		}
	}
	fmt.Println(m/lcd + 1)
}

func getGCD(a, b int) int {
	if b == 0 {
		return a
	} else {
		return getGCD(b, a%b)
	}
}

