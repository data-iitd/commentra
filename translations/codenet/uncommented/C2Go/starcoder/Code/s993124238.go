package main

import (
	"fmt"
	"math"
)

func main() {
	var n, d int
	fmt.Scanf("%d%d", &n, &d)
	point := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		point[i] = make([]int, d+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= d; j++ {
			fmt.Scanf("%d", &point[i][j])
		}
	}
	count := 0
	for i := 1; i <= n-1; i++ {
		for j := i + 1; j <= n; j++ {
			sum := 0
			for k := 1; k <= d; k++ {
				sum += (point[i][k] - point[j][k]) * (point[i][k] - point[j][k])
			}
			kyori := math.Sqrt(float64(sum))
			if math.Ceil(kyori) == math.Floor(kyori) {
				count++
			}
		}
	}
	fmt.Printf("%d\n", count)
}

