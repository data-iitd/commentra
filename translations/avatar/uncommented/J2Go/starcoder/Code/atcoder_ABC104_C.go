package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var D, G int
	var p, c []int
	var min int = 100000
	var score, solve_num int
	var bit int
	var i, j int
	var loop bool

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &D, &G)
	p = make([]int, D)
	c = make([]int, D)
	for i = 0; i < D; i++ {
		fmt.Fscan(reader, &p[i], &c[i])
	}
	for bit = 0; bit < (1 << D); bit++ {
		score = 0
		solve_num = 0
		for i = 0; i < D; i++ {
			if bit&(1<<i)!= 0 {
				score += 100*(i+1)*p[i] + c[i]
				solve_num += p[i]
			}
		}
		if score < G {
			loop = false
			for i = D - 1; i >= 0; i-- {
				if bit&(1<<i) == 0 {
					for j = 0; j < p[i]-1; j++ {
						score += 100*(i+1)
						solve_num++
						if score >= G {
							loop = true
							break
						}
					}
				}
				if loop {
					break
				}
			}
		}
		if score >= G {
			min = min(min, solve_num)
		}
	}
	fmt.Println(min)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

