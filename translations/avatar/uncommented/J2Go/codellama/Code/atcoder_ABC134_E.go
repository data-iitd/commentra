package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	m := make(map[int]int)
	for i := 0; i < n; i++ {
		sc.Scan()
		num, _ := strconv.Atoi(sc.Text())
		if _, ok := m[num]; !ok {
			m[num] = 1
		} else {
			m[num]++
		}
	}
	ans := 0
	for _, v := range m {
		ans += v
	}
	fmt.Println(ans)
}

