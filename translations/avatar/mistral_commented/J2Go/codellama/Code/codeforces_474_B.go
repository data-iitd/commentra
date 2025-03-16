package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := make(chan string)
	go read(sc)
	n := <-sc
	arr := make([]int, n)
	arr[0] = <-sc
	for i := 1; i < n; i++ {
		arr[i] = <-sc + arr[i-1]
	}
	m := <-sc
	q := make([]int, m)
	for i := 0; i < m; i++ {
		q[i] = <-sc
	}
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n, m) + 1)
	}
}

func read(sc chan string) {
	sc <- readLine()
	sc <- readLine()
	for i := 0; i < n; i++ {
		sc <- readLine()
	}
	sc <- readLine()
	for i := 0; i < m; i++ {
		sc <- readLine()
	}
}

func readLine() string {
	var line string
	fmt.Scanln(&line)
	return line
}

func fun(arr []int, q int, n int, m int) int {
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

