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
	S := sc.Text()
	N := len(S)
	mod_arr := make([]int, N)
	mod_cnt := make([]int, 2019)
	radix := 1
	for i := 0; i < N; i++ {
		tmp := ((int(S[N-1-i]) - int('0')) * radix) % 2019
		if i!= 0 {
			tmp = (tmp + mod_arr[i-1]) % 2019
		}
		mod_arr[i] = tmp
		mod_cnt[tmp]++
		radix = (radix * 10) % 2019
	}
	ans := 0
	mod_cnt[0]++
	for i := 0; i < 2019; i++ {
		ans += mod_cnt[i] * (mod_cnt[i] - 1) / 2
	}
	fmt.Println(ans)
}

