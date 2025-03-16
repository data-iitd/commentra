package main

import (
	"fmt"
	"strconv"
	"strings"
)

var W, N int
var input [1024][2]int

func main() {
	for t := 0; ; t++ {
		var ans [1024][2]int
		for i := 0; i < 1024; i++ {
			input[i][0] = 0
			input[i][1] = 0
		}

		fmt.Scanf("%d%d", &W, &N)
		if W == 0 {
			break
		}
		for i := 0; i < N; i++ {
			var s string
			fmt.Scanf("%s", &s)
			parts := strings.Split(s, ",")
			input[i][0], _ = strconv.Atoi(parts[0])
			input[i][1], _ = strconv.Atoi(parts[1])
		}

		for i := 0; i < N; i++ {
			for j := 1023; j >= input[i][1]; j-- {
				if ans[j][0] < input[i][0]+ans[j-input[i][1]][0] {
					ans[j][0] = input[i][0] + ans[j-input[i][1]][0]
					ans[j][1] = input[i][1] + ans[j-input[i][1]][1]
				}
			}
		}

		j := 0
		for ; ans[W][0] == ans[W-j-1][0]; j++ {
		}

		fmt.Printf("Case %d:\n%d\n%d\n", t+1, ans[W-j][0], ans[W-j][1])
	}
}

