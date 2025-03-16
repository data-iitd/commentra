package main

import (
	"fmt"
	"strings"
)

func main() {
	str := make([]byte, 201)
	tmp := make([]byte, 101)
	p := make([]byte, 101)
	slen := 0
	plen := 0
	i := 0
	j := 0
	flag := 0

	fmt.Scanf("%s %s", &str, &p)

	copy(tmp, str)
	str = append(str, tmp...)

	slen = len(str)
	plen = len(p)

	for i = 0; i < slen-plen; i++ {
		if strings.Compare(string(str[i:i+plen]), string(p)) == 0 {
			flag = 1
			break
		}
	}

	if flag == 1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

