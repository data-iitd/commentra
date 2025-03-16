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
	N, _ := strconv.Atoi(sc.Text())
	m := make(map[int]string)
	for i := 0; i < N; i++ {
		sc.Scan()
		m[i] = sc.Text()
	}
	ans := true
	past := make(map[int]string)
	next := ""
	for i := 0; i < N; i++ {
		if past[m[i]]!= "" {
			ans = false
			break
		}
		past[i] = m[i]
		if i!= 0 {
			if next!= m[i][0:1] {
				ans = false
				break
			}
		}
		next = m[i][len(m[i])-1:]
	}
	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

