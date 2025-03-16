
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var q int
	fmt.Scan(&q)
	ans := make([]int, 2)
	p1 := make([]int, 0)
	p2 := make([]int, 0)
	sum_b := 0
	sum_p1 := 0
	sum_p2 := 0
	for i := 0; i < q; i++ {
		ql := make([]int, 3)
		for j := 0; j < 3; j++ {
			fmt.Scan(&ql[j])
		}
		if ql[0] == 2 {
			if len(p1) == len(p2) {
				fmt.Println(-p2[0], sum_p1-len(p1)*-p2[0]+len(p2)*-p2[0]-sum_p2+sum_b)
			} else {
				fmt.Println(p1[0], sum_p1-len(p1)*p1[0]+len(p2)*p1[0]-sum_p2+sum_b)
			}
		} else {
			sum_b += ql[2]
			if len(p1) == 0 {
				p1 = append(p1, ql[1])
				sum_p1 += ql[1]
			} else if p1[0] <= ql[1] {
				p1 = append(p1, ql[1])
				sum_p1 += ql[1]
			} else {
				p2 = append(p2, -ql[1])
				sum_p2 += ql[1]
			}
			if len(p1) < len(p2) {
				k := p2[0]
				p2 = p2[1:]
				p1 = append(p1, -k)
				sum_p2 += k
				sum_p1 -= k
			}
			if len(p1) > len(p2)+1 {
				k := p1[0]
				p1 = p1[1:]
				p2 = append(p2, -k)
				sum_p1 -= k
				sum_p2 += k
			}
		}
	}
}

