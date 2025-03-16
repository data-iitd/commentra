
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	m, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
		a[i] /= 2
	}
	gcd := int64(0)
	lcd := int64(1)
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, int64(a[i]))
		lcd = lcd*int64(a[i])/gcd
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
	fmt.Println((m / int(lcd) + 1) / 2)
}

func getGCD(a, b int64) int64 {
	if b == 0 {
		return a
	} else {
		return getGCD(b, a%b)
	}
}

