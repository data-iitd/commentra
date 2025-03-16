package main

import (
	"fmt"
	"strings"
)

func main() {
	var str, tmp, p string
	fmt.Scan(&str, &p)
	
	tmp = str
	str = str + tmp
	
	slen := len(str)
	plen := len(p)
	
	flag := false
	for i := 0; i <= slen - plen; i++ {
		if strings.HasPrefix(str[i:], p) {
			flag = true
			break
		}
	}
	
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

