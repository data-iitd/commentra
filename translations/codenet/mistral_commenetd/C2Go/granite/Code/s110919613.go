
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var an [20]int
	var L, aj, end, i, j, k, d, def, max, min, tmp int
	for scanner.Scan() {
		aj, _ = strconv.Atoi(scanner.Text())
		if L, _ = strconv.Atoi(scanner.Text()); L == 0 {
			break
		}
		aj = an[0]
		end = 0
		for k = 1; k < 20; k++ {
			ajStr := strconv.Itoa(aj)
			L = len(ajStr)
			a1 := make([]int, L)
			a2 := make([]int, L)
			for i = L - 1, j = 0; i >= 0; i, j = i-1, j+1 {
				a1[i], _ = strconv.Atoi(string(ajStr[i]))
				a2[i] = a1[i]
			}
			for i = 1; i < L; i++ {
				for j = 1; j < L; j++ {
					if a1[j-1] < a1[j] {
						tmp = a1[j-1]
						a1[j-1] = a1[j]
						a1[j] = tmp
					}
					if a2[j-1] > a2[j] {
						tmp = a2[j-1]
						a2[j-1] = a2[j]
						a2[j] = tmp
					}
				}
			}
			d = 1
			max = 0
			min = 0
			for i = L - 1, j = 0; i >= 0; i, j = i-1, j+1 {
				max += a1[i] * d
				min += a2[i] * d
				d *= 10
			}
			def = max - min
			for i = 0; i < k; i++ {
				if def == an[i] {
					fmt.Printf("%d %d %d\n", i, def, k-i)
					end = 1
					break
				}
			}
			if end == 1 {
				break
			}
			an[k] = def
			aj = def
		}
	}
}

