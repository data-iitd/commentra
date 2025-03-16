package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	S := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}
	march := []string{"M", "A", "R", "C", "H"}
	march_lis := make([]int, 5)
	for _, s := range S {
		if strings.ToUpper(s[0:1]) == march[0] {
			march_lis[0]++
		} else if strings.ToUpper(s[0:1]) == march[1] {
			march_lis[1]++
		} else if strings.ToUpper(s[0:1]) == march[2] {
			march_lis[2]++
		} else if strings.ToUpper(s[0:1]) == march[3] {
			march_lis[3]++
		} else if strings.ToUpper(s[0:1]) == march[4] {
			march_lis[4]++
		}
	}
	ans := 0
	for _, x := range march_lis {
		for _, y := range march_lis {
			for _, z := range march_lis {
				ans += x * y * z
			}
		}
	}
	fmt.Println(ans)
}



