
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func gcd(a, b int) int {
	for a%b!= 0 {
		a, b = b, a%b
	}
	return b
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var x, y, a, b int
	scanner.Scan()
	x, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	y, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	a, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ = strconv.Atoi(scanner.Text())
	lcm := lcm(x, y)
	fmt.Println(b/lcm - (a-1)/lcm)
}

