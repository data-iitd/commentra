
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	s := sc.Text()
	n := len(s)
	mod_arr := make([]int, n)
	mod_cnt := make([]int, 2019)
	radix := 1
	for i := 0; i < n; i++ {
		tmp := (int(s[n-1-i]) - int('0')) * radix % 2019
		if i != 0 {
			tmp = (tmp + mod_arr[i-1]) % 2019
		}
		mod_arr[i] = tmp
		mod_cnt[tmp]++
		radix = radix*10 % 2019
	}
	ans := 0
	mod_cnt[0]++
	for i := 0; i < 2019; i++ {
		ans += int64(mod_cnt[i]) * int64(mod_cnt[i]-1) / 2
	}
	fmt.Println(ans)
}

