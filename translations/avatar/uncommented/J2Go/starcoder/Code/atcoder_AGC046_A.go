package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var x int
	sc.Scan()
	x, _ = strconv.Atoi(sc.Text())
	count := 0
	tmp := x
	x = 0
	for x!= 360 {
		x = x + tmp
		if x > 360 {
			x = x - 360
		}
		count++
	}
	fmt.Println(count)
}

