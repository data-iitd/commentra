
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		maxsize int
		maxcnt  int
		ans_num int
		ans_num2 int
		str_v   []string
	)
	for {
		var in string
		if _, err := fmt.Scanf("%s", &in); err!= nil {
			break
		}
		str_v = append(str_v, in)
		if maxsize < len(in) {
			maxsize = len(in)
			ans_num = len(str_v) - 1
		}
	}
	for i := 0; i < len(str_v); i++ {
		cnt := 0
		for j := 0; j < len(str_v); j++ {
			if str_v[i] == str_v[j] {
				cnt++
			}
		}
		if maxcnt < cnt {
			maxcnt = cnt
			ans_num2 = i
		}
	}
	fmt.Printf("%s %s\n", str_v[ans_num2], str_v[ans_num])
}

