
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
	reader := bufio.NewReader(os.Stdin)
	D, _ := strconv.Atoi(read(reader))
	G, _ := strconv.ParseInt(read(reader), 10, 64)
	p := make([]int, D)
	c := make([]int, D)
	for i := 0; i < D; i++ {
		p[i], _ = strconv.Atoi(read(reader))
		c[i], _ = strconv.Atoi(read(reader))
	}
	min := INF
	for bit := 0; bit < (1 << D); bit++ {
		score := 0
		solve_num := 0
		for i := 0; i < D; i++ {
			if (bit>>i)&1 == 1 {
				score += 100*(i+1)*p[i] + c[i]
				solve_num += p[i]
			}
		}
		if score < G {
			for i := D - 1; i >= 0; i-- {
				if (bit>>i)&1 == 0 {
					for j := 0; j < p[i]-1; j++ {
						score += 100 * (i + 1)
						solve_num++
						if score >= G {
							break
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

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(str)
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

