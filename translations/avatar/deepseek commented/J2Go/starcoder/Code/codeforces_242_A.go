
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	in.Scan()
	x, _ := strconv.Atoi(in.Text())
	in.Scan()
	y, _ := strconv.Atoi(in.Text())
	in.Scan()
	a, _ := strconv.Atoi(in.Text())
	in.Scan()
	b, _ := strconv.Atoi(in.Text())

	count := 0
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue
			}
			count++
		}
	}

	fmt.Println(count)
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue
			}
			fmt.Println(i, j)
		}
	}
}

