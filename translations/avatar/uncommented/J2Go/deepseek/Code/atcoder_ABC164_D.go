package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	S := input[:len(input)-1] // Remove the newline character
	N := len(S)
	modArr := make([]int, N)
	modCnt := make([]int, 2019)
	radix := 1
	for i := 0; i < N; i++ {
		tmp := (int(S[N-1-i]-'0') * radix) % 2019
		if i != 0 {
			tmp = (tmp + modArr[i-1]) % 2019
		}
		modArr[i] = tmp
		modCnt[tmp]++
		radix = radix * 10 % 2019
	}
	ans := 0
	modCnt[0]++
	for i := 0; i < 2019; i++ {
		ans += modCnt[i] * (modCnt[i] - 1) / 2
	}
	fmt.Println(ans)
}
