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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := make([]int, n)
	arr[0], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	for i := 1; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		arr[i] += arr[i-1]
	}
	fmt.Println("Enter the number of queries")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	q := make([]int, m)
	for i := 0; i < m; i++ {
		q[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n, m) + 1)
	}
}

func fun(arr []int, q int, n, m int) int {
	res := 0
	i := 0
	j := n
	for i <= j {
		md := i + (j-i)/2
		if arr[md] == q {
			return md
		} else if arr[md] > q {
			res = md
			j = md - 1
		} else {
			i = md + 1
		}
	}
	return res
}

