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
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	k, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	a := sc.Text()
	if k > n/2 {
		for i := 0; i < n; i++ {
			fmt.Println("RIGHT")
		}
	} else {
		for i := 0; i < k; i++ {
			fmt.Println("LEFT")
		}
	}
	if k == 1 {
		for i := 0; i < len(a); i++ {
			fmt.Println("PRINT", a[i])
			if i+1 < len(a) {
				fmt.Println("RIGHT")
			}
		}
	} else {
		for i := len(a) - 1; i >= 0; i-- {
			fmt.Println("PRINT", a[i])
			if i-1 >= 0 {
				fmt.Println("LEFT")
			}
		}
	}
}

