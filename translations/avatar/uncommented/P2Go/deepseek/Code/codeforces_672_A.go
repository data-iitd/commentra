package main

import (
	"fmt"
)

func main() {
	li := []int{}
	for i := 1; i <= 370; i++ {
		temp := []int{}
		p, q := i, i
		count := 0
		for p != 0 {
			p /= 10
			count++
		}
		if count == 1 {
			li = append(li, i)
		}
		if count == 2 {
			temp = []int{}
			for q != 0 {
				x := q % 10
				q /= 10
				temp = append(temp, x)
			}
			for j := len(temp) - 1; j >= 0; j-- {
				li = append(li, temp[j])
			}
		}
		if count == 3 {
			temp = []int{}
			for q != 0 {
				x := q % 10
				q /= 10
				temp = append(temp, x)
			}
			for j := len(temp) - 1; j >= 0; j-- {
				li = append(li, temp[j])
			}
		}
	}
	li = li[:len(li)-2]
	n := 0
	fmt.Scan(&n)
	fmt.Println(li[n-1])
}

