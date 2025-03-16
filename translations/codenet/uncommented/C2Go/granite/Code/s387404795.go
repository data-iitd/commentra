
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var str, tmp, p string
	var slen, plen int
	var i, j int
	var flag bool

	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		str = scanner.Text()
	}
	if scanner.Scan() {
		p = scanner.Text()
	}

	tmp = str
	str = str + tmp

	slen = len(str)
	plen = len(p)

	flag = false
	for i = 0; i < slen-plen; i++ {
		if strings.HasPrefix(str[i:i+plen], p) {
			flag = true
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

