package main

import (
	"fmt"
	"strings"
)

func main() {
	var str, tmp, p string
	var slen, plen int
	var i, flag int

	fmt.Scan(&str, &p)

	tmp = str
	str = str + tmp

	slen = len(str)
	plen = len(p)

	flag = 0
	for i = 0; i < slen - plen; i++ {
		if strings.Compare(str[i:i+plen], p) == 0 {
			flag = 1
		}
	}

	if flag == 1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

