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

	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())

	m := make(map[int]int)

	for n > 0 {
		var num int
		sc.Scan()
		num, _ = strconv.Atoi(sc.Text())

		if _, ok := m[num];!ok {
			m[num] = 1
		} else {
			if m[num] == 1 {
				delete(m, num)
			} else {
				m[num]--
			}
			m[num]++
		}
		n--
	}

	ans := 0
	for _, v := range m {
		ans += v
	}
	fmt.Println(ans)
}

