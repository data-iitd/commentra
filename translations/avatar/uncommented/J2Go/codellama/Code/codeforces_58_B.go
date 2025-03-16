
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	fmt.Println(n)
	m := n
	for i := n - 1; i > 0; i-- {
		if m%i == 0 {
			fmt.Println(i)
			m = i
		}
	}
}

