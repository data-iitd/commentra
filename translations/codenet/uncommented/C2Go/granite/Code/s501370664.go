
package main

import (
	"bufio"
	"fmt"
	"os"
)

var flag []bool

func prime(num int) {
	flag = make([]bool, num+1)
	for i := 2; i*i <= num; i++ {
		if!flag[i] {
			for j := 2; i*j <= num; j++ {
				flag[i*j] = true
			}
		}
	}
}

func main() {
	var n, i, cnt int
	prime(50000)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		n, _ = fmt.Sscanf(scanner.Text(), "%d", &n)
		if n == 0 {
			break
		}
		i = 2
		cnt = 0
		for i*2 <= n {
			if!flag[i] &&!flag[n-i] {
				cnt++
			}
			i++
		}
		fmt.Println(cnt)
	}
}

