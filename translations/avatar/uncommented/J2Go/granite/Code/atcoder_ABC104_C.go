
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	INF = 100000
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var D int
	var G int
	sc.Scan()
	D, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	G, _ = strconv.Atoi(sc.Text())
	p := make([]int, D)
	c := make([]int, D)
	for i := 0; i < D; i++ {
		sc.Scan()
		p[i], _ = strconv.Atoi(sc.Text())
		sc.Scan()
		c[i], _ = strconv.Atoi(sc.Text())
	}
	min := INF
	for bit := 0; bit < (1 << D); bit++ {
		score := 0
		solve_num := 0
		for i := 0; i < D; i++ {
			if (bit>>(i))&1 == 1 {
				score += 100*(i+1)*p[i] + c[i]
				solve_num += p[i]
			}
		}
		if score < G {
			loop:
				for i := D - 1; i >= 0; i-- {
					if (bit>>(i))&1 == 0 {
						for j := 0; j < p[i]-1; j++ {
							score += 100 * (i + 1)
							solve_num++
							if score >= G {
								break loop
							}
						}
					}
				}
		}
		if score >= G {
			min = minInt(min, solve_num)
		}
	}
	fmt.Println(min)
}

func minInt(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

