
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	m, _ := strconv.Atoi(reader.ReadLine()[2:])
	q1 := make([]int, n)
	q2 := make([]int, n)
	for i := 0; i < n; i++ {
		q1[i], _ = strconv.Atoi(reader.ReadLine()[2:])
		q2[i] = i + 1
	}
	ans := 0
	for len(q1) > 0 {
		if q1[0] <= m {
			ans = q2[0]
			q1 = q1[1:]
			q2 = q2[1:]
		} else {
			x := q1[0]
			val := x - m
			q1[0] = val
			q1 = append(q1[1:], val)
			val2 := q2[0]
			q2[0] = val2
			q2 = append(q2[1:], val2)
		}
	}
	fmt.Println(ans)
}

