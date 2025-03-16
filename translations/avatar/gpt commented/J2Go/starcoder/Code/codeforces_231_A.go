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
	sc.Scan()
	t, _ := strconv.Atoi(sc.Text())
	count := 0
	for t > 0 {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		c, _ := strconv.Atoi(sc.Text())
		if a == 1 || b == 1 || c == 1 || a == 1 && b == 1 && c == 1 {
			count++
		}
		t--
	}
	fmt.Println(count)
}

