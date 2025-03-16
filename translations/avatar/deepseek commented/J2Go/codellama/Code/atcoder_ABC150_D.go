
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n, m int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ = strconv.Atoi(scanner.Text())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	var gcd int
	var lcd int = 1
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, a[i])
		lcd = lcd * a[i] / gcd
		if lcd > m {
			fmt.Println(0)
			return
		}
	}
	for i := 0; i < n; i++ {
		if (lcd / a[i]) % 2 == 0 {
			fmt.Println(0)
			return
		}
	}
	fmt.Println((m / lcd + 1) / 2)
}

func getGCD(a, b int) int {
	if b == 0 {
		return a
	} else {
		return getGCD(b, a%b)
	}
}

