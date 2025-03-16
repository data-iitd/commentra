package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		var n, m int
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &n, &m)
		if n == 0 {
			break
		}

		here := make([]int, 100001)
		dp1 := make([]int, 100001)
		dp2 := make([]int, 100001)

		dpflg := false

		for i := 0; i < m; i++ {
			var a int
			scanner.Scan()
			fmt.Sscan(scanner.Text(), &a)
			if a == 0 {
				dpflg = true
			}
			here[a] = 1
		}

		maxi1 := 0
		maxi2 := 0

		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp1[i] = dp1[i-1] + 1
			}
			if dp1[i] > maxi1 {
				maxi1 = dp1[i]
			}
		}

		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp2[i] = dp2[i-1] + 1
			} else {
				dp2[i] = dp1[i-1] + 1
			}
			if dp2[i] > maxi2 {
				maxi2 = dp2[i]
			}
		}

		if !dpflg {
			fmt.Println(maxi1)
		} else {
			fmt.Println(maxi2)
		}
	}
}

