package main

import (
	"fmt"
)

func main() {
	for {
		var an [20]int
		var a1 [6]int
		var a2 [6]int
		var L, tmp, d, def, end, aj, max, min int
		var k, i, j int

		fmt.Scan(&an[0], &L)
		if L == 0 {
			break
		}

		aj = an[0]
		end = 0
		for k = 1; k < 21; k++ {
			for i = L - 1; i >= 0; i-- {
				a1[i] = aj % 10
				a2[i] = aj % 10
				aj /= 10
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
			for i = L - 1; i >= 0; i-- {
				max += (a1[i] % 10) * d
				min += (a2[i] % 10) * d
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

