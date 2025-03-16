
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	a, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	b, _ := strconv.Atoi(sc.Text())
	count := 0
	for {
		if a > 0 && b > 0 {
			count++
			a--
			b--
		} else {
			break
		}
	}
	ans := a/2 + b/2
	fmt.Println(count, ans)
}

