
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	n, _ := strconv.Atoi(reader.ReadLine()[2:])

	vec := make([][]int, n)
	for i := 0; i < n; i++ {
		vec[i] = make([]int, 4)
		for j := 0; j < 4; j++ {
			vec[i][j], _ = strconv.Atoi(reader.ReadLine()[2:])
		}
	}

	ans := 500
	ansPrice := 200000

	for i := 0; i < n; i++ {
		flag := true
		for j := 0; j < n; j++ {
			if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
				flag = false
				break
			}
		}

		if flag {
			if vec[i][3] < ansPrice {
				ansPrice = vec[i][3]
				ans = i + 1
			}
		}
	}

	fmt.Println(ans)
	writer.Flush()
}

