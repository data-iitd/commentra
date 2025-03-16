
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initial int = 0
	const end int = 100001
	dp1 := make([]int, end)
	dp2 := make([]int, end)
	here := make([]int, end)
	for scanner.Scan() {
		text := scanner.Text()
		if text == "0 0" {
			break
		}
		parts := strings.Split(text, " ")
		n, _ := strconv.Atoi(parts[0])
		m, _ := strconv.Atoi(parts[1])
		for i := initial; i < end; i++ {
			here[i] = dp1[i] = dp2[i] = initial
		}
		dpflg := false
		for i := initial; i < m; i++ {
			a, _ := strconv.Atoi(parts[i+1])
			if a == 0 {
				dpflg = true
			}
			here[a] = 1
		}
		maxi1 := initial
		for i := initial; i < n; i++ {
			if here[i+1] == 1 {
				dp1[i+1] = dp1[i] + 1
			}
			if dp1[i+1] > maxi1 {
				maxi1 = dp1[i+1]
			}
		}
		maxi2 := initial
		for i := initial; i < n; i++ {
			if here[i+1] == 1 {
				dp2[i+1] = dp2[i] + 1
			} else {
				dp2[i+1] = dp1[i] + 1
			}
			if dp2[i+1] > maxi2 {
				maxi2 = dp2[i+1]
			}
		}
		if!dpflg {
			fmt.Println(maxi1)
		} else {
			fmt.Println(maxi2)
		}
	}
}

