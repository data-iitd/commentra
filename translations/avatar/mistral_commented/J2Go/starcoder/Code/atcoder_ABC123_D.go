
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	x := make([]int, 3)
	max := 0

	for i := 0; i < 3; i++ {
		sc.Scan()
		x[i], _ = strconv.Atoi(sc.Text())
		max = int(math.Max(float64(max), float64(x[i])))
	}

	k, _ := strconv.Atoi(sc.Text())

	a := make([][]int, 3)
	for i := 0; i < 3; i++ {
		a[i] = make([]int, x[i])
		for j := 0; j < x[i]; j++ {
			sc.Scan()
			a[i][j], _ = strconv.Atoi(sc.Text())
		}
		sort.Ints(a[i])
	}

	ans := make([]int, 0)

	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				if (i+1)*(j+1)*(m+1) <= k {
					tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1]
					ans = append(ans, tmp)
				}
			}
		}
	}

	sort.Ints(ans)

	for i := 0; i < k; i++ {
		fmt.Println(ans[len(ans)-i-1])
	}
}

