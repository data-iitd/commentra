
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func aaa(n int) int {
	if n > N {
		return 0
	}

	ans := 1
	if strings.Join(strings.Split(strconv.Itoa(n), ""), "") == "753" {
		return ans
	}

	for _, i := range "753" {
		ans += aaa(n + int(i))
	}

	return ans
}

func main() {
	fmt.Println(aaa(0))
}

