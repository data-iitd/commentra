
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
	var count int
	var tmp int
	var str string
	for sc.Scan() {
		str = sc.Text()
		x, _ = strconv.Atoi(str)
		tmp = x
		x = 0
		for x != 360 {
			x = x + tmp
			if x > 360 {
				x = x - 360
			}
			count++
		}
		fmt.Println(count)
	}
}

