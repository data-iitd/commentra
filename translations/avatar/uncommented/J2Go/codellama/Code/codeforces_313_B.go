
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	cum := make([]int, len(s)+1)
	cum[0] = cum[len(s)] = 0
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}
	var q int
	fmt.Scan(&q)
	for q > 0 {
		q--
		var l, r int
		fmt.Scan(&l, &r)
		fmt.Println(cum[r-1] - cum[l-2])
	}
}

