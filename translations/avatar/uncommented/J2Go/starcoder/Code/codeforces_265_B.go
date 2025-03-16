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
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		arr[i], _ = strconv.Atoi(sc.Text())
	}
	ans := arr[0] + 1
	for i := 1; i < n; i++ {
		ans += abs(arr[i] - arr[i-1]) + 2
	}
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

