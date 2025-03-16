package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, k int
	fmt.Scanf("%d%d", &n, &k)
	cnt := 0
	for n > 0 {
		var h int
		fmt.Scanf("%d", &h)
		if h >= k {
			cnt++
		}
		n--
	}
	fmt.Printf("%d\n", cnt)
}

