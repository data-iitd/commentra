package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := toInt(scanner.Text())
	scanner.Scan()
	m := toInt(scanner.Text())

	q1 := []int{}
	q2 := []int{}

	for i := 1; i <= n; i++ {
		scanner.Scan()
		val := toInt(scanner.Text())
		q1 = append(q1, val)
		q2 = append(q2, i)
	}

	ans := 0

	for len(q1) > 0 {
		if q1[0] <= m {
			ans = q2[0]
			q1 = q1[1:]
			q2 = q2[1:]
		} else {
			val := q1[0] - m
			q1 = q1[1:]
			q1 = append(q1, val)
			val2 := q2[0]
			q2 = q2[1:]
			q2 = append(q2, val2)
		}
	}

	fmt.Println(ans)
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

