
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the threshold value")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	q1 := make([]int, n)
	q2 := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Println("Enter the element")
		q1[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		q2[i] = i + 1
	}
	ans := 0
	for len(q1) > 0 {
		if q1[0] <= m {
			q1 = q1[1:]
			ans = q2[0]
			q2 = q2[1:]
		} else if q1[0] > m {
			x := q1[0]
			q1 = q1[1:]
			val := x - m
			q1 = append(q1, val)
			val2 := q2[0]
			q2 = q2[1:]
			q2 = append(q2, val2)
		}
	}
	fmt.Println(ans)
}

