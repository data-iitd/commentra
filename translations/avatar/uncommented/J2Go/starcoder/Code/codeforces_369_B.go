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
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	fmt.Println("Enter the number of elements to be incremented")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	fmt.Println("Enter the lower bound of the increment")
	l, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	fmt.Println("Enter the upper bound of the increment")
	r, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	fmt.Println("Enter the sum of all the elements")
	sAll, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	fmt.Println("Enter the sum of the elements to be incremented")
	sk, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	ans := getPoints(n, k, l, r, sAll, sk)
	for _, num := range ans {
		fmt.Print(num, " ")
	}
}

func getPoints(n, k, l, r, sAll, sk int) []int {
	ans := make([]int, n)
	for i := 0; i < n; i++ {
		ans[i] = l
	}
	sAll -= sk + (n-k)*l
	sk -= k * l
	for sk > 0 {
		idx := n - 1
		for sk > 0 && idx >= n-k {
			ans[idx]++
			sk--
			idx--
		}
	}
	for sAll > 0 {
		idx := 0
		for sAll > 0 && idx < n-k {
			ans[idx]++
			sAll--
			idx++
		}
	}
	return ans
}

