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
	fmt.Println("Enter the number of elements")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the number of elements in the first group")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the lower bound for the points")
	l, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the upper bound for the points")
	r, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the total sum of points")
	sAll, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the sum of points for the first group")
	sk, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

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

