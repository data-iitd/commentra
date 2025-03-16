package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')
	S = reverse(S)

	divide := []string{"dream", "dreamer", "erase", "eraser"}
	for i := 0; i < 4; i++ {
		divide[i] = reverse(divide[i])
	}

	can := true
	for i := 0; i < len(S); {
		can2 := false
		for _, d := range divide {
			if strings.HasPrefix(S[i:], d) {
				can2 = true
				i += len(d)
			}
		}
		if !can2 {
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

