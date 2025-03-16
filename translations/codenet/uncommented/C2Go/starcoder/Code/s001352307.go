package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		W, N int
		i, j int
		ans  [1024][2]
		input [1024][2]
	)

	for t := 0; ; t++ {
		for i = 0; i < 1024; i++ {
			ans[i][0] = 0
			ans[i][1] = 0
			input[i][0] = 0
			input[i][1] = 0
		}

		fmt.Scanf("%d%d", &W, &N)
		if W == 0 {
			break
		}
		for i = 0; i < N; i++ {
			fmt.Scanf("%d,%d", &input[i][0], &input[i][1])
		}

		for i = 0; i < N; i++ {
			for j = 1023; j >= input[i][1]; j-- {
				if ans[j][0] < input[i][0]+ans[j-input[i][1]][0] {
					ans[j][0] = input[i][0] + ans[j-input[i][1]][0]
					ans[j][1] = input[i][1] + ans[j-input[i][1]][1]
				}
			}
		}

		for j = 0; ans[W][0] == ans[W-j-1][0]; j++ {
		}

		fmt.Printf("Case %d:\n%d\n%d\n", t+1, ans[W-j][0], ans[W-j][1])
	}
}

