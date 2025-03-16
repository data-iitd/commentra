
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const MOD = 100000007

	for scanner.Scan() {
		text := scanner.Text()
		if text == "0" {
			break
		}

		nStr := text
		mStr := scanner.Text()
		n, _ := strconv.Atoi(nStr)
		m, _ := strconv.Atoi(mStr)

		a := make([]int, m)
		for i := 0; i < m; i++ {
			scanner.Scan()
			a[i], _ = strconv.Atoi(scanner.Text())
		}

		dp1 := make([]int, n+1)
		dp2 := make([]int, n+1)
		for i := 0; i < m; i++ {
			dp1[a[i]] = 1
			dp2[a[i]] = 1
		}

		for i := 1; i <= n; i++ {
			if dp1[i-1]!= 0 {
				dp1[i] = dp1[i-1] + 1
			}
			if dp2[i-1]!= 0 {
				dp2[i] = dp2[i-1] + 1
			}
			if dp1[i-1]!= 0 && a[i-1]+1 == i {
				dp2[i] = max(dp2[i], dp1[i-1]+1)
			}
		}

		max1 := 0
		max2 := 0
		for i := 1; i <= n; i++ {
			max1 = max(max1, dp1[i])
			max2 = max(max2, dp2[i])
		}

		fmt.Println(max2)
	}
}

func max(x, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}

