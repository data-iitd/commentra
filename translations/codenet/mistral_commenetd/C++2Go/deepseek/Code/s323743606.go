package main

import (
	"fmt"
	"math"
)

func main() {
	m := make(map[int]int)

	for i := 0; i*200 < 5001; i++ {
		for j := 0; j*300 < 5001; j++ {
			for k := 0; k*500 < 5001; k++ {
				w := i*200 + j*300 + k*500
				p := i/5*5*380*0.8 + float64(i%5)*380 +
					j/4*4*550*0.85 + float64(j%4)*550 +
					k/3*3*850*0.88 + float64(k%3)*850

				if val, ok := m[w]; ok {
					m[w] = int(math.Min(float64(val), p))
				} else {
					m[w] = int(p)
				}
			}
		}
	}

	for {
		var n int
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		fmt.Println(m[n])
	}
}

