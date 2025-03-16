package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var pandu, vundu, urdu, c int64
	var s string
	sc := bufio.NewScanner(os.Stdin)
	s = sc.Text()
	pandu, _ = strconv.ParseInt(s, 10, 64)
	s = sc.Text()
	vundu, _ = strconv.ParseInt(s, 10, 64)
	s = sc.Text()
	urdu, _ = strconv.ParseInt(s, 10, 64)
	for i := int64(1); i <= urdu; i++ {
		c += i * pandu
	}
	if c < vundu {
		fmt.Println("0")
	} else {
		fmt.Println(c - vundu)
	}
}

