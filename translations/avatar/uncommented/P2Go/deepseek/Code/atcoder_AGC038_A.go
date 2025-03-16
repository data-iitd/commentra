package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(H int, W int, A int, B int) {
	answer := make([][]string, H)
	for i := 0; i < H; i++ {
		answer[i] = make([]string, W)
		for j := 0; j < W; j++ {
			if i < B {
				if j < A {
					answer[i][j] = "0"
				} else {
					answer[i][j] = "1"
				}
			} else {
				if j < A {
					answer[i][j] = "1"
				} else {
					answer[i][j] = "0"
				}
			}
		}
	}
	for i := 0; i < H; i++ {
		fmt.Println(answer[i])
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	H := nextInt(sc)
	W := nextInt(sc)
	A := nextInt(sc)
	B := nextInt(sc)
	solve(H, W, A, B)
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}
