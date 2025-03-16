package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	S := strings.TrimSpace(input)
	N := len(S)

	modArr := make([]int, N)
	modCnt := make([]int, 2019)
	radix := 1

	for i := 0; i < N; i++ {
		tmp := 0
		tmp = (int(S[N-1-i]) - int('0')) * radix % 2019
		if i != 0 {
			tmp = (tmp + modArr[i-1]) % 2019
		}
		modArr[i] = tmp
		modCnt[tmp]++
		radix = radix * 10 % 2019
	}

	var ans int64 = 0

	for i := 0; i < 2019; i++ {
		ans += int64(modCnt[i]) * int64(modCnt[i] - 1) / 2
	}

	fmt.Println(ans)
}

