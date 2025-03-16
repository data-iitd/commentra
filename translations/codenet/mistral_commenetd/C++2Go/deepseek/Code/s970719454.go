package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var here [100001]int
	var dp1 [100001]int
	var dp2 [100001]int

	for {
		var n, m int
		fmt.Fscan(reader, &n, &m)
		if n == 0 {
			break
		}

		for i := 0; i < 100001; i++ {
			here[i] = 0
			dp1[i] = 0
			dp2[i] = 0
		}

		dpflg := false

		for i := 0; i < m; i++ {
			var a int
			fmt.Fscan(reader, &a)
			here[a] = 1
			if a == 0 {
				dpflg = true
			}
		}

		maxi1 := 0
		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp1[i] = dp1[i-1] + 1
			}
			if dp1[i] > maxi1 {
				maxi1 = dp1[i]
			}
		}

		maxi2 := 0
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
			fmt.Fprintln(writer, maxi1)
		} else {
			fmt.Fprintln(writer, maxi2)
		}
	}
}

