package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	var x [3]int
	max := 0
	for i := 0; i < 3; i++ {
		scanner.Scan()
		x[i] = toInt(scanner.Text())
		if x[i] > max {
			max = x[i]
		}
	}
	
	scanner.Scan()
	k := toInt(scanner.Text())
	
	a := make([][]int, 3)
	for i := 0; i < 3; i++ {
		a[i] = make([]int, x[i])
		for j := 0; j < x[i]; j++ {
			scanner.Scan()
			a[i][j] = toInt(scanner.Text())
		}
		sort.Ints(a[i])
	}
	
	ans := []int{}
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
	n := len(ans)
	for i := 0; i < k; i++ {
		fmt.Println(ans[n-i-1])
	}
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

