
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)
	scan.Scan()
	t, _ := strconv.Atoi(scan.Text())
	for i := 0; i < t; i++ {
		scan.Scan()
		n, _ := strconv.Atoi(scan.Text())
		fmt.Println(maxLeft(n))
	}
}

func maxLeft(n int) int {
	if n > 2 {
		return n - 2
	}
	return 0
}

