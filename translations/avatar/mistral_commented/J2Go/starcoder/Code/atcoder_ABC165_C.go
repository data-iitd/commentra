
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b, c, d, n, m, q int
	var ans int64
	var a_arr, b_arr, c_arr, d_arr []int
	var list []int
	var str string
	var str_arr []string
	var i, j int
	var score int64

	reader := bufio.NewReader(os.Stdin)
	str, _ = reader.ReadString('\n')
	str_arr = strings.Split(str, " ")
	n, _ = strconv.Atoi(str_arr[0])
	m, _ = strconv.Atoi(str_arr[1])
	q, _ = strconv.Atoi(str_arr[2])

	a_arr = make([]int, q)
	b_arr = make([]int, q)
	c_arr = make([]int, q)
	d_arr = make([]int, q)

	for i = 0; i < q; i++ {
		str, _ = reader.ReadString('\n')
		str_arr = strings.Split(str, " ")
		a_arr[i], _ = strconv.Atoi(str_arr[0])
		b_arr[i], _ = strconv.Atoi(str_arr[1])
		c_arr[i], _ = strconv.Atoi(str_arr[2])
		d_arr[i], _ = strconv.Atoi(str_arr[3])
	}

	dfs(list)

	fmt.Println(ans)
}

func dfs(list []int) {
	if len(list) == n {
		score = 0
		for i = 0; i < q; i++ {
			if list[b_arr[i]-1]-list[a_arr[i]-1] == c_arr[i] {
				score += d_arr[i]
			}
		}
		ans = max(ans, score)
		return
	}

	if len(list)!= 0 {
		for num := list[len(list)-1]; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	} else {
		for num := 1; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	}
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

