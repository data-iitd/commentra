package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	n, a, b := 0, 0, 0
	n, _ = strconv.Atoi(sc.Text())
	a, _ = strconv.Atoi(sc.Text())
	b, _ = strconv.Atoi(sc.Text())
	list1 := make([]int, a)
	list2 := make([]int, b)
	for i := 0; i < a; i++ {
		list1[i], _ = strconv.Atoi(sc.Text())
	}
	for i := 0; i < b; i++ {
		list2[i], _ = strconv.Atoi(sc.Text())
	}
	for i := 0; i < n; i++ {
		if contains(list1, i+1) {
			fmt.Print("1 ")
		} else {
			fmt.Print("2 ")
		}
	}
}

func contains(list []int, val int) bool {
	for _, v := range list {
		if v == val {
			return true
		}
	}
	return false
}

