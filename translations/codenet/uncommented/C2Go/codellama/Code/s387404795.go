package main

import (
	"fmt"
	"strings"
)

func main() {
	var str, p string
	var tmp string
	var slen, plen int
	var i, j int
	var flag bool

	fmt.Scan(&str, &p)

	tmp = str
	str += tmp

	slen = len(str)
	plen = len(p)

	flag = false
	for i = 0; i < slen-plen; i++ {
		if strings.HasPrefix(str[i:], p) {
			flag = true
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

