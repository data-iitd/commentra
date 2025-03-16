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
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	M, _ := strconv.Atoi(sc.Text())
	H := make([]int, N)
	ans := make([]bool, N)
	for i := 0; i < N; i++ {
		sc.Scan()
		H[i], _ = strconv.Atoi(sc.Text())
		ans[i] = true
	}
	for i := 0; i < M; i++ {
		sc.Scan()
		temp1, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		temp2, _ := strconv.Atoi(sc.Text())
		if H[temp1-1] < H[temp2-1] {
			ans[temp1-1] = false
		} else if H[temp1-1] > H[temp2-1] {
			ans[temp2-1] = false
		} else {
			ans[temp1-1] = false
			ans[temp2-1] = false
		}
	}
	ans2 := 0
	for i := 0; i < N; i++ {
		if ans[i] {
			ans2++
		}
	}
	fmt.Println(ans2)
}

