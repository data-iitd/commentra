
package main

import (
	"fmt"
	"os"
)

func main() {
	input := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	var n int
	fmt.Scan(&n)
	vec := make([][]int, n)
	for i := 0; i < n; i++ {
		vec[i] = make([]int, 4)
		fmt.Scan(&vec[i][0], &vec[i][1], &vec[i][2], &vec[i][3])
	}
	ans := 500
	ansprice := 20000
	for i := 0; i < n; i++ {
		fl := 1
		for j := 0; j < n; j++ {
			if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
				fl = 0
			}
		}
		if fl == 1 {
			if vec[i][3] < ansprice {
				ansprice = vec[i][3]
				ans = i + 1
			}
		}
	}
	fmt.Println(ans)
	out.Flush()
}

