
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	n := len(s)
	modArr := make([]int, n)
	modCnt := make([]int, 2019)
	radix := 1
	for i := 0; i < n; i++ {
		tmp := (int(s[n-1-i]) - int('0')) * radix % 2019
		if i!= 0 {
			tmp = (tmp + modArr[i-1]) % 2019
		}
		modArr[i] = tmp
		modCnt[tmp]++
		radix = radix * 10 % 2019
	}
	ans := int64(0)
	modCnt[0]++
	for i := 0; i < 2019; i++ {
		ans += int64(modCnt[i]) * (int64(modCnt[i]) - 1) / 2
	}
	fmt.Println(ans)
}

