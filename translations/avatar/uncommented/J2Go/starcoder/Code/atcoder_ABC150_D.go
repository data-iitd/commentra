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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the maximum limit")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	a := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	var gcd, lcd int64
	lcd = 1
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, int64(a[i]))
		lcd = lcd * int64(a[i]) / gcd
		if lcd > int64(m) {
			fmt.Println(0)
			return
		}
	}
	for i := 0; i < n; i++ {
		if (lcd/int64(a[i]))%2 == 0 {
			fmt.Println(0)
			return
		}
	}
	fmt.Println((int64(m)/lcd+1)/2)
}

func getGCD(a, b int64) int64 {
	if b == 0 {
		return a
	} else {
		return getGCD(b, a%b)
	}
}

