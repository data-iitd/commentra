package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	var vec [][]int
	for i := 0; i < n; i++ {
		var temp []int
		for j := 0; j < 4; j++ {
			var temp2 int
			fmt.Fscan(reader, &temp2)
			temp = append(temp, temp2)
		}
		vec = append(vec, temp)
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
}

