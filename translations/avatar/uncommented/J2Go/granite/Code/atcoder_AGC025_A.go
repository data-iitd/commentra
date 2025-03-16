
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func sum(a int) int {
	ans := 0
	for a >= 10 {
		ans += a % 10
		a /= 10
	}
	ans += a
	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr)
	var n2 int
	if n%2 == 0 {
		n2 = n / 2
	} else {
		n2 = (n + 1) / 2
	}
	ans := sum(1) + sum(n-1)
	for a := 1; a <= n2; a++ {
		if sum(a)+sum(n-a) < ans {
			ans = sum(a) + sum(n-a)
		}
	}
	fmt.Println(ans)
}

