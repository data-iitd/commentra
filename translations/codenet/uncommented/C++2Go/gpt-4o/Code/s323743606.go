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
				p := (i/5)*5*380*int(0.8) + (i%5)*380 +
					(j/4)*4*550*int(0.85) + (j%4)*550 +
					(k/3)*3*850*int(0.88) + (k%3)*850

				if existing, ok := m[w]; ok {
					m[w] = int(math.Min(float64(existing), float64(p)))
				} else {
					m[w] = p
				}
			}
		}
	}

	var n int
	for {
		if _, err := fmt.Scan(&n); err != nil || n == 0 {
			break
		}
		fmt.Println(m[n])
	}
}

// <END-OF-CODE>
