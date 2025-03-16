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
	n := parseInt(scanner.Text())
	scanner.Scan()
	m := parseInt(scanner.Text())

	q1 := []int{}
	q2 := []int{}

	for i := 1; i <= n; i++ {
		scanner.Scan()
		val := parseInt(scanner.Text())
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
			q2 = q2[1:]
			q2 = append(q2, q2[0])
		}
	}

	fmt.Println(ans)
}

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

