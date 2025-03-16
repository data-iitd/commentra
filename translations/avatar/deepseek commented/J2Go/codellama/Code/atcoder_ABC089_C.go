
package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	cnt := make([]int, 5)
	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str)
		if str[0] == 'M' {
			cnt[0]++
		} else if str[0] == 'A' {
			cnt[1]++
		} else if str[0] == 'R' {
			cnt[2]++
		} else if str[0] == 'C' {
			cnt[3]++
		} else if str[0] == 'H' {
			cnt[4]++
		}
	}
	res := cnt[0]*cnt[1]*cnt[2] + cnt[0]*cnt[1]*cnt[3] + cnt[0]*cnt[1]*cnt[4] + cnt[0]*cnt[2]*cnt[3] + cnt[0]*cnt[2]*cnt[4] + cnt[0]*cnt[3]*cnt[4] + cnt[1]*cnt[2]*cnt[3] + cnt[1]*cnt[2]*cnt[4] + cnt[1]*cnt[3]*cnt[4] + cnt[2]*cnt[3]*cnt[4]
	fmt.Println(res)
}

// 