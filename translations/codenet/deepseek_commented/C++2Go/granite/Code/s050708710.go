
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	r, g, b, n := readInt()
	ans := 0
	for i := 0; i <= n/r; i++ {
		for j := 0; j <= n/g; j++ {
			num := n - r*i - g*j
			if num >= 0 && num%b == 0 {
				ans++
			}
		}
	}
	fmt.Println(ans)
}

func readInt() (int, int, int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	var r, g, b, n int
	scanner.Scan()
	r64, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	r = int(r64)
	scanner.Scan()
	g64, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	g = int(g64)
	scanner.Scan()
	b64, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	b = int(b64)
	scanner.Scan()
	n64, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	n = int(n64)
	return r, g, b, n
}

