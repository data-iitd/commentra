package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)

	vec := make([][]int, n)
	for i := 0; i < n; i++ {
		vec[i] = make([]int, 4)
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &vec[i][0], &vec[i][1], &vec[i][2], &vec[i][3])
	}

	ans := 500
	ansprice := 20000

	for i := 0; i < n; i++ {
		flag := 1

		for j := 0; j < n; j++ {
			if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
				flag = 0
				break
			}
		}

		if flag == 1 {
			if vec[i][3] < ansprice {
				ansprice = vec[i][3]
				ans = i + 1
			}
		}
	}

	fmt.Fprintln(writer, ans)
	writer.Flush()
}

