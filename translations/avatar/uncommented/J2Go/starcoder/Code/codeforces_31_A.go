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
	a := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		a[i], _ = strconv.Atoi(sc.Text())
	}
	k, j, i := 0, 0, 0
	for k = 0; k < n; k++ {
		t := a[k]
		for i = 0; i < n; i++ {
			for j = 0; j < n-1; j++ {
				if i!= j && t == (a[i] + a[j]) {
					fmt.Println(k+1, j+1, i+1)
					return
				}
			}
		}
	}
	fmt.Println("-1")
}

