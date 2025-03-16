package main

import "fmt"

func main() {
	var W, N int
	var input [1024][2]int

	for {
		for i := 0; i < 1024; i++ {
			input[i][0] = 0
			input[i][1] = 0
		}

		fmt.Scanf("%d%d", &W, &N)
		if W == 0 {
			break
		}
		for i := 0; i < N; i++ {
			fmt.Scanf("%d,%d", &input[i][0], &input[i][1])
		}

		for i := 0; i < N; i++ {
			for j := 1023; j >= input[i][1]; j-- {
				if input[i][0]+input[j-input[i][1]][0] > input[j][0] {
					input[j][0] = input[i][0] + input[j-input[i][1]][0]
					input[j][1] = input[i][1] + input[j-input[i][1]][1]
				}
			}
		}

		for j := 0; input[W][0] == input[W-j-1][0]; j++ {
		}

		fmt.Printf("Case %d:\n%d\n%d\n", W-j, input[W-j][0], input[W-j][1])
	}
}

