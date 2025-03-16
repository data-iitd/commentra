package main

import (
	"fmt"
)

func main() {
	var W, N int
	input := make([][2]int, 1024)
	ans := make([][2]int, 1024)

	for t := 0; ; t++ {
		for i := 0; i < 1024; i++ {
			ans[i][0] = 0
			ans[i][1] = 0
			input[i][0] = 0
			input[i][1] = 0
		}

		_, err := fmt.Scanf("%d%d", &W, &N)
		if err != nil || W == 0 {
			break
		}
		for i := 0; i < N; i++ {
			_, err := fmt.Scanf("%d,%d", &input[i][0], &input[i][1])
			if err != nil {
				break
			}
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
		for ans[W][0] == ans[W-j-1][0] {
			j++
		}

		fmt.Printf("Case %d:\n%d\n%d\n", t+1, ans[W-j][0], ans[W-j][1])
	}
}

// <END-OF-CODE>
