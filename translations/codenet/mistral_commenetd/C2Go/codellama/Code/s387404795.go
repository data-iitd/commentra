
package main

import (
	"fmt"
	"strings"
)

func main() {
	var str, p string
	fmt.Scan(&str, &p)

	tmp := str
	str += tmp

	slen := len(str)
	plen := len(p)

	flag := 0
	for i := 0; i < slen-plen; i++ {
		if strings.HasPrefix(str[i:i+plen], p) {
			flag = 1
		}
	}

	if flag == 1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

