package main

import (
	"fmt"
	"os"
)

func solve(H int, W int, A int, B int) {
	answer := make([][]string, H)
	for i := range answer {
		answer[i] = make([]string, W)
		for j := range answer[i] {
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
		fmt.Println(join(answer[i]))
	}
}

func join(arr []string) string {
	result := ""
	for _, s := range arr {
		result += s
	}
	return result
}

func main() {
	var H, W, A, B int
	fmt.Scan(&H, &W, &A, &B)
	solve(H, W, A, B)
}

// <END-OF-CODE>
