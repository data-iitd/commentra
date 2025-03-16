
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialCapacity = 4096
	var buf []byte
	scanner.Buffer(buf, initialCapacity)
	scanner.Split(bufio.ScanWords)

	var A, B int64
	scanner.Scan()
	A, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	B, _ = strconv.ParseInt(scanner.Text(), 10, 64)

	fmt.Println((A * B) / gcd(A, B))
}

func gcd(x, y int64) int64 {
	var tmp int64

	if x < y {
		tmp = x
		x = y
		y = tmp
	}

	for y!= 0 {
		tmp = y
		y = x % y
		x = tmp
	}

	return x
}

