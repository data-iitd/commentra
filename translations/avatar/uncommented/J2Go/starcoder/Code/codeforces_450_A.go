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
	m, _ := strconv.Atoi(sc.Text())
	q1 := make([]int, n)
	q2 := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		q1[i], _ = strconv.Atoi(sc.Text())
		q2[i] = i + 1
	}
	ans := 0
	for!isEmpty(q1) {
		if q1[0] <= m {
			q1 = q1[1:]
			ans = q2[0]
			q2 = q2[1:]
		} else if q1[0] > m {
			x := q1[0]
			q1 = append(q1, x-m)
			val := q2[0]
			q2 = append(q2, val)
		}
	}
	fmt.Println(ans)
}

func isEmpty(q1 []int) bool {
	return len(q1) == 0
}

