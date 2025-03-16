package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var N int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	var M int64
	sc.Scan()
	M, _ = strconv.ParseInt(sc.Text(), 10, 64)
	H := make([]int64, N)
	ans := make([]bool, N)
	for i := 0; i < N; i++ {
		sc.Scan()
		H[i], _ = strconv.ParseInt(sc.Text(), 10, 64)
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

