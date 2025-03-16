package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var N int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &N)
	var M int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &M)

	H := make([]int64, N)
	ans := make([]bool, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &H[i])
		ans[i] = true
	}

	for i := 0; i < M; i++ {
		var temp1, temp2 int
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &temp1)
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &temp2)
		temp1--
		temp2--
		if H[temp1] < H[temp2] {
			ans[temp1] = false
		} else if H[temp1] > H[temp2] {
			ans[temp2] = false
		} else {
			ans[temp1] = false
			ans[temp2] = false
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

