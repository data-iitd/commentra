
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const MOD = 10007
	const NIL = -1
	const MAX = 100000000
	var a, b, n, x, y int
	var fie [17][17]int
	for scanner.Scan() {
		text := scanner.Text()
		if text == "0 0" {
			break
		}
		fields := strings.Split(text, " ")
		a, _ = strconv.Atoi(fields[0])
		b, _ = strconv.Atoi(fields[1])
		for i := 0; i < a; i++ {
			for j := 0; j < b; j++ {
				fie[i][j] = NIL
			}
		}
		for i := 0; i < n; i++ {
			scanner.Scan()
			text := scanner.Text()
			fields := strings.Split(text, " ")
			x, _ = strconv.Atoi(fields[0])
			y, _ = strconv.Atoi(fields[1])
			fie[x-1][y-1] = 0
		}
		for i := 0; i < a; i++ {
			for j := 0; j < b; j++ {
				if fie[i][j] == NIL {
					if i == 0 && j == 0 {
						fie[i][j] = 1
					} else if i == 0 {
						fie[i][j] = fie[i][j-1]
					} else if j == 0 {
						fie[i][j] = fie[i-1][j]
					} else {
						fie[i][j] = (fie[i][j-1] + fie[i-1][j]) % MOD
					}
				}
			}
		}
		fmt.Println(fie[a-1][b-1])
	}
}
