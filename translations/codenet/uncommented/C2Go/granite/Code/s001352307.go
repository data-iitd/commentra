
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var t int
	var w, n int
	var input [1024][2]int
	var ans [1024][2]int
	var i, j int

	for t = 0; ; t++ {
		for i = 0; i < 1024; i++ {
			ans[i][0] = 0
			ans[i][1] = 0
			input[i][0] = 0
			input[i][1] = 0
		}

		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d", &w, &n)
		if w == 0 {
			break
		}
		for i = 0; i < n; i++ {
			s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
			s = strings.TrimSpace(s)
			s = strings.Replace(s, ",", " ", -1)
			s = strings.Replace(s, " ", "", -1)
			input[i][0], _ = strconv.Atoi(s)
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &input[i][1])
		}

		for i = 0; i < n; i++ {
			for j = 1023; j >= input[i][1]; j-- {
				if ans[j][0] < input[i][0]+ans[j-input[i][1]][0] {
					ans[j][0] = input[i][0] + ans[j-input[i][1]][0]
					ans[j][1] = input[i][1] + ans[j-input[i][1]][1]
				}
			}
		}

		for j = 0; ans[w][0] == ans[w-j-1][0]; j++ {
		}

		fmt.Printf("Case %d:\n%d\n%d\n", t+1, ans[w-j][0], ans[w-j][1])
	}
}

