
<<<<<<< HEAD

import (
=======
package main

import (
	"bufio"
>>>>>>> 98c87cb78a (data updated)
	"fmt"
	"os"
	"strings"
)

func main() {
	var str, tmp, p string
	var slen, plen, i, j, flag int

	fmt.Scanf("%s %s", &str, &p)

	tmp = str
	str += tmp

	slen = len(str)
	plen = len(p)

	flag = 0
	for i = 0; i < slen-plen; i++ {
		if strings.Compare(str[i:i+plen], p) == 0 {
			flag = 1
		}
	}

<<<<<<< HEAD
	if flag == 1 {
=======
	if flag {
>>>>>>> 98c87cb78a (data updated)
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

