
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n, m int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ = strconv.Atoi(scanner.Text())
	if n == 0 {
		if m != 0 {
			fmt.Println("Impossible")
		} else {
			fmt.Println(0, 0)
		}
		return
	}
	if m <= n {
		if m == 0 {
			m = 1
		}
		fmt.Println(n, m+n-1)
		return
	}
	fmt.Println(m, m+n-1)
}

