package main

import (
	"fmt"
	"strings"
)

func main() {
	var S string
	fmt.Scan(&S)

	// 後ろから解くかわりにすべての文字列を「左右反転」する
	S = reverse(S)
	divide := []string{"dream", "dreamer", "erase", "eraser"}
	for i := 0; i < len(divide); i++ {
		divide[i] = reverse(divide[i])
	}

	// 端から切っていく
	can := true
	for i := 0; i < len(S); {
		can2 := false // 4 個の文字列たちどれかで divide できるか
		for j := 0; j < len(divide); j++ {
			d := divide[j]
			if S[i:i+len(d)] == d { // d で divide できるか
				can2 = true
				i += len(d) // divide できたら i を進める
			}
		}
		if !can2 { // divide できなかったら
			can = false
			break
		}
	}

	if can {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

