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
	nums := make([]int, N)
	for i := 0; i < N; i++ {
		sc.Scan()
		nums[i], _ = strconv.Atoi(sc.Text())
	}
	diff := 0
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			if nums[i] > nums[j] {
				diff++
			}
		}
	}
	fmt.Println(diff / 2)
}

